# 罗马数字转换为阿拉伯数字

def ro(m):
    roman = {'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}
    s = 0
    for i in range(len(m)-1):
        if roman[m[i]] < roman[m[i+1]]:
            s = s - roman[m[i]]
        else:
            s = s + roman[m[i]]
    return s + roman[m[-1]]

x = 'DCXXI'
print(ro(x))



