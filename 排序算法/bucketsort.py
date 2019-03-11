# 桶排序

def bucketsort(n):
    if len(n) == 0 or n == None:
        return n
    nummin = min(n)
    nummax = max(n)
    bucket = nummax - nummin + 1
    res = [0] * bucket
    print(res)
    for i in n:
        res[i-nummin] += 1
    print(res)
    res1 = []
    for i in range(bucket):
        while res[i] != 0:
            res1.append((i+nummin))
            res[i] -= 1
    return res1

n = [1, 3, 2, 6, 4, 7, 5, 3, 2, 1]
print(n)
res = bucketsort(n)
print(res)
