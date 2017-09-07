/*
题目描述
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
输入描述:
输入一个int型整数
输出描述:
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
示例1
输入
9876673
输出
37689
*/
#include<iostream>
#include<stdio.h>
using namespace std;
 int main()
 {
     int temp = 0;
     int num[10] = {0};
     int n = 0;
     int result = 0;
     while (cin >> temp)
     {
         while (temp > 0)
         {
             n = temp % 10;
             temp = temp / 10;
             if (num[n] == 0)
             {
                 num[n] = 1;
                 result= result *10 + n;
             }
             else
             {
                 continue;
             }
         }
         cout << result << endl;
     }
     return 0;
 }