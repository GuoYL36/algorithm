# n个骰子的点数
# n为骰子个数，s为n个骰子点数之和(n =< s <= 6n)
# 递归方法：f(n, s) = f(n-1, s-1) + f(n-1, s-2) +...+ f(n-1, s-6)
# f(1, 1) = f(1, 2) = f(1, 3) = ... = f(1, 6) = 1

# -----------------递归求解-------------------------------------
def calNum(n, s):
    if n < 1 or s < n or s > 6*n:
        return 0
    if n == 1:
        return 1
    return calNum(n-1, s-1) + calNum(n-1, s-2) + calNum(n-1, s-3) + calNum(n-1, s-4) + calNum(n-1, s-5) + calNum(n-1, s-6)

def probability(n):
    if n <= 0:
        return None
    total = 6 ** n
    res = [0] * (6*n - n + 1)
    j = n
    while j <= 6*n:
        res[j-n] = calNum(n, j)
        j += 1
    for i in range(len(res)):
        print("<{0}, {1}>, pro: {2}/{3}" .format(n, i+n, res[i], total))


# # ----------------------动态规划求解------------------------------------
# def dongtaiguihua(n):
#     a = [0] * 6  # 用于存储不断变化的值
#
#     for i in range(6):
#         a[i] = 1
#     i = 2
#     while i < n+1:
#         j = i
#         res = [0] * (6 * i - i + 1)  # 下标表示所有点数之和减i
#         while j <= 6*i:
#
#             j += 1
#         for k in range(6):
#             a[k] = res[k+i]
#         i += 1




probability(3)





