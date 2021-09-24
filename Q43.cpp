#include <stdio.h>
#include <iostream>

int main(int n, char** args)
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i * 10;
	}
	printf("0x%x 0x%x 0x%x\n", a, *a, &a);
	printf("0x%x 0x%x 0x%x 0x%x\n", (a + 1), *(a + 1), *a + 1, &a + 1);
}
/*
x in ra gia tri cua bien a
&x in ra dia chi bộ nhớ biến x
*x in giá trị ở địa chỉ bộ nhớ biến x
&a + 1 dia chi cua vung nho sau mang a, cach a 10*4 bytes = 40 bytes
*/