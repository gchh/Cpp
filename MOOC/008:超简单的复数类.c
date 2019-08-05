/*************************************************************************
008:超简单的复数类
总时间限制: 1000ms 内存限制: 65536kB 
描述
下面程序的输出是： 
3+4i 
5+6i 
请补足Complex类的成员函数。不能加成员变量。
**************************************************************************/


#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex() {};
#if 1    
  //输入为x+xi，x为多位数
	Complex(char * str)
	{
		char st[10];
		char * sr;
		char * si;
		char * n = NULL;
		strcpy(st, str);
		sr = strtok_r(st, "+", &n);
		si = strtok_r(NULL, "i", &n);
		r = atof(sr);
		i = atof(si);
	}    
#else  
    //要输入为x+xi，x为个位数
    Complex(char* x)
    {
        r=x[0]-'0';
        i=x[2]-'0';
    }
#endif    
// 在此处补充你的代码    
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}

