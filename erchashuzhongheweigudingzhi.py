# 二叉树中和为某一值的路径

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.res = []
        self.path = []

    def solution(self, root, n):
        path = self.path
        path.append(root.val)
        s = n - root.val
        if root.left == None and root.right == None and s == 0:
            self.res.append(path[:])
        if root.left != None:
            self.solution(root.left, s)
        if root.right != None:
            self.solution(root.right, s)
        path.pop()

    def findPath(self, root, expectNumber):
        if root == None or expectNumber == None:
            return []
        self.solution(root, expectNumber)
        return self.res

node1 = TreeNode(10)
node2 = TreeNode(5)
node3 = TreeNode(12)
node4 = TreeNode(4)
node5 = TreeNode(7)

node1.left = node2
node1.right = node3
node2.left = node4
node2.right = node5

m = Solution()
print(m.findPath(node1, 22))






















