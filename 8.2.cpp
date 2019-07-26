/*************************************************************************************************
编程将一个c++程序文件中的注释以及函数体内部的语句全部去掉后输出到一个
新的文件。假设“／**／”形式的注释没有嵌套。若程序名为proccpp，则以命令行方式运
行之：
Procpp test1.cpp result2.cpp
能够将testl. cpp处理后的结果生成为result2. cpp文件。
输入样例：
#include<iostream>
#include< iomanip >
using namepsace std;
/* test sample
*/
void func(int n)
{
	if (n)
	{
		cout << ”in func” << endl;
	}
}
int main() //this is main
{
	double f;
	cin >> f;
	retun 0;
}
输出样例:
#include < iostream >
#include <iomanip >
using namespace std;
void func() 
{ 
}
int main() 
{ 
}
****************************************************************************************************/
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "File name missing!" << endl;
		return 0;
	}
	ifstream inFile(argv[1], ios::binary | ios::in);
	if (!inFile)
	{
		cout << "Source file open error." << endl;
		return 0;
	}
	ofstream outFile(argv[2], ios::binary | ios::out);
	if (!outFile)
	{
		inFile.close();
		cout << "New file open error." << endl;
		return 0;
	}
	char c,c_last=0;
	int flag=0;
	while (inFile.get(c))
	{
		if (c == '/' && inFile.peek() == '*')//   /*   */格式的注释
		{
			while (inFile.get(c))//一直读到注释结尾'/'字符，丢弃其间读到的所有注释内容
			{
				if (c == '/')break;
			}
			if (c == '/')
			{
				while (inFile.get(c))//一直读到换行'\n'，将'/'和其间读到的回车'\r'也丢弃
				{
					if (c == '\n')break;
				}
			}
			if (c == '\n')continue;//将换行'\n'也丢弃
		}
		if (c == '/' && inFile.peek() == '/')//    //格式的注释
		{
			while (inFile.get(c))//一直读到回车'\r'，将上行的注释丢弃，但是换行不丢弃
			{
				if (c == '\r')break;
			}
		}
		//遇到{ }，只留最外层的{ }，最外层{}内的所有内容丢弃
		if (c_last == '{') flag++;
		if (c == '}')flag--;
		if (flag == 0)
		{
			outFile.put(c);
			if (c == '{')//{后面的换行也被丢弃了，重新加上换行
			{
				outFile.put('\r');
				outFile.put('\n');
			}
		}
		c_last = c;
	}
	outFile.close();
	inFile.close();
	return 0;
}
