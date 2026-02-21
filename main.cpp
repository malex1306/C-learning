#include "Coin.h"
#include "Player.h"
#include "raylib.h"
#include <vector>



int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Mein erstes 2D C++ Spiel");

    Player spieler(screenWidth/ 2.0f, screenHeight / 2.0f, 5.0f);

    SetTargetFPS(60);
    std::vector<Coin> coinListe;

    for (int i= 0; i < 5; i++) {
        Coin neuerCoin(0, 0, true);
        neuerCoin.respawn(screenWidth, screenHeight);
        coinListe.push_back(neuerCoin);
    }
    int score = 0;

    while (!WindowShouldClose()) {
        float moveX = 0;
        float moveY = 0;

        if (IsKeyDown(KEY_W)) moveY -= 1.0f;
        if (IsKeyDown(KEY_S)) moveY += 1.0f;
        if (IsKeyDown(KEY_A)) moveX -= 1.0f;
        if (IsKeyDown(KEY_D)) moveX += 1.0f;

        spieler.move(moveX, moveY);
        for (Coin &c : coinListe) {
            if (CheckCollisionCircles(
    { spieler.getX(), spieler.getY()}, 25,
    { c.getX(), c.getY()}, 10))
                {
                    c.respawn(screenWidth, screenHeight);
                    score++;
                }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle((int)spieler.getX(), (int)spieler.getY(), 25, MAROON);
        for (const auto& coin : coinListe) {
            DrawCircle((int)coin.getX(), (int)coin.getY(), 10, GOLD);
        }

        DrawText("Bewege den Punkt", 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Score: %i", score), 10, 40, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
