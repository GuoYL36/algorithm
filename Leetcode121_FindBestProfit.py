#  Leetcode121：Best Time to Buy and Sell Stock（最佳时间买卖）

# 题目：假设有一个数组，其中的ith元素时第i天给定股票的价格。如果只被允许完成至多一笔交易（即买一份，卖一份股票），设计一个算法来找到最大利润。
# 注意：在购买股票之前，不能出售股票。

# 例1：
	# Input：[7,1,5,3,6,4]
	# Output：5
	# Explanation：Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
            
				 # Not 7-1 = 6, as selling price needs to be larger than buying price.

# 例2：
	# Input: [7,6,4,3,1]
	# Output: 0
	# Explanation: In this case, no transaction is done, i.e. max profit = 0.

# 思路：利用两个指针，一个指针p用于记录最小买入股票价格的索引，一个指针q用于记录最大买入股票价格的索引。
	
# 



def maxProfit(prices: "List[int]") -> int:
    # 如果当前list长度小于2，直接返回结果。
    if len(prices) < 2:
        return 0
    min_index = 0 #记录最小买入股票价格的索引
    max_index = 0 # 记录最大卖出股票价格的索引
    profit = 0 # 记录最大利润
    for i in range(1, len(prices)):
        # 判断当前的价格大于历史最高价
        if prices[i]>prices[max_index]:
            max_index = i
            # 计算当前的利润
            curr_profit = prices[max_index] - prices[min_index]
            # 如果利润大于历史利润，则使用当前利润
            if curr_profit>profit:
                profit = curr_profit
            
        # 获取最小买入股票价格，如果最小买入股票价格的索引大于最大卖出股票价格的索引，则需要对最大卖出股票价格的索引处理
        elif prices[i]<prices[min_index]:
            min_index = i
            if min_index>max_index:
                max_index = min_index
                
    return profit

p0 = [7,1,5,3,6,4]
p1 = [7,6,4,3,1]

print("profit: ",maxProfit(p0))
print("profit: ",maxProfit(p1))
