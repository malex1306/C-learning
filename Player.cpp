#include "Player.h"

Player::Player(float startX, float startY, float startSpeed) {
    x = startX;
    y = startY;
    speed = startSpeed;
}

void Player::move(float deltaX, float deltaY) {
    float nextX = x + (deltaX * speed);
    float nextY = y + (deltaY * speed);

    if (nextX >= 25 && nextX <= 775) {
        x = nextX;
    }
    if (nextY >= 25 && nextY <= 575) {
        y = nextY;
    }
}
float Player::getX() const{
    return x;
}
float Player::getY() const{
    return y;
}

