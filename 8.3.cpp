/*********************************************************
编写一个程序doublefile．exe．运行方式如下：
doubleflie 文件名
则能将指定文件内容加倍，文件未必是文本文件。例如有some．txt文件内容如下：
ThLs is a file.
Please double lt.
最后一行后面没有换行。则经过处理后some．txt文件内容如下:
This is a file.
Please double it.This is a file.
Please double id.
**********************************************************/
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "File name missing!" << endl;
		return 0;
	}
	fstream ioFile(argv[1], ios::binary | ios::in | ios::out);
	if (!ioFile)
	{
		cout << "file open error" << endl;
		return 0;
	}
	ioFile.seekp(0, ios::end);
	int wrpointer=ioFile.tellp();
	ioFile.seekg(0, ios::beg);
	char c;
	for (int i = 0; i < wrpointer; i++)
	{
		//当前指针位置i，将要读取i位置的字符，并将该字符写入wrpointer+i的位置
		ioFile.get(c);//读取字符后，指针移到下一个位置i+1
		ioFile.seekp(wrpointer-1, ios::cur);//当前的指针位置i+1和要写入的位置wrpointer+i，间隔wrpointer-1；指针跳到该位置wrpointer+i
		ioFile.put(c);//在位置wrpointer+i写入字符，指针指向wrpointer+i+1
		ioFile.seekg(0-wrpointer, ios::cur);//指针要跳回位置i+1，准备读取该位置字符；改位置和当前指针位置wrpointer+i+1，间隔0-wrpointer
	}
	ioFile.close();
	return 0;
}
