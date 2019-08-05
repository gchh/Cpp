/******************************************************************************
001:简单的swap
总时间限制: 1000ms 内存限制: 65536kB 
描述
填空，使得程序输出结果是： 
5,3
********************************************************************************/

#include <iostream>
using namespace std;
class A
{
	public:
	int x;
	int getX() { return x; }	
};
void swap(
A & a, A & b
)
{
	int  tmp = a.x;
	a.x = b.x;
	b.x = tmp;
}
int main()
{
	A a,b;
	a.x = 3;
	b.x = 5;
	swap(a,b);
	cout << a.getX() << "," << b.getX();
	return 0;
}
