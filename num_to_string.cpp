/*
题目描述
描述：
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
输入描述:
输入一个int整数
输出描述:
将这个整数以字符串的形式逆序输出
*/
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;

int main()
{
    int num = 0;
    while (cin >> num)
    {
        while (num > 0)
        {
            char temp_c = num % 10 + '0';
            cout << temp_c;
            num = num / 10;
        }
        cout << endl;
    }
    return 0;
}