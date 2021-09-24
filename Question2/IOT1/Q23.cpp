#include <iostream>
using namespace std;
// Thời lượng tĩnh
void doSomeThing_static()
{
	// thời lượng tĩnh thông qua từ khóa static. Dòng này chỉ được thực hiện một lần.
	static int s_value(0);
	++s_value;
	cout << s_value << endl;
} // s_value không bị hủy ở đây nhưng không thể truy cập được

int main()
{
	// Biến tĩnh
	doSomeThing_static();
	doSomeThing_static();
	doSomeThing_static();

	return 0;
}
// Kết quả trả về sẽ lần lượt là 1, 2 , 3 