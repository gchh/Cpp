/**********************************************************************
005:编程填空：学生信息处理程序
总时间限制: 1000ms 内存限制: 1024kB 
描述
实现一个学生信息处理程序，计算一个学生的四年平均成绩。
要求实现一个代表学生的类，并且类中所有成员变量都是【私有的】。
补充下列程序中的 Student 类以实现上述功能。

输入
输入数据为一行，包括：
姓名,年龄,学号,第一学年平均成绩,第二学年平均成绩,第三学年平均成绩,第四学年平均成绩。
其中姓名为由字母和空格组成的字符串（输入保证姓名不超过20个字符，并且空格不会出现在字符串两端），年龄、学号和学年平均成绩均为非负整数。信息之间用逗号隔开。

输出
输出一行数据，包括：
姓名,年龄,学号,四年平均成绩。
信息之间用逗号隔开。

样例输入
Tom Hanks,18,7817,80,80,90,70

样例输出
Tom Hanks,18,7817,80

提示
必须用类实现，其中所有成员变量都是私有的。
输出结果中，四年平均成绩不一定为整数。
************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// 在此处补充你的代码
private:
	char name[21];
	int age;
	int id;
	int avg[4];
	float average;
public:
	void input()
	{
		int i;
		cin.getline(name, 20, ',');
		cin >> age;
		if (cin.get() == ',')
			cin >> id;
		for (i = 0; i < 4; i++)
		{
			if (cin.get() == ',')
				cin >> avg[i];
		}
	}
	void calculate()
	{
		int i;
		average = 0;
		for (i = 0; i < 4; i++)
		{
				average += avg[i];
		}
		average /= 4;
	}
	void output()
	{
		cout << name <<"," << age <<"," << id <<"," << average;
	}
// 在此处补充你的代码  
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
