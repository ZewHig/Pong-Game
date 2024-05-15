#include "paddle.h"

Paddle::Paddle(int speed, Color color)
{
	this->speed = speed;
	this->color = color;

}

void Paddle::draw()
{
	DrawRectangle(x, y, width, height, color);
}
void Paddle::movimentPaddle()
{
	if(IsKeyDown(KEY_UP))
	{
		if(y <= 0)
		{
			y = 0;
		}else
		{
			y -= speed;
			
		}
	}

	if(IsKeyDown(KEY_DOWN))
	{
		if(y + height >= GetScreenHeight())
		{
			y = GetScreenHeight() - height;
		}else
		{
			y += speed;
			
		}
	}
}
void Paddle::setX(float x)
{
	this->x = x;
}

void Paddle::setY(float y)
{
	this->y = y;
}

void Paddle::setSpeed(int speed)
{
	this->speed = speed;
}

void Paddle::setColor(Color color)
{
	this->color = color;
}

void Paddle::setHeight(float height)
{
	this->height = height;
}

void Paddle::setWidth(float width)
{
	this->width = width;
}


float Paddle::getHeight()
{
	return height;
}

float Paddle::getWidth()
{
	return width;
}

float Paddle::getX()
{
	return x;
}

float Paddle::getY()
{
	return y;
}



