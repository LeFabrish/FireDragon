#pragma once
#include "Sprite.h"
class Ovni :
    public Sprite
{
public:
    Ovni(int x, int y);
    ~Ovni();

    void mover(Direccion tecla, int anchoPanel, int altoPanel) override;
    void dibujar(Graphics^ canvas) override;
    Rectangle getRectangle() override;
};

