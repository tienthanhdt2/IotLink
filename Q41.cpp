#include <iostream>
using namespace std;
#define MAX 100

void Nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void Xuatmang(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void calculate(int a[], int n, int x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x)
		{
			cout << a[i] << " " ;
			count++;
		}
	}
	cout << "So luong phan tu lon hon" << x << " la :" << count;
}
int main()
{
	int a[MAX];
	int n,x;
	cout << "So phan tu can nhap :  ";
	cin >> n;
	Nhapmang(a, n);
	cout << "Xuat mang vua nhap :";
	Xuatmang(a, n);
	cout << "Nhap gia tri X=";
	cin >> x;
	cout << "Gia tri lon hon  " << x << " la = ";
	calculate(a, n, x);

}