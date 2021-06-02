#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode* head)
{
    while(head!=NULL){
        cout << head->val<< " ";
        head = head->next;
    }
    cout << endl;
}
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
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2;i<3;i++){
        p->next = new ListNode(i);
        p = p->next;
        p->next = NULL;
    }
    print(head);
    Solution ss;
    print(ss.removeNthFromEnd(head,1));
    return 0;
}
