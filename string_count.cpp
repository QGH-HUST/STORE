/*
题目描述
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
输入描述:
输入N个字符，字符在ACSII码范围内。
输出描述:
输出范围在(0~127)字符的个数。
示例1
输入
abc
输出
3
*/

#include<iostream>
#include<string>
#include<set>
using namespace std;

int main ()
{
    string temp;
    while (cin >> temp)
    {
        int num = 0;
        set<int> result;
        for (int i = 0; i < temp.size(); i++)
        {
            if ((temp[i] >= 0)&&(temp[i] <= 127)&&(result.find(temp[i]) == result.end()))
            {
                num = num + 1;
                result.insert(temp[i]);
            }
        }
        cout << num << endl;
    }
    return 0;
}