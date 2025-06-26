#include <iostream>
#include "raylib.h"
#include <string>
#define DARKRED  (Color){230, 41, 50, 255}

enum GameState { START_MENU, TRANSITION, PLAYING, GAME_OVER };

void ResetBall(Vector2 &ballPos, Vector2 &ballDir, float &ballSpeed, int screenWidth, int screenHeight, int ballSize) {
    ballPos = { screenWidth / 2.0f - ballSize / 2.0f, screenHeight / 2.0f - ballSize / 2.0f };
    int dirX = GetRandomValue(0, 1) == 0 ? 1 : -1;
    int dirY = GetRandomValue(0, 1) == 0 ? 1 : -1;
    ballDir = { (float)dirX, (float)dirY };
    ballSpeed = 4.0f;
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pong Masters");
    SetTargetFPS(60);

    // Game State & Setup
    GameState currentState = START_MENU;
    int transitionAlpha = 0;
    int winLimit = 5;
    int selectedLimit = 5;

    int player1Score = 0;
    int player2Score = 0;
    const int paddleWidth = 10;
    const int paddleHeight = 100;
    const int ballSize = 10;
    const float paddleSpeed = 5.0f;

    // Entities
    Rectangle leftPaddle = { 50, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight };
    Rectangle rightPaddle = { screenWidth - 50 - paddleWidth, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight };
    Vector2 ballPos;
    Vector2 ballDir;
    float ballSpeed;
    ResetBall(ballPos, ballDir, ballSpeed, screenWidth, screenHeight, ballSize);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        if (currentState == START_MENU) {
            DrawText("PONG MASTERS", screenWidth / 2 - MeasureText("PONG MASTERS", 50) / 2, 100, 50, DARKGRAY);

            DrawText("Set Win Limit:", screenWidth / 2 - 150, 200, 30, DARKBLUE);
            DrawText(TextFormat("%d", selectedLimit), screenWidth / 2 + 120, 200, 30, MAROON);

            Rectangle minusBtn = { screenWidth / 2 + 70, 200, 30, 30 };
            Rectangle plusBtn  = { screenWidth / 2 + 150, 200, 30, 30 };
            if (CheckCollisionPointRec(GetMousePosition(), minusBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && selectedLimit > 1) selectedLimit--;
            if (CheckCollisionPointRec(GetMousePosition(), plusBtn)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && selectedLimit < 15) selectedLimit++;

            DrawRectangleRec(minusBtn, GRAY); DrawText("-", minusBtn.x + 10, minusBtn.y + 5, 20, RAYWHITE);
            DrawRectangleRec(plusBtn, GRAY);  DrawText("+", plusBtn.x + 10, plusBtn.y + 5, 20, RAYWHITE);

            Rectangle startButton = { screenWidth / 2 - 100, 300, 200, 60 };
            Color btnColor = CheckCollisionPointRec(GetMousePosition(), startButton) ? DARKGRAY : GRAY;
            DrawRectangleRec(startButton, btnColor);
            DrawText("START", screenWidth / 2 - MeasureText("START", 30) / 2, 315, 30, RAYWHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), startButton)) {
                currentState = TRANSITION;
                transitionAlpha = 0;
                player1Score = 0;
                player2Score = 0;
                winLimit = selectedLimit;
            }

        } else if (currentState == TRANSITION) {
            DrawText("Get Ready...", screenWidth / 2 - MeasureText("Get Ready...", 30) / 2, 280, 30, DARKGRAY);
            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, transitionAlpha / 255.0f));
            transitionAlpha += 5;
            if (transitionAlpha >= 255) {
                currentState = PLAYING;
                ResetBall(ballPos, ballDir, ballSpeed, screenWidth, screenHeight, ballSize);
            }

        } else if (currentState == PLAYING) {
            // Movement
            if (IsKeyDown(KEY_W) && leftPaddle.y > 0) leftPaddle.y -= paddleSpeed;
            if (IsKeyDown(KEY_S) && leftPaddle.y + paddleHeight < screenHeight) leftPaddle.y += paddleSpeed;
            if (IsKeyDown(KEY_UP) && rightPaddle.y > 0) rightPaddle.y -= paddleSpeed;
            if (IsKeyDown(KEY_DOWN) && rightPaddle.y + paddleHeight < screenHeight) rightPaddle.y += paddleSpeed;

            ballPos.x += ballDir.x * ballSpeed;
            ballPos.y += ballDir.y * ballSpeed;

            if (ballPos.y <= 0 || ballPos.y + ballSize >= screenHeight) ballDir.y *= -1;

            Rectangle ballRect = { ballPos.x, ballPos.y, ballSize, ballSize };

            if (CheckCollisionRecs(ballRect, leftPaddle)) {
                ballDir.x = 1; ballSpeed += 1.0f;
                ballPos.x = leftPaddle.x + leftPaddle.width;
            }
            if (CheckCollisionRecs(ballRect, rightPaddle)) {
                ballDir.x = -1; ballSpeed += 1.0f;
                ballPos.x = rightPaddle.x - ballSize;
            }

            if (ballPos.x < 0) {
                player2Score++; ResetBall(ballPos, ballDir, ballSpeed, screenWidth, screenHeight, ballSize);
            }
            if (ballPos.x > screenWidth) {
                player1Score++; ResetBall(ballPos, ballDir, ballSpeed, screenWidth, screenHeight, ballSize);
            }

            // 🏁 Game over condition
            if (player1Score >= winLimit || player2Score >= winLimit) {
                currentState = GAME_OVER;
            }

            // Draw everything
            DrawRectangleRec(leftPaddle, RAYWHITE);
            DrawRectangleRec(rightPaddle, RAYWHITE);
            DrawRectangleV(ballPos, (Vector2){ballSize, ballSize}, MAROON);

            DrawText(TextFormat("%d", player1Score), screenWidth / 4, 20, 40, DARKBLUE);
            DrawText(TextFormat("%d", player2Score), screenWidth * 3 / 4, 20, 40, DARKRED);
            DrawText(TextFormat("Speed: %.1f", ballSpeed), screenWidth / 2 - 50, screenHeight - 30, 20, DARKGRAY);

        } else if (currentState == GAME_OVER) {
            const char *winner = player1Score > player2Score ? "PLAYER 1 WINS!" : "PLAYER 2 WINS!";
            DrawText("GAME OVER", screenWidth / 2 - MeasureText("GAME OVER", 50) / 2, 180, 50, MAROON);
            DrawText(winner, screenWidth / 2 - MeasureText(winner, 30) / 2, 250, 30, DARKBLUE);

            Rectangle newBtn = { screenWidth / 2 - 120, 350, 100, 50 };
            Rectangle exitBtn = { screenWidth / 2 + 20, 350, 100, 50 };

            DrawRectangleRec(newBtn, GRAY);
            DrawText("NEW", newBtn.x + 20, newBtn.y + 15, 20, RAYWHITE);
            DrawRectangleRec(exitBtn, GRAY);
            DrawText("EXIT", exitBtn.x + 25, exitBtn.y + 15, 20, RAYWHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mp = GetMousePosition();
                if (CheckCollisionPointRec(mp, newBtn)) {
                    currentState = START_MENU;
                }
                if (CheckCollisionPointRec(mp, exitBtn)) {
                    break;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
