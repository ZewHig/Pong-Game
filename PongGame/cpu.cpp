#include "cpu.h"

void Cpu::movimentPaddle(int ballY)
{
	if(y + (height/2) > ballY)
	{
		y -= speed;
	}

	if (y + (height / 2) <= ballY)
	{
		y += speed;
	}
}
