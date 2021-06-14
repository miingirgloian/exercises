#include<iostream>
#include "utils.h"
using namespace std;

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
        ListNode *head = make_list(a,7);
        make_list_cycle(head,1);

        Solution ss;
        cout << ss.hasCycle(head) << endl;

        return 0;
}
