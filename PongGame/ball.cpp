#include "ball.h"




Ball::Ball(int x, int y, float radius, Color color) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->color = color;
}

void Ball::draw()
{
	DrawCircle(x,y,radius,color);
}

void Ball::updateMoviment(int& cpuScore, int& playerScore)
{
	x += speedX;
	y += speedY;

	if((y + radius) >= GetScreenHeight() || y - radius <= 0)
	{
		speedY *= -1;
	}

	if((x + radius) >= GetScreenWidth() )
	{
		++cpuScore;
		resetBall();
	}

	if (x - radius <= 0)
	{
		++playerScore;
		resetBall();
	}
}

void Ball::resetBall()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	int speedChoices[2] = { -1,1 };
	speedX *= speedChoices[GetRandomValue(0, 1)];
	speedY *= speedChoices[GetRandomValue(0, 1)];
}


int Ball::getSpeedX()
{
	return speedX;
}

int Ball::getSpeedY()
{
	return speedY;
}

int Ball::getRadius()
{
	return radius;
}

Color Ball::getColor()
{
	return color;
}

float Ball::getY()
{
	return y;
}

float Ball::getX()
{
	return x;
}

void Ball::setSpeedX(int speedX)
{
	this->speedX = speedX;
}

void Ball::setSpeedY(int speedY)
{
	this->speedY = speedY;
}

void Ball::setRadius(int radius)
{
	this->radius = radius;
}

void Ball::setColor(Color color)
{
	this->color = color;
}

