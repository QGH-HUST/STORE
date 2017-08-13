/*
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），
对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按
照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。

Input Param 
     n               输入随机数的个数     
 inputArray      n个随机整数组成的数组 
     
Return Value
     OutputArray    输出处理后的随机整数
     
注：测试用例保证输入参数的正确性，答题者无需验证。测试用例不止一组。
输入描述:
输入多行，先输入随机整数的个数，再输入相应个数的整数
输出描述:
返回多行，处理后的结果
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    int num[1000];
    int total_num = 0;
    // 输入
    while (cin >> total_num)
    {
        int k = 0;
        while (k < total_num)
        {
            cin >> num[k];
            k = k + 1;
        }
        // 排序
        for(int i = 0;i < total_num; i++)
        {
            for (int j = i + 1; j < total_num; j++)
            {
                if (num[j] < num[i])
                {
                    int temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }

            }
        }
        //去重，输出
        int temp = 0;
        if (total_num >= 1)
        {
            temp = num[0];
            cout << temp << endl;
        }
        for(int i = 1;i < total_num; i++)
        {
            if (num[i] == temp)
            {
                continue;
            }
            temp = num[i];
            cout << temp << endl;
        }
    }
    
    return 0;
}
