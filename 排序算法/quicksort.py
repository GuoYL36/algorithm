#  快速排序

def quick(a, left, right):
    if len(a) == 0:
        return
    if left >= right:
        return
    index = paixu(a, left, right)
    quick(a, left, index-1)
    quick(a, index+1, right)

def paixu(a, left, right):
    reserve = a[left]
    lpt = left
    rpt = right
    while lpt < rpt:
        while lpt < rpt and a[rpt] >= reserve:
            rpt -= 1
        if lpt < rpt:
            a[lpt] = a[rpt]
            lpt += 1
        while lpt < rpt and a[lpt] < reserve:
            lpt += 1
        if lpt < rpt:
            a[rpt] = a[lpt]
            rpt -= 1
    a[lpt] = reserve
    return lpt

n = [1, 3, 2, 6, 4, 50, 7, 5, 3, 2, 1]
# n = [1, 0, 1, 1]
print(n)
left = 0
right = len(n) - 1
quick(n, left, right)
print(n)