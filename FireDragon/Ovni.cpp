#include "Ovni.h"

Ovni::Ovni(int x, int y) : Sprite(x,y){
	this->velocidad = 30;
	this->dx = -1;
	this->dy = 0;
}
Ovni::~Ovni() {}

void Ovni::mover(Direccion tecla, int anchoPanel, int altoPanel) {
	if (!activo) return;

	x += dx * velocidad;
	indiceX++;
	if (indiceX >= 4) {
		indiceX = 0;
	}

	if (x < 0) activo = false;
}
void Ovni::dibujar(Graphics^ canvas) {

	if (!activo || ancho == 0 || alto == 0) return;// Evitar division por cero

	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
	Rectangle cuadroOrigen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle cuadroDestino = Rectangle(x, y, ancho * 0.4, alto * 0.4);

	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;

	//// Hitbox
	//Pen^ pen = gcnew Pen(Color::Red);
	//Rectangle hitbox = getRectangle();
	//canvas->DrawRectangle(pen, hitbox);
	//delete pen;
}
Rectangle Ovni::getRectangle() {
	// Ajustar el rectángulo para que sea un poco más pequeño que la imagen

	// que se multiplica por 0.4
	return Rectangle(x + ancho * 0.1, y + alto * 0.1, ancho * 0.2, alto * 0.2);
}