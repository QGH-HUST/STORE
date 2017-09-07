/*
题目描述
王强今天很开心，公司发给N元的年终奖。王强决定把年终奖用于购物，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
主件	附件
电脑	打印机，扫描仪
书柜	图书
书桌	台灯，文具
工作椅	无
如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有 0 个、 1 个或 2 个附件。附件不再有从属于自己的附件。王强想买的东西很多，为了不超出预算，他把每件物品规定了一个重要度，分为 5 等：用整数 1 ~ 5 表示，第 5 等最重要。他还从因特网上查到了每件物品的价格（都是 10 元的整数倍）。他希望在不超过 N 元（可以等于 N 元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
    设第 j 件物品的价格为 v[j] ，重要度为 w[j] ，共选中了 k 件物品，编号依次为 j 1 ， j 2 ，……， j k ，则所求的总和为：
v[j 1 ]*w[j 1 ]+v[j 2 ]*w[j 2 ]+ … +v[j k ]*w[j k ] 。（其中 * 为乘号）
    请你帮助王强设计一个满足要求的购物单。
输入描述:
输入的第 1 行，为两个正整数，用一个空格隔开：N m
（其中 N （ <32000 ）表示总钱数， m （ <60 ）为希望购买物品的个数。）

从第 2 行到第 m+1 行，第 j 行给出了编号为 j-1 的物品的基本数据，每行有 3 个非负整数 v p q

（其中 v 表示该物品的价格（ v<10000 ）， p 表示该物品的重要度（ 1 ~ 5 ）， q 表示该物品是主件还是附件。如果 q=0 ，表示该物品为主件，如果 q>0 ，表示该物品为附件， q 是所属主件的编号）
输出描述:
 输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（ <200000 ）。
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef struct goods
{
	int price;
	int prio;
	int ser;
	bool buy = false;
}GOODS;

int main()
{
	int total_price = 0;
	int total_num = 0;
	while (cin >> total_price >> total_num)
	{
		map<int, vector<GOODS>> m_goods;
		int ser = 0;
		int result = 0;
		int temp_result = 0;
		int temp_price = 0;
		// 数据输入
		for (int i = 0; i < total_num; i++)
		{
			GOODS temp;
			cin >> temp.price >> temp.prio >> temp.ser;
			if (temp.ser == 0)
			{
				ser = ser + 1;
				temp.ser = ser;
			}
			m_goods[temp.ser].push_back(temp);
		}
		for (int i = 1; i <= ser; i++)
		{
			for (int j = 0; j < m_goods[i].size(); j++)
			{
				if ((temp_price + m_goods[i][j].price <= total_price) && (((j > 0) && (m_goods[i][0].buy)) || (j == 0)))
				{
					m_goods[i][j].buy = true;
					temp_result = temp_result + m_goods[i][j].price * m_goods[i][j].prio;
					temp_price = temp_price + m_goods[i][j].price;
				}
				else
				{
					for (int ii = 1; ii <= i; ii++)
					{
						if (m_goods[ii][0].buy)
						{
							// 附件
							if ((j > 0) && (m_goods[i][0].buy))
							{
								// 一附换一附
								for (int jj = 1; jj < m_goods[ii].size(); jj++)
								{
									if ((m_goods[ii][jj].buy) && ((temp_price + m_goods[i][j].price - m_goods[ii][jj].price) <= total_price)
										&& ((m_goods[i][j].price * m_goods[i][j].prio) >(m_goods[ii][jj].price * m_goods[ii][jj].prio)))
									{
										m_goods[ii][jj].buy = false;
										m_goods[i][j].buy = true;
										temp_result = temp_result + m_goods[i][j].price * m_goods[i][j].prio - m_goods[ii][jj].price * m_goods[ii][jj].prio;
										temp_price = temp_price + m_goods[i][j].price - m_goods[ii][jj].price;
										break;
									}
								}

								if (m_goods[i][j].buy)
								{
									break;
								}
								// 一附换一行
								else
								{
									int cur_price = m_goods[ii][0].price;
									int cur_result = m_goods[ii][0].price * m_goods[ii][0].prio;
									for (int jj = 1; jj < m_goods[ii].size(); jj++)
									{
										if (m_goods[ii][jj].buy)
										{
											cur_price = cur_price + m_goods[ii][jj].price;
											cur_result = cur_result + m_goods[ii][jj].price * m_goods[ii][jj].prio;
										}
									}
									if (((temp_price + m_goods[i][j].price - cur_price) <= total_price)
										&& ((m_goods[i][j].price * m_goods[i][j].prio) > cur_result))
									{
										m_goods[ii][0].buy = false;
										m_goods[i][j].buy = true;
										temp_result = temp_result + m_goods[i][j].price * m_goods[i][j].prio - cur_result;
										temp_price = temp_price + m_goods[i][j].price - cur_price;
										break;
									}
								}
							}
							// 主件
							else if (j == 0)
							{
								// 一主换一附
								for (int jj = 1; jj < m_goods[ii].size(); jj++)
								{
									if ((m_goods[ii][jj].buy) && ((temp_price + m_goods[i][j].price - m_goods[ii][jj].price) <= total_price)
										&& ((m_goods[i][j].price * m_goods[i][j].prio) >(m_goods[ii][jj].price * m_goods[ii][jj].prio)))
									{
										m_goods[ii][jj].buy = false;
										m_goods[i][j].buy = true;
										temp_result = temp_result + m_goods[i][j].price * m_goods[i][j].prio - m_goods[ii][jj].price * m_goods[ii][jj].prio;
										temp_price = temp_price + m_goods[i][j].price - m_goods[ii][jj].price;
										break;
									}
								}
								if (m_goods[i][j].buy)
								{
									break;
								}
								else
								{
									int cur_price = m_goods[ii][0].price;
									int cur_result = m_goods[ii][0].price * m_goods[ii][0].prio;
									for (int jj = 1; jj < m_goods[ii].size(); jj++)
									{
										if (m_goods[ii][jj].buy)
										{
											cur_price = cur_price + m_goods[ii][jj].price;
											cur_result = cur_result + m_goods[ii][jj].price * m_goods[ii][jj].prio;
										}
									}
									int new_price = m_goods[i][0].price;
									int new_result = m_goods[i][0].price * m_goods[i][0].prio;
									// 一主换一行
									if ((temp_price + new_price - cur_price <= total_price) && (new_result > cur_result))
									{
										m_goods[ii][0].buy = false;
										m_goods[i][0].buy = true;
										temp_result = temp_result + new_result - cur_result;
										temp_price = temp_price + new_price - cur_price;
										break;
									}
									else
									{
										// 一主一附换一行
										for (int jj = 1; jj < m_goods[i].size(); jj++)
										{
											if (((new_price + m_goods[i][jj].price + temp_price - cur_price) <= total_price)
												&& ((new_result + m_goods[i][jj].price * m_goods[i][jj].prio) > cur_result))
											{
												m_goods[ii][0].buy = false;
												m_goods[i][j].buy = true;
												m_goods[i][jj].buy = true;
												new_price = new_price + m_goods[i][jj].price;
												new_result = new_result + m_goods[i][jj].price * m_goods[i][jj].prio;
												temp_result = temp_result + new_result - cur_result;
												temp_price = temp_price + new_price - cur_price;
											}
										}
										if (m_goods[i][j].buy)
										{
											break;
										}
										// 一行换一行
										else
										{
											for (int jj = j + 1; jj < m_goods[i].size(); jj++)
											{
												new_price = new_price + m_goods[i][jj].price;
												new_result = new_result + m_goods[i][jj].price * m_goods[i][jj].prio;
											}
											if (((new_price + temp_price - cur_price) <= total_price)
												&& (new_result > cur_result))
											{
												for (int jj = 0; jj < m_goods[i].size(); jj++)
												{
													m_goods[i][jj].buy = true;
												}
												temp_result = temp_result + new_result - cur_result;
												temp_price = temp_price + new_price - cur_price;
												break;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		// 一行换多行，多行换一行。。。。
		cout << temp_result << endl;
	}
	return 0;
}