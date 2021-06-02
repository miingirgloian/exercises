/*
 *Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 *Note:
 *You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */
#include<iostream>
#include <vector>
using namespace std;

class Solution {
        public:
                void merge(int A[], int m, int B[], int n)
                {
                        int start = 0, pos;
                        for(int i=0; i<n; i++) {
                                pos = search(A,start, m-1, B[i]);
                                start = pos+1;
                                insert(A, m, B[i], pos);
                        }
                }
                int search(int A[], int start, int end, int target)
                {
                        int mid;
                        while(start<=end) {
                                mid = (start+end)>>1;
                                if(target>A[mid]) start=mid+1;
                                else if(target<A[mid]) end=mid-1;
                                else return mid;
                        }
                        return end;
                }
                void insert(int A[], int& m, int target, int pos)
                {
                       if(pos>m-1) {
                               A[pos] = target;
                               m++;
                               return;
                       }
                       for(int i=m-1; i>=pos; i++){
                                A[i+1]=A[i];
                       }
                       m++;
                       A[pos] = target;
                }
};

int main(int argc, char *argv[])
{
        int a[] = {8,8,8,8,8,9,0,0,0,0,0,0};

        Solution ss;
        
        return 0;
}
