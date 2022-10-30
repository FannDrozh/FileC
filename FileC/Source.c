#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void f(float a, float b, float c, FILE* file)
{
	float D, x1, x2;
	D = (b * b) + 4 * a * c;
	printf("Дискириминант: %f\n", D); 
	fprintf(file, "Дискириминант: %f\n", D);
	if (D > 0)
	{
		x1 = (-b + sqrt(D) / (2 * a));
		x2 = (-b - sqrt(D) / (2 * a));
		printf("x1=%f\n x2=%f", x1, x2);
		fprintf(file, "x1 = %f\n x2 = %f", x1, x2);
		fclose(file);
	}
	else if (D < 0)
	{
		printf("Вещественных корней нет");
		fprintf(file, "Вещественных корней нет");
		fclose(file);
	}
	else if (D = 0)
	{
		x1 = (-b + sqrt(D) / (2 / a));
		printf("x1=%f", x1);
		fprintf(file,"x1 = %f", x1);
		fclose(file);
	}
}


void main()
{
	system("chcp 1251 > nul");
	printf("***Квадратное уравнение*** \n");
	FILE* file; FILE* otv;
	otv = fopen("Otvet.txt", "w+");
	char line[254];
	float a, b, c;
	a = 0;b = 0;c = 0;
	if ((file = fopen("Znach.txt", "r"))) 
	{
		fgets(line, 254, file);
		//A
		int probelA = 0;
		int umnA = 1;
		int numA = 1;
		double Apr = 0;
		//счётчик символов до пробела
		for (int i = 0; i < 254; i++)
		{
			if (line[i] != 32) 
			{
				probelA++;
			}
			else
			{
				break;
			}
		}
		//считывание числа A из файла
		for (int i = probelA - 1; i >= 0; i--)
		{
			if(line[i]==46)
			{
				for (int j = 0; j < probelA-1; j++)
				{
					numA = numA * 10;
				}		
				a = a / numA;
				umnA = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i]!=45)
					{
						Apr = line[i] - '0';
						a += Apr * umnA;
						umnA = umnA * 10;
					}
					else 
					{
						a = a * -1;
					}
				}
				else
				{
					Apr = line[i] - '0';
					a += Apr * umnA;
					umnA = umnA * 10;
				}
			}
		}
		//B
		int probelB = probelA;
		int umnB = 1;
		int numB = 1;
		double Bpr = 0;		
		//счётчик символов до пробела		
		for (int i = probelA+1; i < 255; i++)
		{
			if (line[i] != 32)
			{
				probelB++;
			}
			else
			{
				break;
			}
		}
		//считывание числа B из файла
		for (int i = probelB; i >= probelA+1; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelB - 1; j++)
				{
					numB = numB * 10;
				}
				b = b / numB;
				umnB = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Bpr = line[i] - '0';
						b += Bpr * umnB;
						umnB = umnB * 10;
					}
					else
					{
						b = b * -1;
					}
				}
				else
				{
					Bpr = line[i] - '0';
					b += Bpr * umnB;
					umnB = umnB * 10;
				}
			}
		}
		//C
		int probelC = probelB;
		int umnC = 1;
		int numC = 1;
		double Cpr = 0;
		//счётчик символов до пробела		
		for (int i = probelB + 2; i < 255; i++)
		{
			if (line[i] != -52)
			{
				probelC++;
			}
			else
			{
				break;
			}
		}
		//считывание числа C из файла
		for (int i = probelC; i >= probelB + 2; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelC - 1; j++)
				{
					numC = numC * 10;
				}
				c = c / numC;
				umnC = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Cpr = line[i] - '0';
						c += Cpr * umnC;
						umnC = umnC * 10;
					}
					else
					{
						c = c * -1;
					}
				}
				else
				{
					Cpr = line[i] - '0';
					c += Cpr * umnC;
					umnC = umnC * 10;
				}
			}
		}
		
	}
	f(a, b, c, otv);
}


