# 动态规划思想
# dp[0] = 0
# dp[i] = min{dp[i - coins[j]] + 1}, 且其中i >= coins[j], 0<=j<coins.length
# 回溯法，输出可找的硬币方案
# path[i] 表示经过本次兑换后所剩下的面值，即 i-path[i] 可得到本次兑换后的硬币值
# def changecoins(coins, n):















