#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct ListNode
{
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(NULL){}
};

ListNode *make_list(int a[],int n)
{
    if(!n) return NULL;
    ListNode *head = new ListNode(a[0]), *p = head;
    for (int i=1; i < n; ++i)
    {
        p->next = new ListNode(a[i]);
        p = p->next;
    }

    return head;
}

void print_list(ListNode *head)
{
    while(head!=NULL){
        cout << head->val <<" ";
        head = head->next;
    }
    cout << endl;
}
