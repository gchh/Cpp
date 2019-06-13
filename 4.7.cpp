/**************************************************************************************************
第四章  运算符重载
习题
7．编写一个Mystring类，使得程序的输出结果是
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
**************************************************************************************************/
/***********************************DEV C++*******************************************/
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class MyString{
	char * str;
public:
	MyString()
	{ 
		//str=NULL; 不能这样，否则，会导致cout<<s2无法输出，导致错误。 
		str=new char[1];
		*str='\0';
	}
	MyString(const char * s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	MyString(const MyString & s)
	{
		str = new char[strlen(s.str)+1];
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
		str = new char[strlen(s.str)+1];
		strcpy(str, s.str);
		return *this;
	}
	MyString & operator=(const char * s)
	{
	#if 0
		if (str) delete[] str;
		str = new char[strlen(s)+1];
		strcpy(str, s);
	#else  //简化
		*this = MyString(s);
	#endif
		return *this;
	}
	//+重载函数不能返回MyString &引用，否则，s1+s3或s1+"dddd"会导致s1的内容改变，而这不是我们想要的。 
	MyString operator+(const MyString & s)
	{
		MyString sTmp(*this);
		if (sTmp.str) delete[] sTmp.str;
		sTmp.str = new char[strlen(this->str) + strlen(s.str)+1];
		strcpy(sTmp.str, this->str);
		strcat(sTmp.str, s.str);
		return sTmp;
	}
	MyString operator+(const char * s)
	{
	#if 0
		MyString sTmp(*this);
		if (sTmp.str) delete[] sTmp.str;
		sTmp.str = new char[strlen(this->str) + strlen(s)+1];
		strcpy(sTmp.str, this->str);
		strcat(sTmp.str, s);
		return sTmp;
	#else  //简化
		return *this+ MyString(s);
	#endif
	}
	MyString & operator+=(const char * s)
	{
	#if 0
		char * tmp;
		tmp = new char[strlen(str) + 1];
		strcpy(tmp, str);
		if (str) delete[] str;
		str = new char[strlen(tmp) + strlen(s)+1];
		strcpy(str, tmp);
		strcat(str, s);
	#else  //简化
		*this = *this + MyString(s);
	#endif
		return *this;
	}
	friend MyString operator+(const char * s, const MyString & st);
	friend ostream & operator<<(ostream & os, const MyString & s);
	//返回引用，可以作为左值，修改其值，例如 s1[2] = 'A';
	char & operator[](int i)
	{
		return str[i];
	}
	char * operator()(int st, int sp)
	{
		char * ss;
		ss = str;
		ss[st+sp] = '\0';
		return &ss[st];
	}
	friend bool operator<(const MyString & s1, const MyString & s2);
	friend bool operator==(const MyString & s1, const MyString & s2);
	friend bool operator>(const MyString & s1, const MyString & s2);	
};
MyString operator+(const char * s, const MyString & st)
{
#if 0
	MyString ss;
	ss.str = new char[strlen(s) + strlen(st.str)+1];
	strcpy(ss.str, s);
	strcat(ss.str, st.str);
	return ss;
#else
	return st+MyString(s);
#endif
}
ostream & operator<<(ostream & os, const MyString & s)
{
	os << s.str;
	return os;
}
bool operator<(const MyString & s1, const MyString & s2)
{
	int t;
	t = strcmp(s1.str, s2.str);
	if (t < 0) return true;
	else return false;
}
bool operator==(const MyString & s1, const MyString & s2)
{
	int t;
	t = strcmp(s1.str, s2.str);
	if (t == 0) return true;
	else return false;
}
bool operator>(const MyString & s1, const MyString & s2)
{
	int t;
	t = strcmp(s1.str, s2.str);
	if (t > 0) return true;
	else return false;
}
int CompareString(const void *e1, const void *e2)
{
	MyString *s1 = (MyString *)e1;
	MyString *s2 = (MyString *)e2;
	if (*s1 < *s2) return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;
}
int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big", "me", "about", "take" };
	cout << "1." << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2." << s1 << endl;
	cout << "3." << s2 << endl;
	cout << "4." << s3 << endl;
	cout << "5." << s4 << endl;
	cout << "6." << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7." << s2 << endl;
	cout << "8." << s1 << endl;
	s1 += "mnop";
	cout << "9." << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10." << s4 << endl;
	s1 = s2 + s4 + "uvw" + "xyz";
	cout << "11." << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	//输出s1从下标为0开始长度为4的字串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的字串
	cout << s1(5, 10) << endl;
	return 0;
}
/*********************************visual studio 2013**************************************************/
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class MyString{
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
		strcpy_s(str, strlen(s)+1, s);// strcpy(str, s);
	}
	MyString(const MyString & s)
	{
		str = new char[strlen(s.str)+1];
		strcpy_s(str, strlen(s.str)+1, s.str);//strcpy(str, s.str);
	}
	~MyString()
	{
		if (str) delete[] str;
	}
	MyString & operator=(const MyString & s)
	{
		if (str == s.str) return *this;
		if (str) delete[] str;
		str = new char[strlen(s.str)+1];
		strcpy_s(str, strlen(s.str)+1, s.str);//strcpy(str, s.str);
		return *this;
	}
	MyString & operator=(const char * s)
	{
	#if 0
		if (str) delete[] str;
		str = new char[strlen(s)+1];
		strcpy_s(str, strlen(s)+1, s);//strcpy(str, s);
		return *this;
	#else
		return *this = MyString(s);
	#endif
	}
	MyString operator+(const MyString & s)
	{
		MyString sTmp(*this);
		if (sTmp.str) delete[] sTmp.str;
		sTmp.str = new char[strlen(this->str) + strlen(s.str) + 1];
		strcpy_s(sTmp.str, strlen(this->str) + 1, this->str);//strcpy(sTmp.str, this->str);
		strcat_s(sTmp.str, strlen(this->str) + strlen(s.str) + 1, s.str); //strcat(sTmp.str, s.str);
		return sTmp;
	}
	MyString operator+(const char * s)
	{
	#if 0
		MyString sTmp(*this);
		if (sTmp.str) delete[] sTmp.str;
		sTmp.str = new char[strlen(this->str) + strlen(s) + 1];
		strcpy_s(sTmp.str, strlen(this->str) + 1, this->str);//strcpy(sTmp.str, this->str);
		strcat_s(sTmp.str, strlen(this->str) + strlen(s) + 1, s); //strcat(sTmp.str, s);
		return sTmp;
	#else
		return *this + MyString(s);
	#endif
	}
	MyString & operator+=(const char * s)
	{
	#if 0
		char * tmp;
		tmp = new char[strlen(str) + 1];
		strcpy_s(tmp, strlen(str) + 1, str);//strcpy(tmp, str);
		if (str) delete[] str;
		str = new char[strlen(tmp) + strlen(s)+1];
		strcpy_s(str, strlen(tmp)+1, tmp);//strcpy(str, tmp);
		strcat_s(str, strlen(str) + strlen(s)+1, s); //strcat(str, s); //strncat(str, s, strlen(s));
		return *this;
	#else
		return *this = *this + MyString(s);
	#endif
	}
	friend MyString operator+(const char * s, const MyString & st);
	friend ostream & operator<<(ostream & os, const MyString & s);
	char & operator[](int i)
	{
		return str[i];
	}
	char * operator()(int st, int sp)
	{
		char * ss;
		ss = str;
		ss[st+sp] = '\0';
		return &ss[st];
	}
	friend bool operator<(const MyString & s1, const MyString & s2);
	friend bool operator==(const MyString & s1, const MyString & s2);
	friend bool operator>(const MyString & s1, const MyString & s2);
};
MyString operator+(const char * s, const MyString & st)
{
#if 0
	MyString ss;
	ss.str = new char[strlen(s) + strlen(st.str)+1];
	strcpy_s(ss.str, strlen(s)+1, s);//strcpy(ss.str, s);
	strcat_s(ss.str, strlen(ss.str) + strlen(st.str)+1, st.str); //strcat(ss.str, st.str); //strncat(ss.str, st.str, strlen(st.str));
	return ss;
#else
	return st + MyString(s);
#endif
}
ostream & operator<<(ostream & os, const MyString & s)
{
	os << s.str;
	return os;
}
bool operator<(const MyString & s1, const MyString & s2)
{
	int t;
	t = strcmp(s1.str, s2.str);
	if (t < 0) return true;
	else return false;
}
bool operator==(const MyString & s1, const MyString & s2)
{
	int t;
	t = strcmp(s1.str, s2.str);
	if (t == 0) return true;
	else return false;
}
bool operator>(const MyString & s1, const MyString & s2)
{
	int t;
	t = strcmp(s1.str, s2.str);
	if (t > 0) return true;
	else return false;
}
int CompareString(const void *e1, const void *e2)
{
	MyString *s1 = (MyString *)e1;
	MyString *s2 = (MyString *)e2;
	if (*s1 < *s2) return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;
}
int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big", "me", "about", "take" };
	cout << "1." << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2." << s1 << endl;
	cout << "3." << s2 << endl;
	cout << "4." << s3 << endl;
	cout << "5." << s4 << endl;
	cout << "6." << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7." << s2 << endl;
	cout << "8." << s1 << endl;
	s1 += "mnop";
	cout << "9." << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10." << s4 << endl;
	s1 = s2 + s4 + "uvw" + "xyz";
	cout << "11." << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	//输出s1从下标为0开始长度为4的字串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的字串
	cout << s1(5, 10) << endl;
	return 0;
}
/******************************************使用string类，复合关系(封闭类)：DEV C++/visual studio***********************************************/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
class MyString{
	string str; //封闭类
public:
	MyString(){ }
	MyString(const char * s)
	{
		str = s;
	}
	MyString(const MyString & s)
	{
		str = s.str;
	}
	MyString & operator=(const MyString & s)
	{
		str.assign(s.str, 0, s.str.length() + 1);
		return *this;
	}
	MyString & operator=(const char * s)
	{
		str.assign(s);
		return *this;
	}
	MyString operator+(const MyString & s)
	{
		MyString sTmp(*this);
		sTmp.str += s.str;
		return sTmp;
	}
	MyString operator+(const char * s)
	{
		MyString sTmp(*this);
		sTmp.str += s;
		return sTmp;
	}
	MyString & operator+=(const char * s)
	{
		str += s;
		return *this;
	}
	friend MyString operator+(const char * s, const MyString & st);
	friend ostream & operator<<(ostream & os, const MyString & s);
	char & operator[](int i)
	{
		return str[i];
	}
	string operator()(int st, int sp)	
	{
		return str.substr(st, sp);
	}
	bool operator<(const MyString & s)
	{
		if (str.compare(s.str)<0) return true;
		else return false;
	}
	bool operator==(const MyString & s)
	{
		if (str.compare(s.str)==0) return true;
		else return false;
	}
	bool operator>(const MyString & s)
	{
		if (str.compare(s.str)>0) return true;
		else return false;
	}
};
MyString operator+(const char * s, const MyString & st)
{
	MyString ss;
	ss.str.assign(s);
	ss.str += st.str;
	return ss;
}
ostream & operator<<(ostream & os, const MyString & s)
{
	os << s.str;
	return os;
}

int CompareString(const void *e1, const void *e2)
{
	MyString *s1 = (MyString *)e1;
	MyString *s2 = (MyString *)e2;
	if (*s1 < *s2) return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;
}
int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big", "me", "about", "take" };
	cout << "1." << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2." << s1 << endl;
	cout << "3." << s2 << endl;
	cout << "4." << s3 << endl;
	cout << "5." << s4 << endl;
	cout << "6." << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7." << s2 << endl;
	cout << "8." << s1 << endl;
	s1 += "mnop";
	cout << "9." << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10." << s4 << endl;
	s1 = s2 + s4 + "uvw" + "xyz";
	cout << "11." << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	//输出s1从下标为0开始长度为4的字串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的字串
	cout << s1(5, 10) << endl;
	return 0;
}
/******************************************继承string类：DEV C++/visual studio******/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
class MyString : public string {
public:
	MyString() :string() {};
	MyString(const char * s) :string(s){};
	MyString(const string & s) : string(s){};
	MyString operator() (int s, int l) 
	{
		return this->substr(s, l);
	}
};
int CompareString(const void *e1, const void *e2)
{
	MyString *s1 = (MyString *)e1;
	MyString *s2 = (MyString *)e2;
	if (*s1 < *s2) return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;
}
int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big", "me", "about", "take" };
	cout << "1." << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2." << s1 << endl;
	cout << "3." << s2 << endl;
	cout << "4." << s3 << endl;
	cout << "5." << s4 << endl;
	cout << "6." << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7." << s2 << endl;
	cout << "8." << s1 << endl;
	s1 += "mnop";
	cout << "9." << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10." << s4 << endl;
	s1 = s2 + s4 + "uvw" + "xyz";
	cout << "11." << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	//输出s1从下标为0开始长度为4的字串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的字串
	cout << s1(5, 10) << endl;
	return 0;
}
/******************************重载string相关的函数：DEV C++*************************************/
/*
visual studio 报错误：
error C2556: “void strcpy(char *,const char *)”: 重载函数与“char *strcpy(char *,const char *)”只是在返回类型上不同
error C2556: “void strcat(char *,const char *)”: 重载函数与“char *strcat(char *,const char *)”只是在返回类型上不同
error C2556: “int strlen(const char *)”: 重载函数与“size_t strlen(const char *)”只是在返回类型上不同
*/
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
class MyString{
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
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; i++)
		cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}
