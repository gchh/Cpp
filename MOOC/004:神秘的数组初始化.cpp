/******************************************************************
004:神秘的数组初始化
总时间限制: 1000ms 内存限制: 65536kB 
描述
填空，使得程序输出指定结果
123,456
******************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int * a[] = {
NULL, NULL, new int, new int[6]  // 在此处补充你的代码
};
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	return 0;
}
