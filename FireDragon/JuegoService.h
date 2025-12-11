#pragma once
#include "Dragon.h"
#include "Ovni.h"
#include "BolaDeFuego.h"
#include "GestorArchivo.h"
#include "FondoDinamico.h"


#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace System::Drawing;
using namespace std;

class JuegoService
{
private:
	Dragon* dragon;
	vector<BolaDeFuego*> bolasF;
	vector<Ovni*> ovnis;
	 int anchoPanel, altoPanel;
	 GestorArchivo* gestorArchivo;
	 FondoDinamico * fondoDinamico;
	 bool juegoterminado, victoria;
	 int tiempoOvni;
	 bool OvniAparecido;
	 // Puntos
	 int ovnisDestruidos = 0;
	 int puntos = 0;
	 int vidasRestantes = 5;
	 string nombreJugador = "Jugador1";

	 // dificultad
	 int dificultad; // 1: facil, 2: medio, 3: dificil, 4: infinito
	 bool yaGuardo;

public:

	JuegoService(int ancho, int alto, string nombreJugador, int dificultad);
	~JuegoService();
	void  inicializar();
	void  generarBolas();
	void  generarOvnis();
	void  moverDragon(Direccion tecla);
	void moverOvnis();
	void moverBolas();
	void  verificarColisionBolaOnvi();
	void verificarColisionDragonOvni();
	void  verificarMapaBola();
	void  actualizarEstadoJuego();
	void actualizarOvni();
	void dibujarTodo(Graphics^ canvas);
	void  guardarResultado();
	System::String^ leerResultado();
	bool JuegoTerminado();
	bool  gano();
	Dragon* getDragon();
	//^Puntaje
	int getPuntos();
	int getOvnisDestruidos();
	int getVidasRestantes();

};

