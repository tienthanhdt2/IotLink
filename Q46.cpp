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
		cout << i << " " << a[i] << " " << &a[i] << endl;

}
//Kết quả in ra địa chỉ của các giá trị x,y,u,v
// kết quả i tại -2 là 24 rồi 25 rồi quay về 21 rồi cứ tiếp tục đên hết sau đó in ra địa chỉ của các giá trị vừa rồi