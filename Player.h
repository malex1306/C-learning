#ifndef PLAYER_H
#define PLAYER_H


class Player {
    private:
        float x, y;
        float speed;

public:
    Player(float startX, float startY, float startSpeed);

    void move(float deltaX, float deltaY);

    float getX() const;
    float getY() const;
};

#endif //PLAYER_H