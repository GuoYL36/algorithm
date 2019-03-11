# 剑指offer57：删除已排序链表中重复的节点

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplication(self, pHead):
        if pHead == None:
            return pHead
        a = {}
        p1 = pHead
        while p1 != None:
            if p1.val not in a:
                a[p1.val] = 1
            else:
                a[p1.val] = -1
            p1 = p1.next
        pre = None
        res = None # 保存头结点
        p2 = pHead
        while p2 != None:
            if a[p2.val] == 1:
                if pre == None:
                    pre = p2
                    res = pre
                else:
                    pre.next = p2  # 注意是引用传递
                    pre = pre.next
                    pre.next = None  # 会导致p2.next = None，因此改变了原来遍历的链表，直接跳出循环
            p2 = p2.next

        return res

a1 = ListNode(1)
a2 = ListNode(1)
a3 = ListNode(2)
a4 = ListNode(3)
a5 = ListNode(4)
a6 = ListNode(4)
a7 = ListNode(5)
a8 = ListNode(6)
a7.next = a8
a6.next = a7
a5.next = a6
a4.next = a5
a3.next = a4
a2.next = a3
a1.next = a2

s = Solution()
res = s.deleteDuplication(a1)
while res != None:
    print(res.val)
    res = res.next