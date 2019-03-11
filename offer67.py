# # 机器人的运动范围
#
# class Solution:
#     def movingCount(self, threshold, rows, cols):
#         visit = [False] * (rows * cols)
#         count = self.movingCountCore(threshold, rows, cols, 0, 0, visit)  # (0, 0)为起始坐标
#         return count
#
#     def movingCountCore(self, threshold, rows, cols, row, col, visit):
#         count = 0
#         if self.check(threshold, rows, cols, row, col, visit):
#             visit[row * col + col] = True
#             count = 1 + self.movingCountCore(threshold, rows, cols, row + 1, col, visit) + self.movingCountCore(threshold, rows, cols, row - 1, col, visit) + self.movingCountCore(threshold, rows, cols, row, col + 1,visit) + self.movingCountCore(threshold, rows, cols, row, col - 1, visit)
#
#         return count
#
#     def check(self, threshold, rows, cols, row, col, visit):
#         if (row >= 0) and (row < rows) and (col >= 0) and (col < cols) and (not (visit[row * cols + col])) and (
#             self.getDigitSum(col, row) <= threshold):
#             return True
#         return False
#
#     def getDigitSum(self, n, m):
#         cur = 0
#         while n > 0:
#             cur += n % 10
#             n = n // 10
#         while m > 0:
#             cur += m % 10
#             m = m // 10
#         return cur
#
#
# s = Solution()
# print(s.getDigitSum(10, 10))
# print(s.movingCount(5, 10, 10))
# print(s.getDigitSum(10, 10))












