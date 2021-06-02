#include<iostream>
#include <vector>
using namespace std;

class Solution {
        public:
                vector<int> searchRange(int A[], int n, int target) {
                        int pos[2] = {-1,-1};
                        int t = binary_search(A,n,target-0.5);
                        if(A[t]==target) {
                                pos[0] = t;
                                pos[1] = binary_search(A,n,target+0.5)-1;
                        }
                        return vector<int>(pos,pos+2);
                }
                int binary_search(int A[], int n, double target)
                {
                        int low = 0, high = n-1;
                        int mid;
                        while(low <= high){
                                mid = (low+high)/2; 
                                if(target<A[mid]) high = mid-1;
                                else low = mid+1;
                        }
                        return low;
                }
};

int main(int argc, char *argv[])
{
        int a[] = {7,7,7,8,8,8};

        Solution ss;
        vector<int> v = ss.searchRange(a,6,7);
        for(vector<int>::iterator it = v.begin(); it!=v.end();it++)
        {
                cout << *it << endl;
        }

        return 0;
}
