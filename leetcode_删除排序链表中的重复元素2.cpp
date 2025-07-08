#include<vector>
#include<iostream>
using namespace std;

// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
// 例子：a=[1,2,2,3,4], 输出为[1,3,4]

struct Node
{
    public:
        int val;
        Node* next;
    Node(int v): val(v) , next(NULL){};
    Node(int v, Node* n): val(v), next(n) {};
}
;


class Solution
{
    public:
    Node* solution(Node* node){
        if(node == NULL){
            return node;
        }
        Node* dummy = new Node(0, node);
        Node* tmp = dummy;
        while(tmp->next && tmp->next->next){
            if(tmp->next->val == tmp->next->next->val){  // 判断连续两个节点取值相同
                int x = tmp->next->val;
                while(tmp->next && tmp->next->val == x){
                    tmp->next = tmp->next->next;
                }
            }
            else{
                tmp = tmp->next;
            }
            
        }
        return dummy->next;
    }
}
;


int main()
{
    Node* node = new Node(1, new Node(2, new Node(2, new Node(3,new Node(4)))));
    Solution func = Solution();
    Node* res = func.solution(node);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }

    return 1;
}








































