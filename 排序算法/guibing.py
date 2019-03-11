#  归并排序

def guibing(a, left, right):
    if len(a) == 0:
        return
    if (right-left+1) < 2:
        return
    mid = left + int((right-left)/2)
    guibing(a, left, mid)
    guibing(a, mid+1, right)
    paixu(a, left, right)


def paixu(a, left, right):
    mid = left + int((right-left)/2)
    lpt = left  # 左指针
    rpt = mid + 1  # 右指针
    res = []
    while lpt <= mid and  rpt <= right:
        print(lpt, rpt)
        if a[lpt] < a[rpt]:
            res.append(a[lpt])
            lpt += 1
        else:
            res.append(a[rpt])
            rpt += 1
    while lpt <= mid:
        res.append(a[lpt])
        lpt += 1
    while rpt <= right:
        res.append(a[rpt])
        rpt += 1
    a[left:right+1] = res[:]

n = [1, 3, 2, 6, 4, 50, 7, 5, 3, 2, 1]
print(n)
left = 0
right = len(n) - 1
guibing(n, left, right)
print(n)














