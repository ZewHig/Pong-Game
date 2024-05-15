#ifndef BALL_H
#define BALL_h
#include <raylib.h>


class Ball{
public:

    int getSpeedX();
    int getSpeedY();
    int getRadius();
    Color getColor();
    float getY();
    float getX();

    void setSpeedX(int speedX);
    void setSpeedY(int speedY);
    void setRadius(int radius);
    void setColor(Color color);
    void updateMoviment(int& cpuScore, int& playerScore);

    void draw();


    Ball(int x, int y, float radius, Color color);

private:
    float x;
    float y;

    int speedX;
    int speedY;
    int radius;

    Color color;

    void resetBall();
};

#endif // !BALL_H


