/***************************************************************************************
编写一个学生记录处理程序。学生记录用以下类表示
claas {
	char name[10];
	int ID;
	double gpa;
};
学生记录文件名为students. dat，要求是二进制文件，文件中的每个记录和上述类的对象相对应。students. dat最初不存在。
程序可以多次运行，如果第一敬运行程序后students．dat生成了，则以后再运行时，程序应基干已经存在的students. dat进行操作。
程序运行时能接受以下几种命令：
1) Add 姓名 学号 成绩
例如：Add Tom 1234567 78.5
添加学生信息．姓名和学号都不会包含空格。姓名由最多9个字母组成，学号是整数。可能重名，但学号不会重复。
如果发现相同学号的学生已经存在，则不添加学生信息，而是输出：“Aiready entered”。
2) Search 姓名
根据姓名查找学生信息，并输出。如果有重名的，把重名的学生信息全部输出。辅出格式为：
姓名 学号 成绩
每个学生信息输出为一行。查不到则输出“Not Found”。
3) Search 学号
根据学号查找学生信息，并输出。输出格式为：
姓名 学号 成绩
每个学生信息输出为一行。查不到则输出“Not Found”。
4) Modify 学号 成绩
根据学号修改学生的成绩并输出“Done”。如果找不到该学号的学生，则输出“NotFound”。
假定学生记录非常多，所以不能采取用一个大数组把全部学生记录都读取到内存的做法。
***************************************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class CStudent{
public:
	char name[10];
	int ID;
	double gpa;
};
int main()
{
	string command;
	CStudent st,pt;
	fstream ioFile("students.dat", ios::binary | ios::in | ios::out);//ios::app //app会在每次写操作之前都把写指针置于文件末尾
	if (!ioFile) //文件不存在，新建文件
	{
		ioFile.open("students.dat", ios::binary | ios::in | ios::out | ios::trunc);
	}
	if (!ioFile) //新建文件不成功
	{
		cout << "open file error" << endl;
		return 0;
	}
	while (cin >> command)
	{
		if (command == "Add")
		{
			cin >> st.name >> st.ID >> st.gpa;
			int flag_repeat = 0; //是否重复添加的标志
			ioFile.seekg(0, ios::end);
			int total = ioFile.tellg() / sizeof(CStudent) - 1; //文件中有几条记录（从0数）
			for (int i = 0; i <= total; i++) 
			{
				ioFile.seekg(i*sizeof(CStudent), ios::beg);
				ioFile.read((char*)&pt, sizeof(pt));
				if (pt.ID == st.ID)
				{
					flag_repeat = 1;
					break;
				}
			}
			ioFile.seekp(0, ios::end);
			if (flag_repeat == 0) ioFile.write((char*)&st, sizeof(st));
			else if (flag_repeat == 1) cout << "Already entered" << endl;
		}
		else if (command == "Search")
		{
			cin.ignore(1, ' '); //丢弃Search后面的空格
			int c = cin.peek();
			int flag_found = 0; //是否找到的标志
			if (c >= 'A'&&c <= 'Z') //按姓名查找
			{
				cin >> st.name;
				ioFile.seekg(0, ios::end);
				int total = ioFile.tellg() / sizeof(CStudent) - 1;
				int i;
				for (i = 0; i <= total; i++)
				{
					ioFile.seekg(i*sizeof(CStudent), ios::beg);
					ioFile.read((char*)&pt, sizeof(pt));
					if (strcmp(st.name, pt.name)==0)//(st.name == pt.name) //name是char型，不是字符串对象，不能用==比较
					{
						cout << pt.name << " " << pt.ID << " " << pt.gpa << endl;
						flag_found = 1;
					}
				}
			}
			else //按学号查找
			{
				cin >> st.ID;
				ioFile.seekg(0, ios::end);
				int total = ioFile.tellg() / sizeof(CStudent) - 1;
				int i;
				for (i = 0; i <= total; i++)
				{
					ioFile.seekg(i*sizeof(CStudent), ios::beg);
					ioFile.read((char*)&pt, sizeof(pt));
					if (st.ID == pt.ID)
					{
						cout << pt.name << " " << pt.ID << " " << pt.gpa << endl;
						flag_found = 1;
						break;
					}
				}
			}
			if (flag_found == 0) cout << "Not Found" << endl;
		}
		else if (command == "Modify")
		{
			cin >> st.ID >> st.gpa;
			ioFile.seekg(0, ios::end);
			int total = ioFile.tellg() / sizeof(CStudent) - 1;
			int i, flag_found = 0;
			for (i = 0; i <= total; i++)
			{
				ioFile.seekg(i*sizeof(CStudent), ios::beg);
				ioFile.read((char*)&pt, sizeof(pt));
				if (st.ID == pt.ID)
				{
					pt.gpa = st.gpa;
					ioFile.seekp(i*sizeof(CStudent), ios::beg);
					ioFile.write((char*)&pt, sizeof(pt));
					flag_found = 1;
					cout << "Done" << endl;
					break;
				}
			}
			if (flag_found == 0) cout << "Not Found" << endl;
		}
	}
	ioFile.close();
	return 0;
}
