/*
题目描述
给定n个字符串，请对n个字符串按照字典序排列。
输入描述:
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述:
数据输出n行，输出结果为按照字典序排列的字符串。
*/
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    string *temp = new string[num + 1];
    for (int i = 0; i < num; i++)
    {
        cin >> *(temp + i);
    }
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (*(temp + i) > *(temp + j))
            {
                string str = *(temp + i);
                *(temp + i) = *(temp + j);
                *(temp + j) = str;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        cout << *(temp + i) << endl;
    }
    delete []temp;
    return 0;
}
