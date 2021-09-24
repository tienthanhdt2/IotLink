#include <stdio.h>
#include <iostream>
using namespace std;

int xyz;
int main(int n, char** args)
{
	xyz = 0;
	cout << xyz;
}
//Do giá trị hằng số xyz là hằng số const nên giá trị của nó không thể thay đổi. Cách giải quyết có thể bỏ hằng số const hoặc không gán giá trị xyz