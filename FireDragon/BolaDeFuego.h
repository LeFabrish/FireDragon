#pragma once
#include "Sprite.h"
class BolaDeFuego :
    public Sprite
{
public:
    BolaDeFuego(int dragonDx, int dragonDy, int x, int y);
    ~BolaDeFuego();

    void mover(Direccion tecla, int anchoPanel, int altoPanel) override;
    void dibujar(Graphics^ canvas) override;
    Rectangle getRectangle() override;
};

