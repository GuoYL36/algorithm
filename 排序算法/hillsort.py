#  希尔排序

def hill(a):
    if len(a) == 0:
        return

    num = len(a)
    gap = int(num/2)
    while gap >= 1:
        i = gap
        while i < num:
            j = i
            while j-gap >= 0:
                if a[j] < a[j-gap]:
                    a[j], a[j-gap] = a[j-gap], a[j]
                j -= gap
            i += 1
        gap = int(gap/2)
    return a


n = [1, 3, 2, 6, 4, 50, 7, 5, 3, 2, 1]
print(n)
res = hill(n)
print(res)




