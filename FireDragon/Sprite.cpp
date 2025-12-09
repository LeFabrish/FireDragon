#include "Sprite.h"
#include <cstring>

Sprite::Sprite(int x, int y) :
	x(x), y(y), ancho(0), alto(0), indiceX(0), indiceY(0)
	, dx(0), dy(0), velocidad(0), filas(0), columnas(0),
	activo(true) {
	image = new char[100];
}
Sprite::~Sprite(){
	if (image) delete[] image;
}
//dede
int Sprite::getVelocidad() { return velocidad; }
int Sprite::getX() { return x; }
int Sprite::getY() { return y; }
bool Sprite::isActivo() { return activo; }

void Sprite::setVelocidad(int velocidad) { this->velocidad = velocidad; }
void Sprite::setX(int x) { this->x = x; }
void Sprite::setY(int y) { this->y = y; }
void Sprite::setActivo(bool activo) { this->activo = activo; }

//
void Sprite::cargarImagen(char* ruta, int filas, int columnas){
    strcpy_s(image, 100, ruta);
    this->filas = filas;
    this->columnas = columnas;

    // Calcular ancho y alto de cada cuadro del sprite
    System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(gcnew System::String(image));
    ancho = bitmap->Width / columnas;
    alto = bitmap->Height / filas;
    delete bitmap;
}