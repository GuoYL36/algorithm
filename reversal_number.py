# 数字翻转
def rev(x):
    if x == 0 or x > (2**31-1) or x < (-2**31):
        return 0
    m = str(x)
    l = ''
    for i in range(len(m))[::-1]:
        if i != 0:
            if m[i] != '0' or l.strip() != '':
                l = l+m[i]
        else:
            if m[0] != '-':
                l = l+m[0]
                if int(l) <= 2**31-1:
                    return int(l)
                else:
                    return 0
            else:
                if -int(l) >= -2**31:
                    return -int(l)
                else:
                    return 0
n = 1534236
print(rev(n))