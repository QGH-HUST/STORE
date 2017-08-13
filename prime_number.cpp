/*
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
最后一个数后面也要有空格

详细描述：

函数接口说明：
public String getResult(long ulDataInput)
输入参数：
long ulDataInput：输入的正整数
返回值：
String


输入描述:
输入一个long型整数
输出描述:
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
*/
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long temp;
	cin >> temp;
    while (temp != 1)
    {
        for (int i = 2; i <=temp; i++)
        {
            if (temp % i == 0)
            {
                temp = temp / i;
                cout << i << " ";
                break;
            }
        }
    }
    return 0;
}