#Leetcode 最长连续序列
# 描述：给定一个未排序的整数数组，找出最长连续序列的长度
# 输入: [100, 4, 200, 1, 3, 2]
# 输出: 最长连续序列是[1,2,3,4]，长度为4.

# 解法一：先排序后遍历，时间复杂度为o(nlogn)

#解法二：利用hashmap，时间复杂度为o(n).
def main(a):
    d = dict()
    for i in a:
        if (i not in d) and (i-1 in d or i+1 in d):
            if i-1 in d:
                left = d[i-1]
                d[i] = left+1
                d[i-left] = left+1
            if i+1 in d:
                right = d[i+1]
                if i-1 in d:
                    d[i] = right + d[i]
                    d[i+right] = d[i]
                    d[i-d[i-1]] = d[i]
                else:
                    d[i] = right+1
                    d[i+right] = d[i]
        else:
            d[i] = 1

    print(d)

a = [1,23,2,300,5,3,9,4,3,90]
main(a)







