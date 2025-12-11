#include "JuegoService.h"

JuegoService::JuegoService(int ancho, int alto, string nombreJugador, int dificultad) {
	this->anchoPanel = ancho;
	this->altoPanel = alto;
	dragon = new Dragon(10, alto / 2);
	gestorArchivo = new GestorArchivo();
	fondoDinamico = new FondoDinamico("Fondo_nubes.png", anchoPanel, altoPanel);
	this->nombreJugador = nombreJugador;
	juegoterminado = false;
	victoria = false;
	tiempoOvni = 0;
	OvniAparecido = false;
	this->dificultad = dificultad;// 1: facil, 2: medio, 3: dificil, 4: infinito
	yaGuardo = false;
	srand(time_t(NULL));
}
JuegoService::~JuegoService() {
	if (!yaGuardo)
		guardarResultado();
	if (dragon) delete dragon;
	if (gestorArchivo) delete gestorArchivo;
	for (Ovni* o : ovnis)
		delete o;
	ovnis.clear();
	for (BolaDeFuego* b : bolasF)
		delete b;
	bolasF.clear();
	if (fondoDinamico) delete fondoDinamico;

}
void  JuegoService::inicializar() {
	char* rutaDinamica = "Fondo_nubes.png";
	fondoDinamico->cargarImagen(rutaDinamica, anchoPanel, altoPanel);
	char* rutaDragon = "DragonFuego.png";
	dragon->cargarImagen(rutaDragon, 4, 4);

}
void  JuegoService::generarBolas() {
	if (juegoterminado) return;
	if (!dragon->disparando()) {
		dragon->disparar_bola();
		// Que la posicion sea en el medio del dragon
		int bolaX = dragon->getX() + dragon->getAncho() / 4;
		int bolaY = dragon->getY() + dragon->getAlto() / 4;
		BolaDeFuego* bola = new BolaDeFuego(dragon->getDx(), dragon->getDy(), bolaX, bolaY);

		bola->cargarImagen("Bola_de_fuego.png", 4, 4);
		bolasF.push_back(bola);
	}
}
void  JuegoService::generarOvnis() {
	if (juegoterminado || OvniAparecido) return;
	switch (dificultad) {
	case 1: // facil
		tiempoOvni = rand()%10 + 25;
		break;
	case 2: // medio
		tiempoOvni = rand()%10 + 15;
		break;
	case 3: // dificil
		tiempoOvni = rand()%10 + 5;
		break;
	case 4: // infinito
		tiempoOvni = rand()%9 + 1;
		break;
	}
	OvniAparecido = true;
	int x = anchoPanel;
	int y = rand() % (altoPanel - 120);
	Ovni* ovni = new Ovni(x, y);
	ovni->cargarImagen("Ovni.png", 1, 4);
	ovnis.push_back(ovni);
}
void  JuegoService::moverDragon(Direccion tecla) {
	dragon->mover(tecla, anchoPanel, altoPanel);
}

void JuegoService::moverOvnis() {
	for (int i = 0; i < ovnis.size(); i++) {
		Ovni* o = ovnis[i];
		if (o->isActivo()) {
			o->mover(Direccion::Ninguno, anchoPanel, altoPanel);
		}
		else {
			delete o;
			ovnis.erase(ovnis.begin() + i);
			i--;
		}
	}
}
void JuegoService::moverBolas() {
	for (int i = 0; i < bolasF.size(); i++) {
		BolaDeFuego* b = bolasF[i];
		if (b->isActivo()) {
			b->mover(Direccion::Ninguno, anchoPanel, altoPanel);
		}
		else {
			delete b;
			bolasF.erase(bolasF.begin() + i);
			i--;
		}
	}
}
void  JuegoService::verificarColisionBolaOnvi() {
	for (int i = 0; i < bolasF.size(); i++) {
		BolaDeFuego* b = bolasF[i];
		Rectangle rectBola = b->getRectangle();
		for (int j = 0; j < ovnis.size(); j++) {
			Ovni* o = ovnis[j];
			Rectangle rectOvni = o->getRectangle();
			if (rectBola.IntersectsWith(rectOvni)) {
				// Colision detectada
				b->setActivo(false);
				o->setActivo(false);
				ovnisDestruidos++;
				puntos += 10;
			}
		}
	}
}
void JuegoService::verificarColisionDragonOvni() {
	Rectangle rectDragon = dragon->getRectangle();
	for (int i = 0; i < ovnis.size(); i++) {
		Ovni* o = ovnis[i];
		Rectangle rectOvni = o->getRectangle();
		if (rectDragon.IntersectsWith(rectOvni)) {
			// Colision detectada
			o->setActivo(false);
			dragon->perderVida();
			dragon->resetearPosicion(anchoPanel, altoPanel);
			puntos -= 5;
			if (!dragon->estaVivo()) {
				dragon->setActivo(false);
			}
		}
	}
}
void  JuegoService::verificarMapaBola() {
	for (int i = 0; i < bolasF.size(); i++) {
		BolaDeFuego* b = bolasF[i];
		Rectangle rectBola = b->getRectangle();
		// Verificar colision con los bordes del mapa
		if (rectBola.X < 0 || rectBola.X > anchoPanel ||
			rectBola.Y < 0 || rectBola.Y > altoPanel) {
			b->setActivo(false);
		}
	}
}
void  JuegoService::actualizarEstadoJuego() {
	if (juegoterminado) return;
	fondoDinamico->mover();
	moverBolas();
	moverOvnis();

	actualizarOvni();
	verificarColisionBolaOnvi();
	verificarColisionDragonOvni();
	verificarMapaBola();
	// eliminar ovnis y bolas inactivas, y actualizar estado de juego
	if (!dragon->estaVivo()) {
		juegoterminado = true;
		victoria = false;
	}
	// condicion de victoria: segund dificultad infinito, no tiempo limite
	if (dificultad == 4) return;
	if (dificultad == 3 && ovnisDestruidos >= 30
		|| dificultad == 2 && ovnisDestruidos >= 20
		|| dificultad == 1 && ovnisDestruidos >= 10) {
		victoria = true;
		juegoterminado = true;
	}
}
void JuegoService::actualizarOvni() {
	// Actualizar tiempo de ovni mientras este aparecido
	if (tiempoOvni > 0 && OvniAparecido) {
		tiempoOvni--;
		if (tiempoOvni <= 0) {
			tiempoOvni = 0;
			OvniAparecido = false;
		}
	}
}


void JuegoService::guardarResultado() {
	vector<vector<string>> lineas;
	string nombreArchivo = "progresoDragonFire.txt";

	if (gestorArchivo->archivoExiste(nombreArchivo)) {
		// IMPORTANTE: Usamos ';' como delimitador consistente
		lineas = gestorArchivo->leerLineasString(nombreArchivo, ';');
	}

	// Agregar nueva linea con el resultado actual
	vector<string> nuevaLinea;
	nuevaLinea.push_back(nombreJugador);
	nuevaLinea.push_back(to_string(puntos));
	nuevaLinea.push_back(to_string(ovnisDestruidos));
	// Si cierran el juego antes de morir, guardamos las vidas que tenian
	nuevaLinea.push_back(to_string(dragon->getVidas()));

	if (gano())
		nuevaLinea.push_back("Gano");
	else if (dragon->getVidas() <= 0)
		nuevaLinea.push_back("Perdio");
	else
		nuevaLinea.push_back("Abandono"); // Caso donde cierran la ventana

	lineas.push_back(nuevaLinea);

	// Guardar todas las lineas nuevamente
	gestorArchivo->guardarLineas(nombreArchivo, lineas, ';');
}
System::String^ JuegoService::leerResultado() {
	if (!gestorArchivo->archivoExiste("progresoDragonFire.txt")) {
		return gcnew System::String("No hay resultados guardados.");
	}
	vector<vector<string>> lineas = gestorArchivo->leerLineasString("progresoDragonFire.txt", ';');
	System::String^ resultado = gcnew System::String("Resultados del Juego:\n");
	for (const auto& linea : lineas) {
		for (const auto& valor : linea) {
			resultado += gcnew System::String(valor.c_str()) + " ";
		}
		resultado += "\n";
	}
	return resultado;
}


void JuegoService::dibujarTodo(Graphics^ canvas) {
	fondoDinamico->dibujar(canvas, anchoPanel, altoPanel);
	for (Ovni* o : ovnis) {
		if (o->isActivo()) {
			o->dibujar(canvas);
		}
	}
	for (BolaDeFuego* b : bolasF) {
		if (b->isActivo()) {
			b->dibujar(canvas);
		}
	}

	if (dragon->isActivo()) dragon->dibujar(canvas);
}

bool JuegoService::JuegoTerminado() { return juegoterminado; }
bool  JuegoService::gano() { return victoria; }
Dragon* JuegoService::getDragon() {
	return dragon;
}
//^Puntaje
int JuegoService::getPuntos() {
	return puntos;
}
int JuegoService::getOvnisDestruidos() {
	return ovnisDestruidos;
}
int JuegoService::getVidasRestantes() {
	return dragon->getVidas();
}