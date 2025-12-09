#pragma once
using namespace System::Drawing;
// Clase para manejar un fondo dinámico que se desplaza horizontalmente(de momento, estoy pensando en que sea para vertical y en movimiento del jugador)
class FondoDinamico
{
private:
	char* imagen;
	int anchoReal, altoReal;
	int largoRectOrigen, altoRectOrigen;
	int velocidad;
	int pixelX;// pero solo es una imagen que se repite
public:
	// Constructor
	FondoDinamico();
	FondoDinamico(char* ruta, int ancho, int alto);
	~FondoDinamico();

	void cargarImagen(char* ruta, int ancho, int alto);
	void mover();
	void dibujar(Graphics^ canvas, int anchoVentana, int altoVentana);

	char* getImagen();
	int getAnchoReal();
	int getAltoReal();

};

