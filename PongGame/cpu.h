#ifndef CPU_H
#define CPU_H
#include "paddle.h"

class Cpu :public Paddle
{
public:
	void movimentPaddle(int ballY);
};

#endif

