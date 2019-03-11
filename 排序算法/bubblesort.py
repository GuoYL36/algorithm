#  冒泡排序

def bubble(a):
    if len(a) == 0:
        return
    num = len(a)
    j = num - 1
    # while j < num:
    #     i = num - 1
    #     while i >= j+1:
    #         if a[i] < a[i-1]:
    #             tmp = a[i-1]
    #             a[i-1] = a[i]
    #             a[i] = tmp
    #         i -= 1
    #     j += 1

    while j >= 1:
        i = 0
        while i < j:
            if a[i] > a[i+1]:
                tmp = a[i+1]
                a[i+1] = a[i]
                a[i] = tmp
            i += 1
        j -= 1
    return a

n = [1, 3, 2, 6, 4, 7, 5, 3, 2, 1]
print(n)
res = bubble(n)
print(res)








