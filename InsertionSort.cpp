#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 100
void Nhapmang(int arr[], int &n);
void Xuatmang(int arr[], int n);
void InsertionSort(int arr[], int n);
void BubbleSort(int arr[], int n);
void InterchangeSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void QuickSort(int arr[], int left, int right);

int main()
{
	int Array[MAX];
	int n; //Kich thuoc mang
	Nhapmang(Array, n);
	cout << "Mang vua nhap " << endl;
	Xuatmang(Array, n);
	cout << "Insertion Sort :" << endl;
	
	InsertionSort(Array, n);
	cout << "Xuat mang sau khi sap xep" << endl;
	Xuatmang(Array, n);
	
	SelectionSort(Array, n);
	cout << "Xuat mang sau khi sap xep" << endl;
	Xuatmang(Array, n);
	
	BubbleSort(Array, n);
	cout << "Xuat mang sau khi sap xep" << endl;
	Xuatmang(Array, n);

	InterchangeSort(Array, n);
	cout << "Xuat mang sau khi sap xep" << endl;
	Xuatmang(Array, n);

	mergeSort(Array,0, n-1);
	cout << "Xuat mang sau khi sap xep" << endl;
	Xuatmang(Array, n);

	QuickSort(Array, 0, n - 1);
	cout << "Xuat mang sau khi sap xep" << endl;
	Xuatmang(Array, n);
	
}
void Nhapmang(int arr[], int &n)
{
	cout << "Nhap so luong phan tu mang : "; 
	cin >> n;
	cout << "Nhap gia tri tung phan tu mang" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=" << endl;
		cin >> arr[i];
	}
}
void Xuatmang(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=" << arr[i] << endl;
	}
}
void InsertionSort(int arr[], int n)
{
	int x; // Luu value tri sau khi dich 
	int pos; // vi tri xet
	for (int i = 1; i < n; i++)
	{
		x = arr[i]; // Luu value xet vao x
		pos = i - 1; 
		while (pos>=0 && arr[pos] > x)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = x;
	}
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(arr[i], arr[min]);
		}
	}
}
void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0 ; j < n-i-1; j++) // Sau khi noi bot xuong cuoi thi giam di 1 phan tu roi xet tiep
		{
			if (arr[j]> arr[j+1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void InterchangeSort(int arr[], int n) 
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j]) 
			{
				Swap(arr[i], arr[j]);
			}
		}
	}
}
void merge(int arr[],int left, int mid, int right)
{
	int n1 = mid - left + 1; // Số phần tử mảng 1
	int n2 = right - mid;//Số phần tử mảng 2
	/* 0....7 
		m=3
		n1= 3-0 + 1=4
		n2 = 7-3=4
	*/
	//Tao 2 mang de tam luu 2 mang con
	int* L = new int[n1];
	int* R = new int[n2];
	
	//Sao chep cac phần tử vào 2 mảng mới tạo
	for (int  i = 0; i < n1 ; i++)
	{
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + 1 + j];
	}
	//current là vị trí hiện tại
	int i = 0, j = 0, current = left;

	//Sắp xếp 2 mảng theo đúng thứ tự 
	while (i<n1 && j <n2)
	{
		if (L[i] <= R[j])
		{
			arr[current++] == L[i++];
		}
		else
			arr[current++] == R[j++];
	}
	while (i< n1)
	{
		arr[current++] = L[i++];
	}
	while (j < n2)
	{
		arr[current++] = R[j++];
	}
	//Xoa 2 mang cap phat
	delete[] L, R;
}
void mergeSort(int arr[], int l, int r)
{
	//Neu mang chia doi duoc thi left < right
	//1.Tim vi tri chinh giua mang
	//2.Sắp xếp mảng 1 ( từ left đến mid)
	//3.Săp xếp mảng 2 ( từ mid+1 đến right)
	//4.Trộn 2 mảng lại với nhau

	if (l < r)
	{
		//left + (right - left) / 2 tương đương với (left + right) / 2
		int m = l + (r - l) / 2; // việc này tránh bị tràn số với left, right quá lơn

		//Đệ quy  mảng 1 tách từng phần từ
		mergeSort(arr, l, m);
		//Đệ quy  mảng 2 tách từng phần từ
		mergeSort(arr, m + 1, r);
		//Trộn 2 mảng đã sắp xếp
		merge(arr, l, m, r);
	}
}
void QuickSort(int arr[],int left, int right) 
{
	if (left<right)
	{
		//Chon pivot o vi tri ngau nhien
		int pivot = arr[left + rand() % (right - left)]; 
		//Chia lam 2 phan
		while (left <= right)
		{
			while (arr[left]<pivot)
			{
				++left;
			}
			while (arr[right]>pivot)
			{
				--right;
			}
			if (left <= right)
			{
				Swap(arr[left], arr[right]);
				++left;
				--right;
			}
			//Goi de quy lap lai
			QuickSort(arr, left, pivot - 1);
			QuickSort(arr, pivot + 1, right);
		}
	}
}