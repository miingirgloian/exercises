/*
 *Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 *Follow up:
 *Can you solve it without using extra space?
 */
#include<iostream>
using namespace std;

struct ListNode
{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

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


#define N 2
int main(int argc, char *argv[])
{
        int a[] = {1,2,3,4,5,6,7};
        ListNode *head = new ListNode(a[0]);
        ListNode *p = head;
        ListNode *q = NULL;

        for (int i = 1; i < N; ++i)
        {
                p->next = new ListNode(a[i]);
                if(i==1) q = p;
                p = p->next;
        }
        p->next = p;

        Solution ss;
        cout << ss.detectCycle(head)->val << endl;

        return 0;
}
