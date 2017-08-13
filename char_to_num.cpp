/*
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
输入描述:
输入一个十六进制的数值字符串。
输出描述:
输出该数值的十进制字符串。
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char str[100] = {0};
    while (cin >> str)
    {
        int str_len = strlen(str);
        int restult = 0;
        for (int i = 2; i < str_len; i++)
        {
            int temp = 0;
            if ((str[i] >='0')&&(str[i] <='9'))
            {
                temp = str[i] - '0';
            }
            else if ((str[i] >='A')&&(str[i] <='F'))
            {
                temp = str[i] - 'A' + 10;
            }
            restult = restult * 16 + temp;
        }
        cout << restult << endl;
    }
    
	//while (cin >> str)
    return 0;
}