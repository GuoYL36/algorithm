// nc93、设计LRU缓存结构

// 思路：hashmap + 双向链表



#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


struct ListNode{
    int key, val;
    ListNode* pre;
    ListNode* nxt;
    ListNode(int k, int v): key(k), val(v), pre(nullptr), nxt(nullptr){}
};


class Solution{
public:
    int size = 0;
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> mp;

    vector<int> LRU(vector<vector<int>>& operators, int k){
        if(k<1) return {};
        size = k;
        head = new ListNode(0,0);
        tail = new ListNode(0,0);
        head->nxt = tail;
        tail->nxt = head;

        if(operators.size()==0) return {};

        vector<int> res;
        for(vector<int> op: operators){
            if(op[0]==1){
                set(op[1],op[2]);
            }
            else if(op[0]==2){
                int value = get(op[1]);
                res.push_back(value);
            }
        }
        return res;
    }

    void set(int key, int val){
        if(mp.find(key) == mp.end()){
            ListNode* node = new ListNode(key, val);
            mp[key] = node;
            if(size<=0){
                removeLast();
            }
            else{
                size--;
            }
            insertFirst(node);
        }
        else{
            mp[key]->val = val;
            moveToHead(mp[key]);
        }

    }

    int get(int key){
        int res = -1;
        if(mp.find(key) != mp.end()){
            res = mp[key]->val;
            moveToHead(mp[key]);
        }
        return res;

    }

    void insertFirst(ListNode* node){
        node->pre = head;
        node->nxt = head->nxt;
        head->nxt->pre = node;
        head->nxt = node;

    }

    void moveToHead(ListNode* node){   // 先删除 后插入
        if(node->pre == head) return;
        node->pre->nxt = node->nxt;
        node->nxt->pre = node->pre;
        insertFirst(node);

    }

    void removeLast(){
        mp.erase(tail->pre->key);
        tail->pre->pre->nxt = tail;
        tail->pre = tail->pre->pre;
    }
};























