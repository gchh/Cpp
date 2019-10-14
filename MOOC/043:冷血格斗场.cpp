/***********************************************************************************************
043:冷血格斗场
总时间限制: 1000ms 内存限制: 65536kB 

描述
为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家冷血格斗场。
格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。
我们假设格斗的实力可以用一个正整数表示，成为实力值，两人的实力值可以相同。另外，每个人都有一个唯一的id，也是一个正整数。
为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，
如果有多个人的实力值与他差别相同，则他会选择id最小的那个。
不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。
现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

输入
第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。
以后n行每一行两个数，按照入会的时间给出会员的id和实力值。
一开始，facer就算是会员，id为1，实力值1000000000。

输出
N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

样例输入
3
2 3
3 1
4 2

样例输出
2 1
3 2
4 2

***********************************************************************************************/
// Time Limit Exceeded 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	map<int, int>Members;
	int newmembers,id,power;
	Members.insert(map<int, int>::value_type(1, 1000000000));
	scanf("%d", &newmembers);//cin >> newmembers;
	for (int i = 1; i <= newmembers; i++)
	{
		scanf("%d %d", &id,&power);//cin >> id >> power;
		map<int, int>::iterator p = Members.begin();
		int base = abs(p->second - power);
		map<int, int>::iterator q = p;
		for (; p != Members.end(); ++p)
		{
			if (base > abs(p->second - power))
			{
				base = abs(p->second - power);
				q = p;
			}
			else if (base == abs(p->second - power) && q->first > p->first) //power > p->second)
			{
				base = abs(p->second - power);
				q = p;
			}
		}
		printf("%d %d\n", id, q->first);//cout << id << " " << q->first << endl;
		Members.insert(map<int, int>::value_type(id, power));
	}
	return 0;
}

