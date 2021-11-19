#include <iostream>
using namespace std;


void main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* p = a;
	printf("0x%x 0x%x 0x%x\n", a, *a, &a);
	printf("0x%x 0x%x 0x%x\n", p, *p, &p);

	printf("0x%x 0x%x 0x%x 0x%x\n", (a + 1), *(a + 1), *a + 1, &a + 1);
	printf("0x%x 0x%x 0x%x 0x%x\n", (p + 1), *(p + 1), *p + 1, &p + 1);
}
