/*********************************************************************************************
039:我自己的 ostream_iterator
总时间限制: 1000ms 内存限制: 65536kB 
描述
程序填空输出指定结果

输入
无
输出
5,21,14,2,3,
1.4--5.56--3.2--98.3--3.3--
**********************************************************************************************/
#include <iostream>
#include <list>
#include <string>
using namespace std;
template <class T1, class T2>
void Copy(T1 s, T1 e, T2 x)
{
	for (; s != e; ++s, ++x)
		*x = *s;
}
template<class T>
class myostream_iteraotr
{
	// 在此处补充你的代码
	string sep;
	ostream& os;
public:
	myostream_iteraotr(ostream& o, string s) :os(o), sep(s)	{}
	void operator++(){}
#if 1
	void operator = (T& s)
	{
		os << s << sep;
	}
#else
	myostream_iteraotr& operator = (T& s)
	{
		os << s << sep;
		return *this;
	}
#endif
	myostream_iteraotr& operator * ()
	{
		return *this;
	}
	// 在此处补充你的代码
};
int main()
{
	const int SIZE = 5;
	int a[SIZE] = { 5, 21, 14, 2, 3 };
	double b[SIZE] = { 1.4, 5.56, 3.2, 98.3, 3.3 };
	list<int> lst(a, a + SIZE);
	myostream_iteraotr<int> output(cout, ",");
	Copy(lst.begin(), lst.end(), output);
	cout << endl;
	myostream_iteraotr<double> output2(cout, "--");
	Copy(b, b + SIZE, output2);
	return 0;
}


