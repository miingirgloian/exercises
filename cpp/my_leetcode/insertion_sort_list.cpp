#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode* head)
{
    ListNode* p = head;
    while(p!=NULL){
        cout << p->val <<" ";
        p = p->next;
    }
    cout << endl;
}
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
                print(head);
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
            print(head);
        }
        return head;
    }
};
int main()
{
    Solution ss;
    int a[]={13,12,31,1,3,42,7,5,21,0};
    ListNode* head = new ListNode(a[0]);
    ListNode* p = head;
    for(int i = 1; i<10; i++)
    {
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    p->next = NULL;

    print(head);
    cout <<"******************************"<<endl;
    head = ss.insertionSortList(head);
    cout <<"******************************"<<endl;
    print(head);
    return 0;
}
