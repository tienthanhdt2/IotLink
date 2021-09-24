#include <stdio.h>
#include <iostream>
int main(int n, char** args)
{
	int i = 5;
	while (i = 5)
	{
		printf("Inside loop\n");
		i--;
	}
}

// Chương trình này sẽ bị lặp vô hạn vì không có điều kiện dừng. Vì điều kiện trong while là phép gán.