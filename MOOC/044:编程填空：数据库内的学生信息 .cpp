/***************************************************************************************************
044:编程填空：数据库内的学生信息
总时间限制: 3000ms 内存限制: 20480kB 

描述

程序填空，使得下面的程序,先输出
(Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
(Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
(70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
(70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
******
然后，再根据输入数据按要求产生输出数据

输入
输入数据的每一行，格式为以下之一：
A name score
Q name score

name是个不带个空格的字符串，长度小于 20
score是个整数，能用int表示
A name score 表示往数据库中新增一个姓名为name的学生，其分数为score。开始时数据库中一个学生也没有。
Q name 表示在数据库中查询姓名为name的学生的分数
数据保证学生不重名。
输入数据少于200,000行。

输出
对于每个查询，输出学生的分数。如果查不到，则输出 "Not Found"

样例输入
A Tom1 30
A Tom2 40
Q Tom3 
A Tom4 89
Q Tom1
Q Tom2

样例输出
(Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
(Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
(70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
(70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
******
Not Found
30
40

提示
1) 编写模板的时候，连续的两个 “>”最好要用空格分开，以免被编译器看作是 ">>"运算符。VS可能无此问题，但是Dev C++和服务器上的编译环境会有这个问题。
比如 vector<vector<int>> 有可能出错，要改成 vector<vector<int> >

2) 在模板中写迭代器时，最好在前面加上 typename关键字，否则可能会编译错。VS可能无此问题，但是Dev C++和服务器上的编译环境会有这个问题。
***************************************************************************************************/
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
#if 0
#include<functional>
template<class Key,class T, class Pred=greater<Key>>
#else
template <class Key>
class cmp {
public:
	bool operator ()(const Key&a, const Key& b)const 
	{
		return a > b;
	}
};
template<class Key, class T, class Pred = cmp<Key>>
#endif
class MyMultimap{
public:
	typedef multimap<Key, T, Pred> mmp;
	typedef typename multimap<Key, T>::iterator iterator;
	mmp mp;
	iterator insert(pair<Key, T> a)
	{
		return mp.insert(a);
	}
	iterator begin() 
	{
		return mp.begin();
	}
	iterator end() 
	{
		return mp.end();
	}
	void Set(Key k, T t)
	{
		pair<iterator, iterator>range = mp.equal_range(k);
		for (; range.first != range.second; ++range.first)
		{
			range.first->second = t;
		}
	}
	iterator find(Key n) 
	{
		return mp.find(n);
	}
	void clear() 
	{
		mp.clear();
	}
};
template<class Key, class T>
ostream& operator<<(ostream&os, pair<Key, T> m)
{
	os << "(" << m.first << "," << m.second << ")";
	return os;
}
// 在此处补充你的代码
struct Student
{
	string name;
	int score;
};
template <class T>
void Print(T first, T last) 
{
	for (; first != last; ++first)
		cout << *first << ",";
	cout << endl;
}
int main()
{
	Student s[] = { { "Tom", 80 }, { "Jack", 70 }, { "Jone", 90 }, { "Tom", 70 }, { "Alice", 100 } };

	MyMultimap<string, int> mp;
	for (int i = 0; i<5; ++i)
		mp.insert(make_pair(s[i].name, s[i].score));
	Print(mp.begin(), mp.end()); //按姓名从大到小输出

	mp.Set("Tom", 78); //把所有名为"Tom"的学生的成绩都设置为78
	Print(mp.begin(), mp.end());

	MyMultimap<int, string, less<int> > mp2;
	for (int i = 0; i<5; ++i)
		mp2.insert(make_pair(s[i].score, s[i].name));

	Print(mp2.begin(), mp2.end()); //按成绩从小到大输出
	mp2.Set(70, "Error");          //把所有成绩为70的学生，名字都改为"Error"
	Print(mp2.begin(), mp2.end());
	cout << "******" << endl;

	mp.clear();

	string name;
	string cmd;
	int score;
	while (cin >> cmd) 
	{
		if (cmd == "A") 
		{
			cin >> name >> score;
			if (mp.find(name) != mp.end()) 
			{
				cout << "erroe" << endl;
			}
			mp.insert(make_pair(name, score));
		}
		else if (cmd == "Q") 
		{
			cin >> name;
			MyMultimap<string, int>::iterator p = mp.find(name);
			if (p != mp.end()) 
			{
				cout << p->second << endl;
			}
			else 
			{
				cout << "Not Found" << endl;
			}
		}
	}
	return 0;
}


