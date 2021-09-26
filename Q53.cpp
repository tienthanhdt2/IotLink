#include<iostream>
using namespace std;

void main()
{
	int x, y, z;
	int* p, * q, * r;
	x = 1;
	y = 2;
	z = 3;
	p = &x;
	q = &y;
	r = &z;

	cout << "value of x is " << x << endl;
	cout << "value of y is " << y << endl;
	cout << "value of z is " << z << endl;
	cout << "value of p is " << p << endl;
	cout << "value of q is " << q << endl;
	cout << "value of r is " << r << endl;
	cout << "value of *p is " << *p << endl;
	cout << "value of *q is " << *q << endl;
	cout << "value of *r is " << *r << endl;

	cout << "SWAPPING POINTERS!" << endl;

	z = x;
	x = y;
	y = z;

	cout << "value of x is " << x << endl;
	cout << "value of y is " << y << endl;
	cout << "value of z is " << z << endl;
	cout << "value of p is " << p << endl;
	cout << "value of q is " << q << endl;
	cout << "value of r is " << r << endl;
	cout << "value of *p is " << *p << endl;
	cout << "value of *q is " << *q << endl;
	cout << "value of *r is " << *r << endl;




}//end main 