/*
计算字符串最后一个单词的长度，单词以空格隔开。
输入描述:
一行字符串，非空，长度小于5000。
输出描述:
整数N，最后一个单词的长度。
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char str[5000];
    int last_len = 0;
    int str_len = 0;
    cin.get(str,5000);
    str_len = strlen(str);
    last_len = str_len;
    for(int i = 0;i < str_len; i++)
    {
        if(str[i] == ' ') last_len = str_len - i -1;
    }
    cout << last_len << endl;
    return 0;
}
