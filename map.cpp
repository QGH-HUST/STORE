/*
数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
输入描述:
先输入键值对的个数
然后输入成对的index和value值，以空格隔开
输出描述:
输出合并后的键值对（多行）
*/
#include<iostream>
#include<map>

using namespace std;
 int main()
 {
     int n =0;
     while (cin >>n)
     {
         map<int, int> temp;
         while(n--)
         {
             int index = 0, value = 0;
             cin >> index >> value;
             if (!temp[index])
             {
                 temp[index] = value;
             }
             else
             {
                 temp[index] = temp[index] + value;
             }
         }
         map<int, int>::iterator itor = temp.begin();
         for(; itor != temp.end(); itor++)
         {
             cout << itor->first << " " << itor->second << endl;
         }
     }
     return 0;
 }
 