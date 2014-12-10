#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* pre_m = NULL, *node_m = NULL,*node_n = NULL,*after_n = NULL;

        int i = 1;
        if(m == 1){
            pre_m = NULL;
            node_m = head;
        } else{
            pre_m = head;
            while(i < m - 1){
                i++;
                pre_m = pre_m->next;
            }
            node_m = pre_m->next;
            i++; // i is pointis node m
        }

        i+=1; //now, i is the node after m
        ListNode* pre = node_m;
        ListNode* cur = node_m->next;
        while(i <= n){
            //reverse
            ListNode* cur_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = cur_next;
            i++;
        }
        // i point to node n + 1
        node_n = pre;
        after_n = cur; //if i == len, then cur == NULL

        if(pre_m != NULL){
            pre_m->next = node_n;
        }
        node_m->next = after_n;
        if(pre_m != NULL)
            return head;
        else 
            return node_n;
    }
};

void Print(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void Test(int start, int end){
    ListNode* pre = new ListNode(5);
    ListNode* head = pre;
    int i = 4;
    while(i > 0){
        ListNode* node = new ListNode(i--);
        node->next = pre;
        pre = node;
        head = node;
    }
    Print(head);
    Solution s;
    Print(s.reverseBetween(head, 2, 4));
}

int main(){
    Test(2,4);
    Test(1,4);
    Test(2,5);
    Test(2,5);
    return 0;
}
