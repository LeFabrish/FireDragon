#include "BolaDeFuego.h"


BolaDeFuego::BolaDeFuego(int dragonDx, int dragonDy, int x, int y) : Sprite(x, y) {
	this->velocidad = 80;
	this->dx = dragonDx;
	this->dy = dragonDy;
}
BolaDeFuego::~BolaDeFuego() {
}



void BolaDeFuego::mover(Direccion tecla, int anchoPanel, int altoPanel) {
	if (!activo) return;
	if (dx == 0 && dy == 1) { indiceY = 3; }  // abajo
	if (dx == 0 && dy == -1) { indiceY = 2; }			  // arriba
	if (dx == 1 && dy == 0) { indiceY = 1; }			  // derecha
	if (dx == -1 && dy == 0) { indiceY = 0; }			  // izquieda

	x += dx * velocidad;
	y += dy * velocidad;
	indiceX++;
	if (indiceX >= columnas) {
		indiceX = 0;
	}

	if (x < 0 || x > anchoPanel - ancho * 1||
		y < 0||y > altoPanel - alto * 1) {
		activo = false;
	}
}
void BolaDeFuego::dibujar(Graphics^ canvas) {
	if (activo || ancho == 0 || alto == 0) return;// Evitar division por cero

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
Rectangle BolaDeFuego::getRectangle() {
	return Rectangle(x, y, ancho * 1, alto * 1);
}