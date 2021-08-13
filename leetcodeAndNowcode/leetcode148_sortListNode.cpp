// leetcode148、排序链表——中等

#include<iostream>
#include<vector>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {          // 时间复杂度：O(nlogn)，空间复杂度:O(1)
public:
    // 两个链表合并
    ListNode* merge(ListNode* head0, ListNode* head1){
        if(head0 == nullptr){
            return head1;
        }
        if(head1 == nullptr){
            return head0;
        }
        ListNode* dummyHead = new ListNode(-1);
        ListNode* node = dummyHead;
        while(head0 != nullptr && head1 != nullptr){
            ListNode* tmp = nullptr;
            if(head0->val>head1->val){
                tmp = head1->next;
                head1->next = nullptr;
                node->next = head1;
                node = node->next;
                head1 = tmp;
            }else{
                tmp = head0->next;
                head0->next = nullptr;
                node->next = head0;
                node = node->next;
                head0 = tmp;  
            }
        }

        if(head0 != nullptr){
            node->next = head0;
        }
        if(head1 != nullptr){
            node->next = head1;
        }
        return dummyHead->next;
    }

    // 归并法
    ListNode* sortList(ListNode* head){
        if(head==nullptr){
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while(node != nullptr){
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        // 先对链表进行拆分成子链表，然后进行合并
        for(int sublength=1;sublength<length;sublength<<=1){    // 拆分子链表的长度从1开始
            ListNode* pre=dummyHead; // 用于连接排序好的子链表
            ListNode* curr = dummyHead->next;
            while(curr != nullptr){      // 从前往后分割长度为sublength的子链，得到两个就先合并，再继续迭代分割合并
                ListNode* tmp = curr;   // 获取长度为sublength的子链
                for(int i=1;i<sublength&&curr->next!=nullptr;i++){   // 得到第一个长度为sublength的子链，curr->next!=nullptr是考虑最后一个子链表不满足sublength长度时
                    curr = curr->next;
                }

                ListNode* tmp1 = curr->next;
                curr->next = nullptr;     // 第一个长度为sublength的子链

                curr = tmp1;
                for(int i=1;i<sublength&& curr!=nullptr&&curr->next !=nullptr;i++){    // 得到第二个长度为sublength的子链,curr!=nullptr是考虑最后一次迭代只有一个子链的情况,curr->next!=nullptr是考虑最后一个子链表不满足sublength长度时
                    curr = curr->next;
                }

                ListNode* tmp2 = nullptr;
                if(curr != nullptr){
                    tmp2 = curr->next;
                    curr->next = nullptr;
                }

                // 对上面得到的子链表进行排序合并
                ListNode* m = merge(tmp, tmp1);
                pre->next = m;
                while(pre->next != nullptr){
                    pre = pre->next;
                }
                curr = tmp2;
            }
        }
        return dummyHead->next;
    }

    // 快排  时间复杂度: O(nlogn)，最坏O(n^2)，空间复杂度: O(1)
    ListNode* fastSort(ListNode* head, ListNode* end){
        if(head==end || head->next == end){
            return head;
        }
        ListNode* left = head;
        ListNode* right = head;
        ListNode* cur = head->next;
        while(cur != end){
            ListNode* tmp = cur->next;
            if(cur->val < head->val){
                cur->next = left;
                left = cur;
            }else{
                right->next = cur;
                right = cur;                
            }
            cur = tmp;
        }
        right->next = end;
        ListNode* node = fastSort(left, head);
        head->next = fastSort(head->next, end);
        return node;
    }
    ListNode* sortList1(ListNode* head){
        return fastSort(head, nullptr);
    }
};


int main()
{
    // 4->2->1->3;
    // ListNode* head = new ListNode(4);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(1);
    // head->next->next->next = new ListNode(3);
    
    //-1->5->3->4->0;
    ListNode* head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);

    Solution func = Solution();

    ListNode* res = func.sortList(head);
    ListNode* tmp;
    tmp = res;
    while(tmp != nullptr){
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }

    return 1;
}











