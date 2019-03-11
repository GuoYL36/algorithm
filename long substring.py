#最长公共子序列和最长公共子串
#最长公共子序列

def find_lcseque(s1, s2):
    # 生成字符串长度加1的0矩阵，m用来保存对应位置匹配的结果
    length1 = len(s1)
    length2 = len(s2)
    result = ''
    C = [[0 for x in range(length2 + 1)] for y in range(length1 + 1)]
    for i in range(length1):
        for j in range(length2):
            if s1[i] == s2[j]:
                C[i+1][j+1] = C[i][j] + 1

            else:
                C[i+1][j+1] = max(C[i][j+1], C[i+1][j])
    print("max length: ", C[length1][length2])
    print("result: ", result)
find_lcseque('ABCBDAB', 'BDCABA')



#最长公共子串
def find_lcsSubstr(s1, s2):
    # 生成字符串长度加1的0矩阵，m用来保存对应位置匹配的结果
    length1 = len(s1)
    length2 = len(s2)
    substr_length = 0
    C = [[0 for x in range(length2 + 1)] for y in range(length1 + 1)]
    for i in range(length1):
        for j in range(length2):
            if s1[i]==s2[j]:
                C[i][j] = C[i-1][j-1] + 1
                substr_length = max(C[i][j], substr_length)
            else:
                C[i][j] = 0

    print("Substr max length: ", substr_length)

find_lcsSubstr('ABCBDAB', 'BDCABA')