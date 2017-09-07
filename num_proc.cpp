/*
题目描述
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
输入描述:
 输入一个整数（int类型）
输出描述:
 这个数转换成2进制后，输出1的个数
*/

#include<iostream>

using namespace std;

int main ()
{
    int temp = 0;
    int num = 0;
    cin >> temp;
    while (temp)
    {
        if (temp % 2)
        {
            num = num + 1;
        }
        temp = temp / 2;
    }
    cout << num << endl;
    return 0;
}