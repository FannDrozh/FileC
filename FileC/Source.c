#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
main(void)
{
	system("chcp 1251 > nul");
	FILE* file;
	file = fopen("","r");
	f(4, 5, 6);
	return 0;
}

float f(int a, int b, int c)
{
	double D,x1,x2;
	D = (b * b) + 4 * a * c;
	if (D > 0)
	{
		x1 = (-b + sqrt(D) / (2 * a));
		x2 = (-b - sqrt(D) / (2 * a));
		printf("x1=%f", x1);
	}
	else if(D < 0)
	{
		printf("Вещественных корней нет");
	}
	else if(D = 0)
	{
		x1 = (-b + sqrt(D) / (2 / a));
		printf("x1=%f", x1);
	}

}

