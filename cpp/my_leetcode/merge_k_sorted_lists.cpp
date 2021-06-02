#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode
{
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(NULL){}
};

class Solution {
        public:
                ListNode *mergeKLists(vector<ListNode *> &lists){
                        int index;
                        ListNode *ret = new ListNode(0), *head = ret;
                        ret->next = NULL;

                        while(~(index = find_max(lists))) {
                                head->next = lists[index];
                                lists[index] = lists[index]->next;
                                head = head->next;
                        }
                        head->next = NULL;

                        head = ret;
                        ret = ret->next;
                        delete head;

                        return ret;

                }
                int find_max(vector<ListNode *> &lists)
                {
                        int max = INT_MAX, index = -1;
                        for(int i=0 ; i<lists.size(); i++){
                                if(lists[i]!=NULL && lists[i]->val<=max){
                                        max = lists[i]->val;
                                        index = i;
                                }
                        }
                        return index;
                }
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

int main(int argc, char *argv[])
{
        int a[] = {1,2,3,4,5,6,7,8,9,10};
        int b[] = {2,4,6,8,10};
        int c[] = {-9, -5, 1, 23, 123, 234};
        vector<ListNode *> v;
        v.push_back(make_list(a,4));
//        print_list(make_list(a,2));
        v.push_back(make_list(b,0));
        v.push_back(make_list(c,0));

        Solution ss;
        print_list(ss.mergeKLists(v));
        return 0;
}
