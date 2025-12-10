#include "Dragon.h"

Dragon::Dragon(int x, int y): Sprite(x,y),
 vidas(5), tiempoDisparo(0), disparo(false){
	this->velocidad = 25;
}
Dragon::~Dragon(){}

void Dragon::perderVida() {
	if (vidas <= 0) return;
	vidas--;
}
bool Dragon::estaVivo() { return vidas > 0; }
void Dragon::resetearPosicion(int limiteAncho, int limiteAlto){
	x = (limiteAncho / 8);
	y = limiteAlto / 2;
}
void Dragon::disparar_bola() {
	tiempoDisparo = 3;
	disparo = true;
}

bool Dragon::disparando(){
	if (tiempoDisparo > 0 && disparo) {
		tiempoDisparo--;
		if (tiempoDisparo <= 0) {
			tiempoDisparo = 0;
			disparo = false;
		}
	}
	return disparo;
}
void Dragon::mover(Direccion tecla, int anchoPanel, int altoPanel) {
	if (!activo) return;

	indiceX++;
	if (indiceX >= 4) {
		indiceX = 0;
	}
	if (tecla == Direccion::Ninguno) {  return; }
	if (tecla == Direccion::Arriba) { dx = 0; dy = -1; indiceY = 3; }
	if (tecla == Direccion::Izquierda) { dx = -1; dy = 0; indiceY = 1; }
	if (tecla == Direccion::Derecha) { dx = 1; dy = 0; indiceY = 2; }
	if (tecla == Direccion::Abajo) { dx = 0; dy = 1; indiceY = 0; }



	x += dx * velocidad;
	y += dy * velocidad;
	if (x < 0) { x = 0; }
	if (x > anchoPanel - ancho*1) { x = anchoPanel - ancho*1; }
	if (y < 0) { y = 0; }
	if (y > altoPanel - alto*1) { y = altoPanel - alto*1; }
}
void Dragon::dibujar(Graphics^ canvas) {
	if (!activo || ancho == 0 || alto == 0) return;// Evitar division por cero

	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
	Rectangle cuadroOrigen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle cuadroDestino = Rectangle(x, y, ancho * 1, alto * 1);

	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;

	// Hitbox
	Pen^ pen = gcnew Pen(Color::Red);
	Rectangle hitbox = getRectangle();
	canvas->DrawRectangle(pen, hitbox);
	delete pen;
}
Rectangle Dragon::getRectangle() {
	return Rectangle(x + ancho / 4, y + alto / 4, ancho / 2, alto / 2);
}


int Dragon::getDx(){
	return dx;
}
int Dragon::getDy(){
	return dy;
}
int Dragon::getVidas(){
	return vidas;
}
int Dragon::getAncho(){
	return ancho;
}
int Dragon::getAlto(){
	return alto;
}
