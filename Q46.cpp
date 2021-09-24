#include <iostream>
using namespace std;

int x = 11;
int y = 12;
int a[5] = { 21, 22, 23, 24, 25 };
int u = 31;
int v = 32;

int main()
{
	cout << &x << " " << &y << " " << &u << " " << &v << endl;
	for (int i = -2; i < 7; i++)
		cout << i << " " << a[i] << endl;

}
//Kết quả in ra từ vị trí tại địa chỉ &a[-2] đến &a[7] tương ứng với giá trị x y , a[5], u v 