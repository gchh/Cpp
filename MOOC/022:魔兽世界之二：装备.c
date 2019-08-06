/*************************************************************************************
022:魔兽世界之二：装备
总时间限制: 1000ms 内存限制: 65536kB 
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。 

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。 
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。 

不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。 

在每个整点，双方的司令部中各有一个武士降生。 

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。 

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。 

制造武士需要生命元。 

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。 

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下： 

1) 武士降生 
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninja，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninja降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士

输出事件时： 
首先按时间顺序输出； 
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。
每组测试数据共两行。 
第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000) 
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始 
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
*************************************************************************************/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
string Weapon[3]={"sword","bomb","arrow"};
class Headquarter{
private:
	string headquarterName;//司令部的名称
	int elements;//司令部里的生命元
	int counts;//制造的战士总数
	string warriorNames[5];//每种战士的名称
	int warriorStrength[5];//每种战士的生命值
	int warriorCounts[5];//每种战士的数量
	int time;//制造战士的次数
	void productWarrior();//某次制造的战士
public:
	Headquarter(string headquarter, int element, string name[], int strength[]);//构造函数，用来初始化
	int dispatchWarrior();//制造士兵
};

Headquarter::Headquarter(string headquarter, int element, string name[], int strength[])
{
	int i, order[5];
	counts = 0;
	time = 0;
	headquarterName = headquarter;
	elements = element;
	if (headquarterName == "red")//红方司令部
	{//制造战士的顺序
		order[0] = 2;
		order[1] = 3;
		order[2] = 4;
		order[3] = 1;
		order[4] = 0;
	}
	else//蓝方司令部
	{//制造战士的顺序
		order[0] = 3;
		order[1] = 0;
		order[2] = 1;
		order[3] = 2;
		order[4] = 4;
	}
	for (i = 0; i < 5; i++)
	{
		warriorCounts[i] = 0;
		warriorNames[i] = name[order[i]];
		warriorStrength[i] = strength[order[i]];
	}
}

void Headquarter::productWarrior()
{
	warriorCounts[time % 5]++;
	elements -= warriorStrength[time % 5];

	cout << setfill('0') << setw(3) << counts << " " << headquarterName << " " << warriorNames[time % 5] << " "
		<< (counts + 1) << " born with strength " << warriorStrength[time % 5] << ","
		<< warriorCounts[time % 5] << " " << warriorNames[time % 5] << " in "
		<< headquarterName << " headquarter" << endl;
	counts++;
	if (warriorNames[time % 5]=="dragon")
	{
		cout << "It has a " << Weapon[counts % 3] << ",and it's morale is " << fixed<< setprecision(2) << float(elements) / warriorStrength[time % 5] << endl;
	}
	if (warriorNames[time % 5] == "ninja")
	{
		cout << "It has a " << Weapon[counts % 3] << " and a " << Weapon[(counts+1) % 3] << endl;
	}
	if (warriorNames[time % 5] == "iceman")
	{
		cout << "It has a " << Weapon[counts % 3] << endl;
	}
	if (warriorNames[time % 5] == "lion")
	{
		cout << "It's loyalty is " << elements << endl;
	}
	time++;
	//counts++;
}

int Headquarter::dispatchWarrior()
{
	int i, flag_dispatchWarrior = 1, record_time;
	if (elements >= warriorStrength[time % 5])//能够按顺序制造战士
	{
		productWarrior();
	}
	else//无法按顺序制造战士
	{
		record_time = time;
		for (i = (record_time % 5) + 1; i < 5; i++)//判断司令部剩余的生命元是否足够制造战士
		{
			time++;
			if (elements >= warriorStrength[i]) break;
		}
		if (i == 5)
		{
			for (i = 0; i < (record_time % 5); i++)//判断司令部剩余的生命元是否足够制造战士
			{
				time++;
				if (elements >= warriorStrength[i]) break;
			}
		}
		if (i == (record_time % 5)) flag_dispatchWarrior = 0;

		if (flag_dispatchWarrior == 0)
		{
			//cout << counts <<"-"<< time << endl;
			cout << setfill('0') << setw(3) << counts << " " << headquarterName << " headquarter stops making warriors" << endl;
		}
		else//继续制造战士
		{
			//cout << ">>";
			productWarrior();
		}
	}
	return flag_dispatchWarrior;
}

int main()
{
	string name[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
	int cases, element, strength[5], flag_red, flag_blue;
	int case_cnt = 0;
	cin >> cases;
	while (cases)
	{
		cases--;
		case_cnt++;
		flag_red = 1;
		flag_blue = 1;

		cin >> element >> strength[0] >> strength[1] >> strength[2] >> strength[3] >> strength[4];
		Headquarter red("red", element, name, strength);
		Headquarter blue("blue", element, name, strength);
		cout << "Case:" << case_cnt << endl;
		while (flag_red == 1 || flag_blue == 1)
		{
			if (flag_red == 1) flag_red = red.dispatchWarrior();
			if (flag_blue == 1) flag_blue = blue.dispatchWarrior();
		}
		//cout << "********__________________**********" << endl;
	}
	return 0;
}


