#include<stdio.h>
#include<iostream>
#include<time.h>
using namespace std;

int main()
{
    while (1)
    {
        int MAX;
        cout << "Nhap Max:" << " " << endl;
        cin >> MAX;

        clock_t start, end;
        double time_use;
        start = clock();
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                for (int k = 0; k < MAX; k++)
                {
                }
            }
        }
        end = clock();
        time_use = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Thoi gian su dung " << time_use << endl;
    }
}
//Thời gian 10 là 0s
//Thời gian 100 là 0.003
//Thời gian 1000 là 2.765

