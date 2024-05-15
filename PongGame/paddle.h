#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>

class Paddle
{
public:
	Paddle( int speed, Color color);

	Paddle() = default;

	void setX(float x);
	void setY(float y);
	void setSpeed(int speed);
	void setColor(Color color);
	void setHeight(float height);
	void setWidth(float width);

	void movimentPaddle();

	float getHeight();
	float getWidth();
	float getX();
	float getY();

	void draw();
protected:
	int speed;
	Color color;
	float x;
	float y;
	float width;
	float height;


};

#endif

