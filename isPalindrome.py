# 判断是否为回文数

def re(x):
    if x < 0:
        return False
    if x > 2**31-1:
        return False
    else:
        l = 1
        while x/l >= 10:
            l = l * 10
        while x != 0:
            left = int(x / l)
            right = x % 10
            if left != right:
                return False

            x = int((x % l)/10)
            l = l / 100
        return True
m = 1000029
print(re(m))