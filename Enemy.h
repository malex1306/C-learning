#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    float x, y;
    float speed;
    float dirX, dirY;

public:
    Enemy(float startX, float startY, float startSpeed);

    void update(int screenWidth, int screenHeight);

    float getX() const;
    float getY() const;
};

#endif //ENEMY_H