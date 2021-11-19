#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int x = 2;
	int y = 8;
	int* p, * q;
	p = &x;
	q = &y;
	cout << &x << " " << x << endl;
	cout << p << " " << *p << endl;
	cout << &y << " " << y << endl;
	cout << q << " " << *q << endl;
	cout << &p << " " << &q << endl;
}