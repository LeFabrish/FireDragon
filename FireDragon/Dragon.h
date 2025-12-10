#pragma once
#include "Sprite.h"
class Dragon :
    public Sprite
{
private:
    int vidas; 
    int tiempoDisparo;
    bool disparo;
public:
    Dragon(int x, int y);
    ~Dragon();

    void perderVida();
    bool estaVivo();
    void resetearPosicion(int limiteAncho, int limiteAlto);
    void disparar_bola();
    bool disparando();
    void mover(Direccion tecla, int anchoPanel, int altoPanel) override;
    void dibujar(Graphics^ canvas) override;
    Rectangle getRectangle() override;
    int getDx();
    int getDy();
	int getVidas();
	int getAncho();
	int getAlto();
};

