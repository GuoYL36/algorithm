

def partition(a, start, end):
    if start >= end:
        return
    r = a[start]
    s =  start
    e = end
    m = start + (end-start)//2
    while s < e:
        while s < e and a[e] >= r:
            e -= 1
        if s < e:
            a[s] = a[e]
            s += 1
        while s < e and a[s] <= r:
            s += 1
        if s < e:
            a[e] = a[s]
            e += 1
    a[s] = r
    return s

def getLeastNumbers(a, n, k):
    if n == 0 or k < 1:
        return
    start = 0
    end = n - 1
    s = partition(a, start, end)
    while s != k-1:
        if s > k-1:
            end = s - 1
            s = partition(a, start, end)
        else:
            start = s + 1
            s = partition(a, start, end)
    print(a[:k])

a =[4,5,1,6,2,7,3,8]
n = len(a)
k = 4
getLeastNumbers(a, n, k)











