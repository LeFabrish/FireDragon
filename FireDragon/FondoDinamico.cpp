//FondoDinamico.cpp
#include "FondoDinamico.h"
#include <cstring>
using namespace System::Drawing;
FondoDinamico::FondoDinamico() {
	this->imagen = new char[100];
	this->imagen[0] = '\0';
	this->anchoReal = 0;
	this->altoReal = 0;
	this->velocidad = 10;
	this->pixelX = 0;
	this->largoRectOrigen = anchoReal / 2;
	this->altoRectOrigen = altoReal;

}
FondoDinamico::FondoDinamico(char* ruta, int ancho, int alto) {
	this->imagen = new char[100];
	strcpy_s(imagen, 100, ruta);
	this->anchoReal = ancho;
	this->altoReal = alto;
	this->velocidad = 10;
	this->pixelX = 0;
	this->largoRectOrigen = anchoReal / 2;
	this->altoRectOrigen = altoReal;

}
FondoDinamico::~FondoDinamico() {
	if (imagen != nullptr) {
		delete[] imagen;
		imagen = nullptr;
	}
}
void FondoDinamico::cargarImagen(char* ruta, int ancho, int alto) {
	if (ruta == nullptr) return;

	strcpy_s(imagen, 100, ruta);
	this->anchoReal = ancho;
	this->altoReal = alto;
	this->largoRectOrigen = anchoReal * 1;
	this->altoRectOrigen = altoReal * 1;


}
void FondoDinamico::mover() {
	pixelX += velocidad;
	// Reiniciar cuando llegamos al final de la imagen
	if (pixelX >= anchoReal) {
		pixelX = 0;
	}
}

void FondoDinamico::dibujar(Graphics^ canvas, int anchoVentana, int altoVentana) {
	// Uso de IA para dibujar un fondo dinámico que se desplaza horizontalmente
	if (anchoReal == 0 || altoReal == 0 || imagen == nullptr) return;

	System::Drawing::Bitmap^ bmp = nullptr;

	try {
		bmp = gcnew System::Drawing::Bitmap(gcnew System::String(imagen));
	}
	catch (...) {
		// Si falla la carga, salir sin dibujar
		return;
	}


	// Calcular cuánto de la imagen podemos mostrar desde pixelX
	int anchoDisponible = anchoReal - pixelX;

	// Caso normal: tomamos una sección de la imagen
	Rectangle origen = Rectangle(pixelX, 0, anchoVentana, altoRectOrigen);
	Rectangle destino = Rectangle(0, 0, (int)(anchoVentana * 1), (int)(altoReal * 1));
	canvas->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);

	delete bmp;
}
char* FondoDinamico::getImagen() {
	return imagen;
}
int FondoDinamico::getAnchoReal() {
	return anchoReal;
}
int FondoDinamico::getAltoReal() {
	return altoReal;
}
