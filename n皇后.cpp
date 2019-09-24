/*****************************************************************************************
N皇后问题：
n个皇后，摆放在n×n的棋盘上，任意2个皇后，不能在同一行同一列，且不能在对角线。
求所有的摆放方式。
*****************************************************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
bool Valid(int rows, const vector<int>&pos) //前rows行皇后是否有冲突，行从0算起
{//pos各行皇后的位置，即在第几列，从0算起
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
      //pos[i] == pos[j]表示这两行的皇后在同一位置，即同一列
      //abs(i - j) == abs(pos[i] - pos[j])表示这两行皇后的位置在对角线上
			if (pos[i] == pos[j] || abs(i - j) == abs(pos[i] - pos[j]))
				return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	vector<int>pos(n);
	for (int i = 0; i < n; ++i) //最小的排列方式0，1，2...n-1，所有皇后在一个对角线上
		pos[i] = i;
	while (next_permutation(pos.begin(), pos.end())) //从最小的排列开始，遍历所有排列方式，从中判断符合条件的排列
	{
		if (Valid(n, pos))
		{
			for (int k = 0; k < n; ++k)
			{
				cout << pos[k] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
