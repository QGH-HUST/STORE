/*
题目描述
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组； 
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。 
输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)
输出描述:
输出到长度为8的新字符串数组
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char str[100];
	while (cin >> str)
    {
        int str_len = strlen(str);
        for (int i = 0; i < str_len; i= i + 8)
        {
            char str_8[9] = {0};
			for (int j = 0; j< 8; j++)
            {
                if(i + j >= str_len)
                {
                    str_8[j] = '0';
                }
                else
                {
                    str_8[j] = str[i + j];
                }
            }
            cout << str_8 << endl;
        }
    }
    return 0;
}
