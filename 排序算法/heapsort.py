# 堆排序

def heap(a):
    build(a)  # 构建最大堆
    num = len(a)
    i = num-1
    while i >= 1:
        swap(a, 0, i)  # 取出最大堆的根结点，并和最末尾的叶子结点交换，并继续调整堆
        heapify(a, 0, i)
        i -= 1
    return a

# 构建堆
def build(a):
    num = len(a)
    i = int(num/2)-1  # 因为堆满足完全二叉树，所以父结点i的左子结点为2i+1,右子结点为2i+2
    while i >= 0:
        heapify(a, i, num)
        i -= 1
    return a

def heapify(a, parentnode, n):
    lchild = 2 * parentnode + 1  #  因为下标是从0开始，所以左子结点为2倍加1
    rchild = 2 * parentnode + 2  #  因为下标是从0开始，所以右子结点为2倍加2
    largest = parentnode
    # 寻找3个结点中最大值结点的下标
    if lchild < n and a[lchild] > a[largest]:
        largest = lchild
    if rchild < n and a[rchild] > a[largest]:
        largest = rchild
    # 如果最大值不是父结点，则交换并继续调整堆
    if largest != parentnode:
        swap(a, parentnode, largest)
        heapify(a, largest, n)
    return a

# 交换函数
def swap(a, m, n):
    tmp = a[m]
    a[m] = a[n]
    a[n] = tmp
    return a

t = [6, 5, 3, 1, 1, 8, 7, 2, 4]
m = heap(t)
print(m)


