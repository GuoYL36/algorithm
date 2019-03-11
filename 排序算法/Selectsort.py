#  选择排序
def select(a):
    if len(a) == 0:
        return
    num = len(a)
    j = 0
    while j < num-1:
        minIndex = j
        i = j+1
        while i <= num-1:
            if a[i] < a[minIndex]:
                minIndex = i
            i += 1
        a[j], a[minIndex] = a[minIndex], a[j]
        j += 1
    return a

n = [1, 3, 2, 6, 4, 50, 7, 5, 3, 2, 1]
print(n)
res = select(n)
print(res)




