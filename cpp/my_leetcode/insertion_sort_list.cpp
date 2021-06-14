#include <iostream>
#include "utils.h"
using namespace std;

class Solution {
public:
    ListNode *insertionSortList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *p = head, *q=p->next;
        while(q!=NULL){
            if(q->val < head->val){
                p->next = q->next;
                q->next = head;
                head = q;
                q = p->next;
                continue;
            }
            ListNode* r = head, *s=head->next;
            while(s!=q){
                if(q->val<s->val){
                    p->next = q->next;
                    q->next = s;
                    r->next = q;
                    q = p->next;
                    break;
                }
                r = s;
                s = s->next;
            }
            if(s==q) {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
int main()
{
    Solution ss;
    int a[]={13,12,31,1,3,42,7,5,21,0};
    ListNode* head = make_list(a,10);

    print_list(head);
    cout <<"******************************"<<endl;
    head = ss.insertionSortList(head);
    cout <<"******************************"<<endl;
    print_list(head);
    return 0;
}
