/***********************************************************************
018:别叫，这个大整数已经很简化了!

输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
输出
对每组数据，输出6行，内容分别是：

样例输入
99999999999999999999999999888888888888888812345678901234567789 12
6 6

样例输出
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
***********************************************************************/
/************************************dev c++****************************************/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt{
private:
	char buf[220];//固定一个220位大小的数组，便于进行对齐
public:
	void reverse(char *p)//将存储数据的数组进行逆序操作，符合竖式计算从低位向高位进行的原理
	{
		int len = strlen(p);
		int i = 0, j = len - 1;
		while (i < j)
		{
			swap(p[i], p[j]);
			++i;
			--j;
		}
	}
	CHugeInt(char *p)
	{
		memset(buf, 0, sizeof(buf));//将buf初始化
		strcpy(buf, p);
		reverse(buf);
	}
	CHugeInt(int n)
	{
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d", n);
		reverse(buf);
	}
	CHugeInt operator+(int n)
	{
		return *this + CHugeInt(n);//可以直接利用后面写的重载运算符	
	}
	CHugeInt operator+(const CHugeInt & n)
	{
		CHugeInt tmp(0);
		int carry = 0;//进位
		for (int i = 0; i < 210; i++)
		{
			char c1 = buf[i];
			char c2 = n.buf[i];
			if (c1 == 0 && c2 == 0 && carry == 0)break;
			if (c1 == 0)c1 = '0';
			if (c2 == 0)c2 = '0';
			int k = c1 - '0' + c2 - '0' + carry;
			if (k >= 10)//相加大于10则进位
			{
				carry = 1;//进位置1
				tmp.buf[i] = k - 10 + '0';
			}
			else
			{
				carry = 0;
				tmp.buf[i] = k + '0';
			}
		}
		return tmp;
	}
	friend CHugeInt operator+(int n, CHugeInt & h)
	{
		return h + n;
	}
	friend ostream & operator<<(ostream & os, const CHugeInt & h)
	{
		int len = strlen(h.buf);
		for (int i = len - 1; i >= 0; i--)
		{
			cout << h.buf[i];
		}
		return os;
	}
	CHugeInt & operator++()
	{
		*this = *this + 1;
		return *this;
	}
	CHugeInt operator++(int)
	{
		CHugeInt tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	CHugeInt & operator+=(int n)
	{
		*this = *this + n;
		return *this;
	}
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n)
	{
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
/*********************************visual studio 2013**********************************/
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt{
private:
	char buf[220];//固定一个220位大小的数组，便于进行对齐
public:
	void reverse(char *p)//将存储数据的数组进行逆序操作，符合竖式计算从低位向高位进行的原理
	{
		int len = strlen(p);
		int i = 0, j = len - 1;
		while (i < j)
		{
			swap(p[i], p[j]);
			++i;
			--j;
		}
	}
	CHugeInt(char *p)
	{
		memset(buf, 0, sizeof(buf));//将buf初始化
		//strcpy_s(buf, sizeof(buf), p); //strcpy(buf, p);
		/*不能使用strcpy_s(buf, sizeof(buf), p)来拷贝，因为经过memset将buf所有元素设为0后，
		使用strcpy_s(buf, sizeof(buf), p)来复制p的内容，调试发现应该保持为0的元素都变成了-2，
		导致后面+运算错误。改为使用strcpy_s(buf, strlen(p)+1, p)，后正确。*/
		strcpy_s(buf, strlen(p) + 1, p);//只拷贝p长度内的字符
		reverse(buf);
	}
	CHugeInt(int n)
	{
		memset(buf, 0, sizeof(buf));
		//sprintf_s(buf, sizeof(buf), "%d", n); //sprintf(buf, "%d", n);
		/*使用sprintf_s(buf, sizeof(buf), "%d", n)和使用strcpy_s(buf, sizeof(buf), p)有同样的问题。*/
#if 0
		char t[11];
		sprintf_s(t, sizeof(t), "%d", n);//执行该语句后，strlen(t)正好是n的位数
		strcpy_s(buf, strlen(t) + 1, t);//只拷贝n位数内的字符
#else
		int intlen = 0, t = n;
		while (t)
		{
			t /= 10;
			intlen++; //n是几位数
		}
		if (intlen>0) sprintf_s(buf, intlen+1, "%d", n); //intlen=0,即n=0,保持buf初始化即可，不需要执行sprintf_s。
#endif
		reverse(buf);
	}
	CHugeInt operator+(int n)
	{
		return *this + CHugeInt(n);//可以直接利用后面写的重载运算符	
	}
	CHugeInt operator+(const CHugeInt & n)
	{
		CHugeInt tmp(0);
		int carry = 0;//进位
		int i;
		for (i = 0; i < 210; i++)
		{
			char c1 = buf[i];
			char c2 = n.buf[i];
			if (c1 == 0 && c2 == 0 && carry == 0)break;
			if (c1 == 0)c1 = '0';
			if (c2 == 0)c2 = '0';
			int k = c1 - '0' + c2 - '0' + carry;
			if (k >= 10)//相加大于10则进位
			{
				carry = 1;//进位置1
				tmp.buf[i] = k - 10 + '0';
			}
			else
			{
				carry = 0;
				tmp.buf[i] = k + '0';
			}
		}
		return tmp;
	}
	friend CHugeInt operator+(int n, CHugeInt & h)
	{
		return h + n;
	}
	friend ostream & operator<<(ostream & os, const CHugeInt & h)
	{
		int len = strlen(h.buf);
		for (int i = len - 1; i >= 0; i--)
		{
			cout << h.buf[i];
		}
		return os;
	}
	CHugeInt & operator++()
	{
		*this = *this + 1;
		return *this;
	}
	CHugeInt operator++(int)
	{
		CHugeInt tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	CHugeInt & operator+=(int n)
	{
		*this = *this + n;
		return *this;
	}
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n)
	{
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
