#include "Coin.h"

#include <raylib.h>

Coin::Coin(float startX, float startY, bool isActive) {
    x = startX;
    y = startY;
    isActive = isActive;
}

void Coin::respawn(int screenWidth, int screenHeight) {

    x = (float)GetRandomValue(20, screenWidth - 20);
    y = (float)GetRandomValue(20, screenHeight - 20);
}

float Coin::getX() const {return x;}
float Coin::getY() const {return y;}
