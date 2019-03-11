"""创建二叉树并实现4种遍历"""

class Node():
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

# 建立二叉树
def creat_tree():
    a = input("enter a key: ")
    if a == '#':
        root = None
    else:
        root = Node(a)
        root.left = creat_tree()
        root.right = creat_tree()
    return root

# 前序遍历
def preord(root):
    if root == None:
        return
    print(root.data, end=' ')
    preord(root.left)
    preord(root.right)

# 中序遍历
def midord(root):
    if root == None:
        return
    midord(root.left)
    print(root.data, end=' ')
    midord(root.right)

# 后序遍历
def backord(root):
    if root == None:
        return
    backord(root.left)
    backord(root.right)
    print(root.data, end=' ')

# 层次遍历——用队列实现
def levelord(root):
    if root == None:
        return
    q = []
    q.append(root)
    while q:
        n = q.pop(0)
        print(n.data, end=' ')
        if n.left != None:
            q.append(n.left)
        if n.right != None:
            q.append(n.right)


root = creat_tree()  # [1,2,4,#,#,5,#,#,3,6,#,#,#]
preord(root)
print()
midord(root)
print()
backord(root)
print()
levelord(root)







# binNode1 = Node(1)
# binNode2 = Node(2)
# binNode3 = Node(3)
# binNode4 = Node(4)
# binNode5 = Node(5)
# binNode6 = Node(6)


# binNode1.left = binNode2
# binNode1.right = binNode3
# binNode2.left = binNode4
# binNode2.right = binNode5
# binNode3.left = binNode6
# print(binNode3.right)
#
# preord(binNode1)
# midord(binNode1)
# backord(binNode1)
# levelord(binNode1)