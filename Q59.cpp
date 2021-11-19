#include<iostream>

void main()
{
	int* a = new int; // Cấp phát mảng động một số nguyên và gán địa chỉ cho a nắm giữ 
	*a = 10; // Gán giá trị 10 cho a 
	delete a; // giải phóng giá trị a
	printf("%d", *a); // Sau khi giải phóng giá trị a sẽ được cấp phát giá trị ngẫu nhiên ở tác vụ nào đó ở máy
}
