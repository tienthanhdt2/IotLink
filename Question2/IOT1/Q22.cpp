#include<stdio.h>
#include<iostream>
void calculate(int val)
{
	static int count = 10; // Biến tĩnh count =10;
	static int value;      //Biến tĩnh value
	printf("%d %d\n", value, count++); // in ra giá trị của value, count sau đó tăng biến count lên
	value = val;	// gán val cho value 
}

void main(int n, char** args)
{
	int i = 1; 
	int j= 2;
	calculate(i);
	calculate(j);
}

//Ban đầu giá trị của value sẽ bằng 0  và count bằng 10. Sau đó giá trị count lên 11. Gán giá trị val=1 vào value.
//Chạy lân gọi hàm thứ 2. Giá trị value = 1, count =11. Sau đó lại tăng count lên 12, Gán giá trị val=2 vào value.