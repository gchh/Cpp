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
#if 0
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

#else
// Wrong Answer 
#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<map>
using namespace std;
int main()
{
	multimap<int, int>member;
	member.insert(multimap<int, int>::value_type(1000000000, 1));
	int newmembers, id, power, adversary;
	scanf("%d", &newmembers);//cin >> newmembers;
	for (int i = 1; i <= newmembers; ++i)
	{
		scanf("%d %d", &id, &power);//cin >> id >> power;
		pair<multimap<int, int>::iterator, multimap<int, int>::iterator>p = member.equal_range(power);
		if (p.first == p.second) //没有和power相等的元素，寻找和power相差最小的元素，作为id的对手
		{
			if (p.first == member.begin()) adversary = p.first->second; //只有一个元素
			else
			{
				//p.first和p.second指向同一个元素，其实力大于power，但是所有大于power的值中差别最小的
				--p.first; //其实力小于power，且是所有小与power的值中差别最小的
				if (abs(p.first->first - power) > abs(p.second->first - power)) //比较哪个差别更小，将其作为对手
				{
					//寻找和p.second->first相同的元素，其中id最小的作为对手
					pair<multimap<int, int>::iterator, multimap<int, int>::iterator>pp = member.equal_range(p.second->first);
					adversary = pp.first->second;
					for (; pp.first != pp.second; ++pp.first)
					{
						if (adversary > pp.first->second)
						{
							adversary = pp.first->second;
						}
					}
				}
				else if (abs(p.first->first - power) < abs(p.second->first - power))
				{
					//寻找和p.first->first相同的元素，其中id最小的作为对手
					pair<multimap<int, int>::iterator, multimap<int, int>::iterator>pp = member.equal_range(p.first->first);
					adversary = pp.first->second;
					for (; pp.first != pp.second; ++pp.first)
					{
						if (adversary > pp.first->second)
						{
							adversary = pp.first->second;
						}
					}
				}
				else  //abs(p.first->first - power) == abs(p.second->first - power)
				{
					//寻找和p.second->first相同的元素，找出其最小的id
					pair<multimap<int, int>::iterator, multimap<int, int>::iterator>pp = member.equal_range(p.second->first);
					adversary = pp.first->second;
					for (; pp.first != pp.second; ++pp.first)
					{
						if (adversary > pp.first->second)
						{
							adversary = pp.first->second;
						}
					}

					//寻找和p.first->first相同的元素，其中id最小的作为对手
					pp = member.equal_range(p.first->first);
					for (; pp.first != pp.second; ++pp.first)
					{
						if (adversary > pp.first->second)
						{
							adversary = pp.first->second;
						}
					}
				}
			}
		}
		else //有和power相等的元素
		{
			//在这些相同元素中寻找id最小的最为对手
			adversary = p.first->second;
			for (; p.first != p.second; ++p.first)
			{
				if (adversary > p.first->second)
				{
					adversary = p.first->second;
				}
			}
		}
		printf("%d %d\n", id, adversary);//cout << id << " " << adversary << endl;
		member.insert(multimap<int, int>::value_type(power, id));
	}
	return 0;
}
#endif
