//牛客51、合并K个有序链表

# include<iostream>
# include<vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* twoConbine(ListNode* l0, ListNode* l1){
        ListNode* prenode = new ListNode(-1);
        ListNode* tmp;
        tmp = prenode;
        while(l0!=nullptr&&l1!=nullptr){
            if(l0->val>l1->val){
                ListNode* t = l1;
                l1 = l1->next;
                t->next = tmp->next;
                tmp->next = t;
                tmp = tmp->next;
            }else{
                ListNode* t = l0;
                l0 = l0->next;
                t->next = tmp->next;
                tmp->next = t;
                tmp = tmp->next;
            }
        }
        
        if(l0 != nullptr){
            tmp->next = l0;
        }
        if(l1 != nullptr){
            tmp->next = l1;
        }
        return prenode->next;
    }
    
    // 先分治
    ListNode* fenzhi(vector<ListNode*>&lists, int i, int j){
        if(i==j){
            return lists[i];
        }
        int mid = i+(j-i)/2;

        ListNode* t0 = fenzhi(lists, i, mid);

        ListNode* t1 = fenzhi(lists, mid+1,j);
        ListNode* tmp = twoConbine(t0, t1);
        return tmp;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int length = lists.size();
        if(length==1){
            return lists[0];
        }
        ListNode* res = fenzhi(lists, 0, length-1);
        return res;
        
        
    }
};






int main(){
    ListNode* a=new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    ListNode* b=new ListNode(4);
    b->next = new ListNode(5);
    b->next->next = new ListNode(6);
    b->next->next->next =new ListNode(7);

    vector<ListNode*> arr;
    arr={a,b};

    Solution func = Solution();
    ListNode* tmp = func.mergeKLists(arr);

    while(tmp!=nullptr){
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }


}
















