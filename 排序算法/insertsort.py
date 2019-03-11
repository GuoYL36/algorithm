#  插入排序
def insert(a):
    if len(a) == 0:
        return
    num = len(a)
    i = 0
    while i < num-1:
        j = i + 1
        while j >= 1:
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]

            j -= 1
        i += 1
    return a

n = [1, 3, 2, 6, 4, 50, 7, 5, 3, 2, 1]
print(n)
res = insert(n)
print(res)





