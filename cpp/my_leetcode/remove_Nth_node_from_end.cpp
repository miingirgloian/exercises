#include <iostream>
#include <vector>
#include <stack>
#include "utils.h"
using namespace std;

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n, int k) {
        int len = 0;
        ListNode* p = head;
        while(p!=NULL){
            len++;
            p = p->next;
        }
        len -= n;
        ListNode* q=head;
        while(len--) {
            p = q;
            q = q->next;
        }
        if(q==head){
            head = head->next;
        } else {
            p->next = q->next;
        }
        return head;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL) return NULL;
        int len = 0;
        ListNode* p = head;
        while(p!=NULL){
            len++;
            p = p->next;
        }
        len -= n;
        p = head;
        if(!len) return head->next;

        while(--len) p = p->next;
        p->next = p->next->next;
        return head;
    }
};
int main()
{
    int a[] = {1,2,3,4,5,6};
    ListNode* head = make_list(a,3);

    print_list(head);
    Solution ss;
    print_list(ss.removeNthFromEnd(head,1));
    return 0;
}
