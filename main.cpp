#include "Coin.h"
#include "Player.h"
#include "raylib.h"
#include <vector>

#include "Enemy.h"

enum GameState {
    TITLE, GAMEPLAY, GAMEOVER
};
GameState currentState = TITLE;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Mein erstes 2D C++ Spiel");

    Player spieler(screenWidth/ 2.0f, screenHeight / 2.0f, 250.0f);
    Enemy gegner(100.0f,100.0f, 2.0f);

    SetTargetFPS(60);
    std::vector<Coin> coinListe;

    for (int i= 0; i < 5; i++) {
        Coin neuerCoin(0, 0, true);
        neuerCoin.respawn(screenWidth, screenHeight);
        coinListe.push_back(neuerCoin);
    }
    int score = 0;

    while (!WindowShouldClose()) {
        switch (currentState) {
            case TITLE:
                if (IsKeyPressed(KEY_ENTER)) currentState = GAMEPLAY;
                break;
            case GAMEPLAY: {
                float moveX = 0;
                float moveY = 0;

                if (IsKeyDown(KEY_W)) moveY -= 1.0f;
                if (IsKeyDown(KEY_S)) moveY += 1.0f;
                if (IsKeyDown(KEY_A)) moveX -= 1.0f;
                if (IsKeyDown(KEY_D)) moveX += 1.0f;

                float dt = GetFrameTime();
                spieler.move(moveX * dt, moveY *dt);
                for (Coin &c : coinListe)
                {
                    if (CheckCollisionCircles(
            { spieler.getX(), spieler.getY()}, 25,
            { c.getX(), c.getY()}, 10))
                    {
                        c.respawn(screenWidth, screenHeight);
                        score++;
                    }
                }
                gegner.update(screenWidth, screenHeight);
                if (CheckCollisionCircles(
                    { spieler.getX(), spieler.getY()}, 25,
                    { gegner.getX(), gegner.getY()}, 15
                    ))
                {
                    score -= 1;
                }
                if (score < 0) currentState = GAMEOVER;
            }
                break;

            case GAMEOVER:
                if (IsKeyPressed(KEY_F1)) {
                    score = 0;
                    currentState = GAMEPLAY;

                }
                break;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentState == TITLE) {
            DrawText("Test Game", 200, 200, 40, DARKGRAY);
            DrawText("Drücke ENTER zum starten", 220, 300, 20, LIGHTGRAY);
        }else if (currentState == GAMEPLAY) {
            DrawCircle((int)spieler.getX(), (int)spieler.getY(), 25, MAROON);
            DrawCircle((int)gegner.getX(), (int)gegner.getY(), 15, BLACK);
            for (const auto& coin : coinListe) {
                DrawCircle((int)coin.getX(), (int)coin.getY(), 10, GOLD);
            }

            DrawText("Bewege den Punkt", 10, 10, 20, DARKGRAY);
            // DrawRectangle(5, 30, 150, 60, Fade(SKYBLUE, 0.5f));
            Rectangle scoreBox = {5, 30, 150, 60};
            DrawRectangleRounded(scoreBox , 0.3f, 10, Fade(SKYBLUE, 0.5f));
            DrawRectangleRoundedLinesEx(scoreBox, 0.3f, 10, 2.0f, BLUE);
            Color displayColor = (score < 0) ? RED : (score > 20 ? GOLD : BLACK);
            DrawText("Score:", 15, 40, 10, DARKGRAY);
            DrawText(TextFormat("%04i", score), 15, 55, 30, displayColor);
        }else if (currentState == GAMEOVER) {
            DrawText("Game Over", 250, 250, 40, RED);
            DrawText("Drücke F1 für Neustart", 270, 300, 20, DARKGRAY);
        }


        EndDrawing();
    }
    CloseWindow();

    return 0;
}
