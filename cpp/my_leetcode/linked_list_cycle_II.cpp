/*
 *Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 *Follow up:
 *Can you solve it without using extra space?
 */
#include<iostream>
#include "utils.h"
using namespace std;

class Solution {
        public:
                ListNode* detectCycle(ListNode *head){
                        ListNode *fast = head;
                        ListNode *slow = head;
                        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
                                slow = slow->next;
                                fast = fast->next->next;
                                if(fast==slow){
                                        ListNode *p = head;
                                        if(fast==head) return head;
                                        while(1){
                                                if(find(p,fast)) return p;
                                                p = p->next;
                                        }
                                } 
                        }
                        return NULL;
                }
                bool find(ListNode *p, ListNode *head)
                {
                        ListNode *q = head;
                        do {
                                if (p == q) return true;
                                q = q->next;
                        } while(q!=head);
                        return false;
                }
};

int main(int argc, char *argv[])
{
        int a[] = {1,2,3,4,5,6,7};
        ListNode *head = make_list(a,7);
        make_list_cycle(head,2);

        Solution ss;
        cout << ss.detectCycle(head)->val << endl;

        return 0;
}
