# 圆圈中最后剩下的数字(约瑟夫问题)

class Solution():
    def LastRemaining_Solution(self, n, m):
        # if m <= 0 or n <= 1:
        #     return -1
        # a = []
        # for i in range(n):
        #     a.append(i)
        # i = n
        # k = 0
        # while i > 1:
        #     if m == i:
        #         j = k + m - 1
        #     else:
        #         j = k + m % i - 1
        #     if j < i:
        #         a.pop(j)
        #     else:
        #         j = j%i
        #         a.pop(j)
        #     k = j
        #     i = len(a)
        # return a[0]

        #  递归公式：f(n,m) = [f(n-1,m) + m] % n
        if n < 1 or m < 1:
            return -1
        last = 0
        i = 2
        while i <= n:
            last = (last + m) % i
            i += 1
        return last



n = 5
m = 3
a = Solution()
print(a.LastRemaining_Solution(5, 3))