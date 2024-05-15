#include <iostream>
#include <raylib.h>
#include "ball.h"
#include  "paddle.h"
#include  "cpu.h"

using namespace std;

int playerScore = 0 ;
int cpuScore = 0;

const int& screenWidth{ 1280 };
const int& screenHeight{ 800 };


Ball ball(screenHeight/2,screenHeight/2,20,GREEN);
Paddle player(6, WHITE);
Cpu cpu;



int main()
{
    cpu.setWidth(25);
    cpu.setHeight(120);
    cpu.setX(10);
    cpu.setY((screenHeight / 2) - (cpu.getHeight() / 2));
    cpu.setColor(WHITE);
    cpu.setSpeed(6);
   

    player.setWidth(25);
    player.setHeight(120);
    player.setX(screenWidth - player.getWidth() - 10);
    player.setY((screenHeight / 2) - (player.getHeight() / 2));

    ball.setSpeedX(7);
    ball.setSpeedY(7);


    InitWindow(screenWidth,screenHeight,"My Pong Game");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();

        //Update
        player.movimentPaddle();
        ball.updateMoviment(cpuScore,playerScore);
        cpu.movimentPaddle(ball.getY());

        //Checking Collision
        if(CheckCollisionCircleRec(Vector2{ball.getX(),ball.getY()},ball.getRadius(),Rectangle{player.getX(),player.getY(),player.getWidth(),player.getHeight()}))
        {
            int speed = ball.getSpeedX() * -1;
            ball.setSpeedX(speed);
        }

        if(CheckCollisionCircleRec(Vector2{ ball.getX(),ball.getY() }, ball.getRadius(), Rectangle{cpu.getX(),cpu.getY(),cpu.getWidth(),cpu.getHeight()}))
        {
            int speedX = ball.getSpeedX() * -1;
            ball.setSpeedX(speedX);
        }

        //Drawing
        DrawText(TextFormat("%i",cpuScore), screenWidth/4, 20, 80, WHITE);
        DrawText(TextFormat("%i", playerScore), 3 * screenWidth / 4 - 20, 20, 80, WHITE);
        ClearBackground(BLACK);
        DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,WHITE);

    	ball.draw();
        cpu.draw();


        player.draw();
        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}

