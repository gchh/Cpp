/*******************************************************************************************
031:山寨版istream_iterator
总时间限制: 1000ms 内存限制: 65536kB 
描述
模仿C++标准模板库istream_iterator用法，实现CMyistream_iterator使得程序按要求输出 

输入
第一行是整数t，表示有t组数据
每组数据一行，三个整数加两个字符串。字符串是不含空格的

输出
对每组数据，输出二行 
在第一行输出第一个数
第二行原样输出输入的内容

样例输入
2
79 90 20 hello me
12 34 19 take up

样例输出
79
79 90 20 hello me
12
12 34 19 take up

提示
C++标准模板库 istream_iterator模版使用说明：

其构造函数执行过程中就会要求输入，然后每次执行++，则读取输入流中的下一个项目，执行 * 则返回上次从输入流中读取的项目。例如，下面程序运行时，就会等待用户输入数据，输入数据后程序才会结束：
#include <iostream>
#include <iterator>
using namespace std;
int main() { 
	istream_iterator<int>inputInt(cin);
	return 0; 
}

下面程序运行时，如果输入 12 34 程序输出结果是： 12,12
#include <iostream>
#include <iterator>
using namespace std;
int main() { 
	istream_iterator<int>inputInt(cin);
	cout << *inputInt << "," << *inputInt << endl;
	return 0; 
}

下面程序运行时，如果输入 12 34 56程序输出结果是： 12,56
#include <iostream>
#include <iterator>
using namespace std;
int main() { 
	istream_iterator<int>inputInt(cin);
	cout << *inputInt << ",";
	inputInt++;
	inputInt++;
	cout << *inputInt << endl;
	return 0; 
}

下面的程序，输入什么，按回车后，就输出什么；按ctrl+z结束
#include <iostream>
#include <iterator>
using namespace std;
int main() { 
	istream_iterator<int>inputInt(cin),eof;
	while(inputInt!=eof)
	{
		cout << *inputInt << ",";
		inputInt++;
	}
	cout<<endl;
	return 0; 
}
*************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;
template <class T>
class CMyistream_iterator
{
	// 在此处补充你的代码
	istream& in;
	T value;
public:
	CMyistream_iterator(istream& i) :in(i){ cin >> value; }
	T operator*(){ return value; }
	CMyistream_iterator& operator++(int) //后缀++
	{
		CMyistream_iterator<T>tmp = *this;
		cin >> value;
		return tmp;
	}
	CMyistream_iterator& operator++() //前缀++
	{
		cin >> value;
		return *this;
	}
	// 在此处补充你的代码
};
int main()
{
	int t;
	cin >> t;
	while (t--) {
		CMyistream_iterator<int>inputInt(cin);
		int n1, n2, n3;
		n1 = *inputInt; //读入 n1
		int tmp = *inputInt;
		cout << tmp << endl;
		inputInt++;
		n2 = *inputInt; //读入 n2
		inputInt++;
		n3 = *inputInt; //读入 n3
		cout << n1 << " " << n2 << " " << n3 << " ";
		CMyistream_iterator<string> inputStr(cin);
		string s1, s2;
		s1 = *inputStr;
		inputStr++;
		s2 = *inputStr;
		cout << s1 << " " << s2 << endl;
	}
	return 0;
}
