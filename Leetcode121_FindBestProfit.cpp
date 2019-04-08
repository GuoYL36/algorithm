/* Leetcode121：Best Time to Buy and Sell Stock（最佳时间买卖）

题目：假设有一个数组，其中的ith元素时第i天给定股票的价格。如果只被允许完成至多一笔交易（即买一份，卖一份股票），设计一个算法来找到最大利润。
注意：在购买股票之前，不能出售股票。

例1：
	Input：[7,1,5,3,6,4]
	Output：5
	Explanation：Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
            
				 Not 7-1 = 6, as selling price needs to be larger than buying price.

例2：
	Input: [7,6,4,3,1]
	Output: 0
	Explanation: In this case, no transaction is done, i.e. max profit = 0.

思路：利用两个指针，一个指针p用于记录最小买入股票价格的索引，一个指针q用于记录最大买入股票价格的索引。
	
*/

#include<iostream>
#include<stdio.h>
using namespace std;

int FindBestTime(int a[], int length){
	if(length<2){
		return 0;
	}
/* 	int max_ind = 0; //记录最大买入股票价格的索引
	int min_ind = 0; //最小买入股票价格的索引
	int cur_profit=0, profit = 0; //cur_profit为当前利润，profit为记录的最大利润
	
	for(int i=1; i<length; i++){
		if(a[i]>a[max_ind]){    // 当前股票价格大于历史最高价
			max_ind = i;
			cur_profit = a[max_ind] - a[min_ind];
			if(cur_profit>profit){  // 如果利润大于历史利润，则使用当前利润
				profit = cur_profit;
			}
		}
		else if(a[i]<a[min_ind]){  // 获取最小买入股票价格，如果最小买入股票价格的索引大于最大卖出股票价格的索引，则需要对最大卖出股票价格的索引处理
			min_ind = i;
			if(max_ind<min_ind){
				max_ind = min_ind;
			}
		}
		else{
			continue;
		}
	} */
	
	
	
	int profit = 0;
	int cur_min = a[0]; // 记录最小值
	for(int i=0;i<length;i++){
		profit = max(a[i]-cur_min, profit);
		cur_min = min(a[i], cur_min);
	}

	
	
	return profit;
}

int main(){
	int price0[6] = {7,1,5,3,6,4};
	int price1[5] = {7,6,4,3,1};
	int length0 = sizeof(price0)/sizeof(price0[0]);
	int length1 = sizeof(price1)/sizeof(price1[0]);
	printf("最大利润: %d\n", FindBestTime(price0, length0));
	printf("最大利润：%d", FindBestTime(price1, length1));
	return 0;
}




















