## I.STD::Move()

**1. Mục đính**
  - Nó chuyển đổi một biểu thức từ một lvalue (chẳng hạn như một biến có tên) thành một x-Value
   - Hàm xây dựng di chuyển được sử dụng thay cho hàm tạo sao chép, nếu đối tượng có kiểu "R-value-Reference" (Type &&)
   -  std :: move là một hàm thư viện chuẩn truyền (sử dụng static_cast) đối số của nó thành một tham chiếu  R-value, để có thể gọi ra ngữ nghĩa của move. Vì vậy, chúng ta có thể sử dụng std :: move để chuyển một L-value thành một kiểu sẽ thích được di chuyển hơn được sao chép.
   - std :: move có thể được sử dụng bất cứ khi nào chúng ta muốn coi một L-value giống như một R-value nhằm mục đích gọi ra ngữ nghĩa chuyển thay vì ngữ nghĩa sao chép.
  

**2. Khi nào nên sử dụng nó?**

- Sử dụng thông thường là "di chuyển" tài nguyên từ đối tượng này sang đối tượng khác thay vì sao chép
- Tạo bản sao có thể không hiệu quả,điều đó dẫn đến việc tạo và phá hủy chuỗi quá nhiều, diễn ra chậm.

**Example:**
```C++
#include <iostream>
#include <string>

template<class T>
void myswap(T& a, T& b)
{
  T tmp { a }; // gọi hàm tạo bản sao
  a = b; // gọi  sao chép
  b = tmp; // gọi  sao chép
}

int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };

	std::cout << "x: " << x << endl;
	std::cout << "y: " << y << endl;

	myswap(x, y);

	std::cout << "x: " << x << endl;
	std::cout << "y: " << y << endl;

	return 0;
}
```
- Việc sao chép không cần thiết ở đây. Tất cả những gì  thực sự đang cố gắng làm là hoán đổi các giá trị của a và b, điều này có thể được thực hiện tốt chỉ bằng cách sử dụng 3 nước đi! Vì vậy, nếu chúng ta chuyển từ ngữ nghĩa copy sang ngữ nghĩa move , chúng ta có thể làm cho mã của mình hoạt động hiệu quả hơn.

```C++
#include <iostream>
#include <string>
#include <utility> // for std::move

template<class T>
void myswap(T& a, T& b)
{
  T tmp { std::move(a) }; // gọi hàm tạo di chuyển
  a = std::move(b); // gọi chuyển nhượng
  b = std::move(tmp); // gọi chuyển nhượng
}

int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };

	std::cout << "x: " << x << endl;
	std::cout << "y: " << y << endl;

	myswap(x, y);

	std::cout << "x: " << x << endl;
	std::cout << "y: " << y << endl;

	return 0;
}
```
- Nhưng nó hiệu quả hơn vi khi tmp được khởi tạo, thay vì tạo một bản sao của x, chúng ta sử dụng std :: move để chuyển biến l-value x thành r-value. Vì tham số là  r-value , ngữ nghĩa di chuyển được gọi và x được chuyển vào tmp. Với một vài lần hoán đổi nữa, giá trị của biến x đã được chuyển sang y và giá trị của y đã được chuyển sang x.

```c++
#include <iostream>
#include <string>
#include <utility> // for std::move
#include <vector>

int main()
{
	std::vector<std::string> v;
	std::string str = "Knock";

	std::cout << "Copying str"<< endl;
	v.push_back(str); // gọi l-value của push_back, sao chép str vào phần tử mảng

	std::cout << "str: " << str << endl ;
	std::cout << "vector: " << v[0] << endl;

	std::cout << "\nMoving str"<< endl>;

	v.push_back(std::move(str)); // gọi l-value của push_back, sao chép str vào phần tử mảng
	std::cout << "str: " << str << endl;
	std::cout << "vector:" << v[0] << ' ' << v[1] << endl;

	return 0;
}
```
Chương trình này in:
```C++
Copying str
str: Knock
vector: Knock

Moving str
str:
vector: Knock Knock
```

- Trong trường hợp đầu tiên, dã truyền push_back () một giá trị l, vì vậy nó sử dụng ngữ nghĩa sao chép để thêm một phần tử vào vectơ. Vì lý do này, giá trị trong str được để lại một mình.

- Trong trường hợp thứ hai, đã truyền push_back () một giá trị r (thực sự là một giá trị l được chuyển đổi qua std :: move), vì vậy nó đã sử dụng ngữ nghĩa chuyển động để thêm một phần tử vào vectơ. Điều này hiệu quả hơn, vì phần tử vectơ có thể lấy cắp giá trị của chuỗi thay vì phải sao chép nó. Trong trường hợp này, str để trống.

## Kết luận
- std :: move cũng có thể hữu ích khi sắp xếp một mảng các phần tử. Nhiều thuật toán sắp xếp (chẳng hạn như sắp xếp lựa chọn và sắp xếp bong bóng) hoạt động bằng cách hoán đổi các cặp phần tử. chúng ta đã phải sử dụng đến ngữ nghĩa sao chép để thực hiện việc hoán đổi. Bây giờ chúng ta có thể sử dụng ngữ nghĩa chuyển động, hiệu quả hơn.
- Nó cũng có thể hữu ích nếu chúng ta muốn di chuyển nội dung được quản lý bởi một con trỏ thông minh sang một con trỏ thông minh khác.
- std :: move có thể được sử dụng bất cứ khi nào chúng ta muốn coi một giá trị l giống như một giá trị r nhằm mục đích gọi ra ngữ nghĩa chuyển thay vì ngữ nghĩa sao chép.


## II.STD::forward()

**1. Mục đính**
   - Trong trường hợp này, nó sẽ là một chuyển đổi thành tham chiếu R-value.
   -  Chuyển tiếp các giá trị dưới dạng giá trị hoặc dưới dạng giá trị, tùy thuộc vào kiểu dữ liệu

**2. Khi nào nên sử dụng nó?**
- Khi t là tham chiếu chuyển tiếp (đối số hàm được khai báo dưới dạng tham chiếu giá trị cho tham số mẫu hàm không đủ điều kiện ), quá tải này sẽ chuyển tiếp đối số tới một hàm khác với danh mục giá trị mà nó có khi được truyền cho hàm gọi.
```C++
template < class  T > 
void  wrapper ( T && arg )  
{ 
    // arg luôn là lvalue 
    foo ( std :: forward < T > ( arg ) ) ;  // Chuyển tiếp dưới dạng lvalue hoặc dưới dạng rvalue, tùy thuộc vào T 
}
```
- Nếu gọi đến wrapper()qua một rvalue std::string, sau đó T là để std::string(không std::string&, const std::string&hay std::string&&), và std::forward đảm bảo rằng  rvalue được truyền đến foo.
- Nếu một lệnh gọi wrapper()chuyển một giá trị const std::string, thì T sẽ được suy ra const std::string& và std::forward đảm bảo rằng một tham chiếu const lvalue được chuyển tới foo.
```c++
// forward example
#include <utility>      // std::forward
#include <iostream>     
// hàm có quá tải tham chiếu lvalue và rvalue:
void overloaded (const int& x) {std::cout << "[lvalue]";}
void overloaded (int&& x) {std::cout << "[rvalue]";}

// hàm lấy tham chiếu rvalue cho kiểu :
template <class T> void fn (T&& x) {
  overloaded (x);                   // always an lvalue
  overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
}

int main () {
  int a;

  std::cout << "calling fn with lvalue: ";
  fn (a);
  std::cout << '\n';

  std::cout << "calling fn with rvalue: ";
  fn (0);
  std::cout << '\n';

  return 0;
}
```
- Output:

```C++
calling fn with lvalue: [lvalue][lvalue]
calling fn with rvalue: [lvalue][rvalue]
```

## Kết luận
- std::move lấy một đối tượng và cho phép bạn coi nó là tạm thời (một giá trị). Mặc dù đó không phải là một yêu cầu ngữ nghĩa, thông thường, một hàm chấp nhận tham chiếu đến một giá trị sẽ làm mất hiệu lực của nó. Khi bạn nhìn thấy std::move, nó chỉ ra rằng giá trị của đối tượng không nên được sử dụng sau đó, nhưng bạn vẫn có thể gán một giá trị mới và tiếp tục sử dụng nó.

- std::forward có một trường hợp sử dụng duy nhất: để truyền tham số hàm templated (bên trong hàm) sang danh mục giá trị (lvalue hoặc rvalue) mà người gọi đã sử dụng để truyền nó. Điều này cho phép các đối số giá trị được truyền vào dưới dạng giá trị và giá trị được truyền dưới dạng giá trị, một sơ đồ gọi là "chuyển tiếp hoàn hảo".
- std :: forward là kiểu ép kiểu có điều kiện nhưng std :: move là kiểu ép kiểu không điều kiện. Các ứng dụng của chuyển tiếp hoàn hảo là std::make_shared, v.v.std::make_uniquevector::emplace_back

 ## III. Universal reference


Forwarding reference (hay còn gọi là Universal reference) 
- Loại được đề cập là một loại tham chiếu đặc biệt có thể ràng buộc mọi thứ & mọi thứ.
- universal reference có thể trở thành một R-value reference hoặc L-value  reference


Có 3 trường hợp chinh xảy ra:
1. Tham số mẫu hàm 
2. Tham chiếu chung trong tự động
3. Tham chiếu chung trong “typedef”


**1.Tham số mẫu hàm** 
 Example:

```C++template<typename T>  
void f(T&& param)  
{  
 std::cout<< __PRETTY_FUNCTION__ << std::endl;  
}
```
Việc gọi hàm 'f' theo các cách khác nhau sẽ tạo ra các kết quả khác nhau

```C++
Widget w;  
f(w);   

// Tham chiếu chuyển tiếp T && sẽ được giải quyết dưới dạng L-value Ref
// Do đó khởi tạo void f (Widget &) ra khỏi mẫu

void f(T&&) [with T = Widget&]. // Printed
```
 - Thêm const 
```C++
const Widget cw;  
f(cw);   

// Tham chiếu chuyển tiếp T && sẽ được giải quyết dưới dạng L-value. Tham chiếu đến const
// Do đó khởi tạo void f (const Widget &) ra khỏi mẫu

void f(T&&) [with T = const Widget&]. // Printed
```

- Truyền các giá trị 
```C++
 f(Widget());  

// Tham chiếu chuyển tiếp T && sẽ được giải quyết dưới dạng Rvalue Ref
// Do đó khởi tạo void f (Widget &&) ra khỏi mẫu
void f(T&&)[with T = Widget] 
```

**2. Tham chiếu chung trong tự động**

```c++
*auto&& var = 10; /// 10 là giá trị do đó var là
// một tham chiếu Universal phân giải thành một tham chiếu r-value.
``
```
- Loại var là int &&
```c++
std::vector<int> vec;  
auto&& var = vec[0]; // vector [] là int & do đó var là
// một tham chiếu Universal phân giải thành một tham chiếu L-value.
```

**3.Tham chiếu chung trong “typedef”**

```c++
template<typename T>  
class Widget  
{  
// ...  
}
Widget<int&> w;

typedef Widget&& UniRefToWodget; 

UniRefToWodget &v1 = w;   
//  tham chiếu, kiểu của v1 là Widget &

const UniRefToWodget &v2 = std::move(w);   
// tham chiếu, kiểu của v2 là const Widget &

UniRefToWodget &&v3 = std::move(w);   
//  tham chiếu, loại của v3 là Widget &&
```
