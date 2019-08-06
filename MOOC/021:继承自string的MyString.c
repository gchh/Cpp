/*********************************************************************************
021:继承自string的MyString
总时间限制: 1000ms 内存限制: 65536kB 
描述
程序填空，输出指定结果
1. abcd-efgh-abcd-
2. abcd-
3. 
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-

提示
提示 1：如果将程序中所有 "MyString" 用 "string" 替换，那么除了最后两条红色的语句编译无法通过外，其他语句都没有问题，
而且输出和前面给的结果吻合。也就是说，MyString 类对 string 类的功能扩充只体现在最后两条语句上面。 

提示 2: string 类有一个成员函数 string substr(int start,int length); 能够求从 start 位置开始，长度为 length 的子串 

提示 3: C++中，派生类的对象可以赋值给基类对象，因为，一个派生类对象，也可看作是一个基类对象（大学生是学生）。
反过来则不行(学生未必是大学生） 同样，调用需要基类对象作参数的函数时，以派生类对象作为实参，也是没有问题的
*********************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class MyString:public string
{
// 在此处补充你的代码
public:
	MyString() :string(){}
	MyString(const char * s) :string(s){}
	MyString(const string & s) :string(s){}
	MyString operator()(int st, int ln)
	{
		return this->substr(st, ln);
	}
// 在此处补充你的代码
};


int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
        sort(SArray,SArray+4);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}


