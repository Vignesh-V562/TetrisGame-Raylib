#include<iostream>
#include"raylib.h"
#include"Game.h"
#include"grid.h"

double LastUpdateTime =0;
bool EventTriggered(double interval)
{
    double CurrentTime =GetTime();
    if(CurrentTime - LastUpdateTime >= interval)
    {
        LastUpdateTime =CurrentTime;
        return true;
    }
    return false;
}

int main(void)
{
    const int screenWidth =  500;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Vignesh's - Tetris Game");
    SetTargetFPS(60);

    Font font = LoadFontEx("movest/Movest Outline",64,0,0);

    Game game;

    while(!WindowShouldClose())
    {
        game.HandleInput();
        if(EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font,"Score",{365,15},38,2,WHITE);
        DrawTextEx(font,"Next",{365,175},38,2,WHITE);
        if(game.GameOver)
        {
            DrawTextEx(font,"Game Over",{325,450},30,2,WHITE);
        }
        DrawRectangleRounded({320,55,170,60},0.3,6,lightBlue);

        char ScoreText[10];
        sprintf(ScoreText,"%d",game.Score);
        Vector2 textSize = MeasureTextEx(font,ScoreText,38,2);
        DrawTextEx(font,ScoreText,{320 + (170 - textSize.x)/2,65},38,2,WHITE);

        DrawRectangleRounded({320,215,170,180},0.3,6,lightBlue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}