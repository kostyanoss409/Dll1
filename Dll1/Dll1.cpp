// Dll_try1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <math.h>
#include <ctime>
#include <cstdlib>
//using namespace std;


extern "C" _declspec(dllexport)
double Val(double x)
{
	srand(time(0));
	double	y = rand() % 1000;
	return y;
}
extern "C" _declspec(dllexport)
bool ccout(double Val, double x)
{
	if (Val == x)
		return 1;
	else return 0;
}
extern "C" _declspec(dllexport)
long factorial(long x)
{
	int i;
	long C, fact = 1;
	for (i = 1; i <= x; i++)
		fact = i * fact;
	C = fact;
	return C;
}
extern "C" _declspec(dllexport)
bool ccheck(double Val, long factorial)
{
	if (Val == factorial)
		return 1;
	else return 0;
}