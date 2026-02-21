#include "Enemy.h"
#include "raylib.h"

Enemy::Enemy(float startX, float startY, float startSpeed)
    : x(startX), y(startY), speed(startSpeed) {
    dirX = 1.0f;
    dirY = 0.5f;
}

void Enemy::update(int screenWidth, int screenHeight) {
    if (GetRandomValue(0, 100) < 2) {
        dirX = (float)GetRandomValue(-10, 10) / 10.0f;
        dirY = (float)GetRandomValue(-10, 10) / 10.0f;
    }

    x += dirX * speed;
    y += dirY * speed;

    if (x <= 0 || x >= screenWidth) dirX *= -5;
    if (y <= 0 || y >= screenHeight) dirY *= -5;
}

float Enemy::getX() const {
    return x;
}

float Enemy::getY() const {
    return y;
}
