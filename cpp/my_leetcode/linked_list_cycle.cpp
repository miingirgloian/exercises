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
                bool hasCycle(ListNode *head){
                        ListNode *fast = head;
                        ListNode *slow = head;
                        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
                                slow = slow->next;
                                fast = fast->next->next;
                                if(fast==slow) return true;
                        }
                        return false;
                }
};


#define N 7
int main(int argc, char *argv[])
{
        int a[] = {1,2,3,4,5,6,7};
        ListNode *head = new ListNode(a[0]);
        ListNode *p = head;
        ListNode *q = NULL;

        for (int i = 1; i < 6; ++i)
        {
                p->next = new ListNode(a[i]);
                if(i==6) q = p;
                p = p->next;
        }
        p->next = NULL;

        Solution ss;
        cout << ss.hasCycle(head) << endl;

        return 0;
}
