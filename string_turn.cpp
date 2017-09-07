/*
题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符
输出描述:
输出该字符串反转后的字符串
示例1
输入
abcd
输出
dcba
*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string input;
    while (cin >> input)
    {
        string output = input;
        int str_length = input.size();
        for (int i = 0; i < str_length; i++)
        {
            output[str_length - i - 1] = input[i];
        }
        cout << output << endl;
    }
    
    return 0;
}