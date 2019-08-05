/*******************************************************************************
006:奇怪的类复制
总时间限制: 1000ms 内存限制: 65536kB 
描述
程序填空，使其输出9 22 5
*******************************************************************************/

#include <iostream>
using namespace std;
class Sample {
public:
	int v;
// 在此处补充你的代码  
	Sample(){}
	Sample(int x) :v(x){}
	Sample(const Sample & x)
	{
		v = x.v + 2;
	}
// 在此处补充你的代码  
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}
