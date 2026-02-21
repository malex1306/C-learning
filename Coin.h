#ifndef COIN_H
#define COIN_H


class Coin {
    private:
        float x, y;
        bool isActive;

    public:
    Coin(float startX, float startY, bool isActive);

    void respawn(int screenWidth, int screenHeight);

    float getX() const;
    float getY() const;
    bool getIsActive() const;
};


#endif //COIN_H