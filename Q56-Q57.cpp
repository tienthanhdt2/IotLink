#include<iostream>
void main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* p = a; // Con trỏ p trỏ tới địa chỉ của mảng a

	int* p2 = new int;

	delete p; // Giải phóng giá trị p, giá trị sẽ bị thay đổi 
	delete a; // Giải phóng địa chỉ a sẽ bị thay đổi một cách ngẫu nhiên 
	delete p2; // sử dụng delete để giải phóng bộ nhớ cấp phát động
}
// Sử dụng delete [] sử dụng khi chúng ta cấp phát bộ nhớ động  cho mảng