/**********************************************************************************
025:这是什么鬼delete
总时间限制: 1000ms 内存限制: 65536kB 
描述
程序填空输出指定结果

destructor B
destructor A
**********************************************************************************/

#include <iostream> 
using namespace std;
class A 
{ 
public:
	A() { }
// 在此处补充你的代码
virtual ~A()
{
     cout<<"destructor A"<<endl;
}
// 在此处补充你的代码
}; 
class B:public A { 
	public: 
	~B() { cout << "destructor B" << endl; } 
}; 
int main() 
{ 
	A * pa; 
	pa = new B; 
	delete pa; 
	return 0;
}
