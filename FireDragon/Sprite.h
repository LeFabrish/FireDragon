#pragma once

using namespace System::Drawing;


enum Direccion
{
	Arriba, Abajo,
	Derecha, Izquierda,
	Ninguno
};

class Sprite
{
protected:
	char* image;
	int ancho, alto;
	int indiceX, indiceY;
	int dx, dy;
	int x, y;
	int velocidad;
	int filas, columnas;
	bool activo;
public:
	Sprite(int x, int y);
	~Sprite();
	//dede
	int getVelocidad();
	int getX();
	int getY();
	bool isActivo();

	void setVelocidad(int velocidad);
	void setX(int x);
	void setY(int y);
	void setActivo(bool activo);

	//
	void cargarImagen(char* ruta, int filas, int columnas);
	virtual void mover(Direccion tecla, int anchoPanel, int altoPanel) = 0;
	virtual void  dibujar(Graphics^ canvas) = 0;
	virtual Rectangle getRectangle() = 0;
};

