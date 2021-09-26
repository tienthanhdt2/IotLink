#include <stdio.h>
#include <iostream>
using namespace std;

typedef int* IntPtrType; //Con trỏ trỏ tới giá trị ở địa chỉ biên InPtrType

int main()
{
	IntPtrType ptr_a, ptr_b, * ptr_c; // Con trỏ trỏ đến giá trị kiểu InPtrType của biến prt_a,ptrb.
	//Con trỏ trỏ đến con trỏ trỏ đến giá trị kiểu InptrType của biến ptr_c 

	ptr_a = new int; //Cấp phát động một số nguyên và gán địa chỉ ptr_a nắm giữ
	*ptr_a = 3; // Giá trị tại địa chỉ ptr_a  đang giữ 
	ptr_b = ptr_a; // Gán giá trị cho ptr_a cho ptr_b
	cout << *ptr_a << " " << *ptr_b << "\n"; //In ra giá trị tại địa chỉ ptr_a là 3 

	ptr_b = new int; //Cấp phát động một số nguyên và gán địa chỉ ptr_b nắm giữ
	*ptr_b = 9; // Giá trị tại địa chỉ ptr_b  đang giữ
	cout << *ptr_a << " " << *ptr_b << "\n"; //In ra giá trị tại địa chỉ ptr_a là 3 và ptr_b là 9	

	*ptr_b = *ptr_a; // Gán giá trị tại địa chỉ ptr_a cho giá trị tại địa chỉ ptr_b	
	cout << *ptr_a << " " << *ptr_b << "\n"; // In ra giá trị tại địa chỉ của prt_a. ptr_b

	delete ptr_a; // Xóa bộ nhớ đệm ptr_a
	ptr_a = ptr_b; // Gán giá trị prt_b cho ptr_a
	cout << *ptr_a << " " << *&*&*&*&*ptr_b << "\n"; // In ra giá trị tại địa chỉ ptr_a và  giá trị tại địa chỉ ptr_b ( Do &*prt_b=prt_b)

	ptr_c = &ptr_a; // gán địa chỉ ptr_a cho ptr_c
	cout << *ptr_c << " " << **ptr_c << "\n"; // In ra giá trị tại địa chỉ prt_c nắm giữ nghĩa là giá trị ptr_a

	delete ptr_a; // Xóa bộ nhớ đệm trả lại vùng nhớ
	ptr_a = NULL; // gán ptr_a thành con trỏ NULL 

	return 0;
}
