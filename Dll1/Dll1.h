#pragma once
#ifndef DLLHEADERH
#define DLLHEADERH
extern "C" _declspec(dllexport) double Val(double x);
extern "C" _declspec(dllexport) bool ccout(double Val, double x);
extern "C" _declspec(dllexport) long factorial(long x);
extern "C" _declspec(dllexport) bool ccheck(double Val, long factorial);

#endif