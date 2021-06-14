#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <cstdlib>
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

void delete_list(ListNode *head)
{
        ListNode *p;
        while(head!=NULL){
                p = head->next;
                delete head;
                head = p;
        }
}
void make_list_cycle(ListNode *head, int index)
{
        if(index<=0||head==NULL) exit(0);

        ListNode *p = head;
        while(head->next!=NULL) head = head->next;
        while(--index&&p!=NULL) p = p->next;

        if(p==NULL) exit(0);
        else head->next = p; 
}
