/**********************************************************
第四章  运算符重载
习题
6．编写一个二维数组类Array2，使得程序的输出结果是
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,

#include<iostream>
using namespace std;
int main()
{
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j; //等价于a.operator[](i)[j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     
	b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
***********************************************************/

#include<iostream>
using namespace std;
#if 1 //one funtion
class Array2{
	int row, col;
	int **ptr;
public:
	Array2(int s1 = 0, int s2 = 0) :row(s1), col(s2)
	{
		if (s1 == 0 && s2 == 0) ptr = NULL;
		//else if (s1 == 0 && s2 > 0) ptr = new int[s2];
		//else if (s1 > 0 && s2 == 0) ptr = new int[s1];
		else
		{
			ptr = new int*[s1];
			for (int i = 0; i < s1; i++)
				ptr[i] = new int[s2];
		}
	}
	~Array2()
	{
		if (ptr != NULL) delete[] ptr;
	}
	Array2 & operator=(const Array2 & a)
	{
		if (ptr == a.ptr)return *this;
		if (a.ptr == NULL)
		{
			if (ptr) delete[] ptr;
			row = 0;
			col = 0;
			ptr = NULL;
			return *this;
		}
		if (row<a.row || col<a.col)
		{
			if (ptr) delete[] ptr;
			ptr = new int*[a.row];
			for (int i = 0; i < a.row; i++)
				ptr[i] = new int[a.col];
		}
		//memcpy(ptr, a.ptr, sizeof(int)*a.row*a.col);//---拷贝a.ptr中的所有数据，地址以及地址指向的数据
		//memcpy(ptr, a.ptr, sizeof(int)*a.row);//---拷贝a.ptr[]中的地址 
		for (int i = 0; i < a.row; i++)
			memcpy(ptr[i], a.ptr[i], sizeof(int)*a.col); //---只拷贝a.ptr[]指向的数据
		row = a.row;
		col = a.col;
		return *this;
	}
	int * & operator[](int i)
	{
		//cout << "called" << endl;
		return ptr[i];
	}
	int operator()(int i, int j)
	{
		return ptr[i][j];
	}
};
#else //other funtion
class Array2
{
private:
	int row;//数组行数
	int column;//数组列数
	int* ptr;//指向二维数组的指针
public:
	Array2(int paraRow=0, int paraColumn=0) :row(paraRow), column(paraColumn)
	{
		if (paraRow == 0 && paraColumn == 0) ptr = NULL;
		else ptr = new int[row * column];
	}
//	Array2(Array2& a) :row(a.row), column(a.column)
//	{
//		ptr = new int[row * column];
//		memcpy(ptr, a.ptr, sizeof(int)*row*column);
//	}
	Array2& operator= (const Array2 &a)
	{
		if(ptr==a.ptr) return *this;
		if (a.ptr == NULL)
		{
			if (ptr) delete[] ptr;
			row = 0;
			column = 0;
			ptr = NULL;
			return *this;
		}
		if ((row*column) < (a.row*a.column))
		{
			if (ptr) delete[] ptr;
			ptr = new int[a.row * a.column];
		}
		memcpy(ptr, a.ptr, sizeof(int)*a.row*a.column);
		row = a.row;
		column = a.column;
		return *this;
	}
	~Array2()
	{
		if (ptr) delete[] ptr;
	}
	int* operator [] (int i)
	{
		return ptr + i*column;
	}
	int& operator() (int i, int j)
	{
		return ptr[i*column + j];
	}
};
#endif
int main()
{
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j; 
			//a.operator[](i)[j] = i * 4 + j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}

	cout << "next" << endl;

	Array2 b;     
	b = a;

	//test 深复制
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a[i][j] << ",";
		}
		cout << endl;
	}
	cout << "______" << endl;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}

	return 0;
}
