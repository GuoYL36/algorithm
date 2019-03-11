# 找出数组中所有字符串的最长的共同前缀

def longestcommonprefix(strs):
    if len(strs) == 0:
        return ""
    short_length = len(strs[0])
    for i in range(len(strs)):
        if short_length > len(strs[i]):
            short_length = len(strs[i])
    print(short_length)
    for i in range(short_length):
        for j in range(len(strs)):
            if strs[j][i] == strs[0][i]:
                #print(j)
                continue
            else:
                if i == 0:
                    return ""
                return strs[0][0:i]
    return strs[0][0:short_length]
l=["aa","ab"]
print(longestcommonprefix(l))




