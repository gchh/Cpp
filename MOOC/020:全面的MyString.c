/**************************************************************************************
020:全面的MyString
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
**************************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
	char * str;
public:
	MyString()
	{
		//str = NULL; 
		str = new char[1];
		*str = '\0';
	}
	MyString(const char * s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	MyString(const MyString & s)
	{
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
	}
	~MyString()
	{
		if (str) delete[] str;
	}
	MyString & operator=(const MyString & s)
	{
		if (str == s.str) return *this;
		if (str) delete[] str;
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
		return *this;
	}
	MyString & operator=(const char * s)
	{
		if (str) delete[] str;
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		return *this;
	}
	MyString operator+(const MyString & s)
	{
		MyString sTmp(*this);
		if (sTmp.str) delete[] sTmp.str;
		sTmp.str = new char[strlen(this->str) + strlen(s.str) + 1];
		strcpy(sTmp.str, this->str);
		strcat(sTmp.str, s.str);
		return sTmp;
	}
	MyString operator+(const char * s)
	{
		MyString sTmp(*this);
		if (sTmp.str) delete[] sTmp.str;
		sTmp.str = new char[strlen(this->str) + strlen(s) + 1];
		strcpy(sTmp.str, this->str);
		strcat(sTmp.str, s);
		return sTmp;
	}
	MyString & operator+=(const char * s)
	{
		char * tmp;
		tmp = new char[strlen(str) + 1];
		strcpy(tmp, str);
		if (str) delete[] str;
		str = new char[strlen(tmp) + strlen(s) + 1];
		strcpy(str, tmp);
		strcat(str, s); //strncat(str, s, strlen(s));
		return *this;
	}
	friend MyString operator+(const char * s, const MyString & st)
	{
		MyString ss;
		ss.str = new char[strlen(s) + strlen(st.str) + 1];
		strcpy(ss.str, s);
		strcat(ss.str, st.str); //strncat(ss.str, st.str, strlen(st.str));
		return ss;
	}	
	friend ostream & operator<<(ostream & os, const MyString & s)
	{
		os << s.str;
		return os;
	}	
	char & operator[](int i)
	{
		return str[i];
	}
	char * operator()(int st, int sp)
	{
		char * ss;
		ss = str;
		ss[st + sp] = '\0';
		return &ss[st];
	}
	friend bool operator<(const MyString & s1, const MyString & s2)
	{
		int t;
		t = strcmp(s1.str, s2.str);
		if (t < 0) return true;
		else return false;
	}	
	friend bool operator==(const MyString & s1, const MyString & s2)
	{
		int t;
		t = strcmp(s1.str, s2.str);
		if (t == 0) return true;
		else return false;
	}	
	friend bool operator>(const MyString & s1, const MyString & s2)
	{
		int t;
		t = strcmp(s1.str, s2.str);
		if (t > 0) return true;
		else return false;
	}	
// 在此处补充你的代码  
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
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
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}


