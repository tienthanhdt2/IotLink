#include <stdio.h>
#include <iostream>
using namespace std;
int main(int n, char** args)
{
	int i = 140;
	unsigned char c = i;
	int j;
	if (i <= 127) j = c;
	else j = 256 + c;
	printf("%d", j);
	system("pause");
}
/*
*Kết quả: -114  bời vì giới  hạn kiểu  signed char = [-128,127], nên c = 140 sẽ được gán trị ngược lại
* Nếu thay đổi kiểu dữ liệu của biến c thành unsigned char thì giá trị sẽ là 140 giống giá trị c
* */