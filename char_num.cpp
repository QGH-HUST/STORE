/*
写出一个程序，接受一个有字母和数字以及空格组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
输入描述:
输入一个有字母和数字以及空格组成的字符串，和一个字符。
输出描述:
输出输入字符串中含有该字符的个数。
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char str[5000];
    char temp;
    int char_num = 0;
    int str_len = 0;
    cin.get(str,5000);
    str_len = strlen(str);
    cin >> temp;
    if ((temp >= 65)&&(temp <= 90))
    {
        temp = temp + 32;
    }
    for(int i = 0;i < str_len; i++)
    {
        if (temp == str[i])
        {
            char_num = char_num + 1;
            continue;
        }
        if ((str[i] >= 65)&&(str[i] <= 90))
        {
            if (temp == str[i] + 32)
            {
                char_num = char_num + 1;
                continue;
            }
        }
    }
    cout << char_num << endl;
    return 0;
}
