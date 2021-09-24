#include<stdio.h>
#include<iostream>
using namespace std;

int Floor(float x)
{
	return int(x);
}
int ceil (float x)
{
	float y;
	y = x - int(x);
	return y > 0 ? x + 1 : x;
}
int round(float x)
{
	float y;
	y = x - int(x);
	return y >= 0.5 ? x + 1 : x;
}
int main()
{
	cout << Floor(6.7);
	cout << ceil(6.1);
	cout << round(6.4);
}