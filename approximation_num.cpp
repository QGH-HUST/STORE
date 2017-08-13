/*
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
输入描述:
输入一个正浮点数值
输出描述:
输出该数值的近似整数值
*/
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    float temp = 0.0;
    float temp_dot = 0.0;
    int dot = 0;
    int num = 0;
	cin >> temp;
	num = (int)temp;
    if((temp - num) >= 0.5)
    {
        num = num + 1;
    }
    cout << num << endl;
    return 0;
}
