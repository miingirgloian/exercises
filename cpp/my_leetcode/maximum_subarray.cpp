#include <iostream>
using namespace std;

class Solution {
    public:
        int find_maxsubary(int a[], int n, int &start, int &end)
        {
            /* Max subarray must be ended with i(0<=i<=n-1)
             * let sum(j) is the sum of the max subarray ended at j, then
             * max_sum_of_subarray = max{sum(0),sum(1),...,sum(n-1)}
             * Obviously, sum(k) = (sum(k-1)>0)*sum(k-1)+ a[k]
             */
            int k=0, sum=a[0], maxsum=a[0];
            start = end = 0;
            for(int i=1; i<n; i++) {
                if(sum<0) {
                    sum = a[i];
                    k = i;
                } else sum += a[i];

                if(maxsum<sum) {
                    maxsum = sum;
                    start = k;
                    end = i;
                }
            }
            return maxsum;
        }
        int find_maxsubary(int A[], int n)
        {
            /* Max subarray must be ended with i(0<=i<=n-1)
             * let sum(j) is the sum of the max subarray ended at j, then
             * max_sum_of_subarray = max{sum(0),sum(1),...,sum(n-1)}
             * Obviously, sum(k) = (sum(k-1)>0)*sum(k-1)+ a[k]
             */
            int sum=A[0], maxsum=A[0];
            for(int i=1; i<n; i++) {
                sum = ((~((sum>0)-1)) & sum)+A[i];
                maxsum = ((~((sum>maxsum)-1)) & sum)+((~((sum<=maxsum)-1)) & maxsum);
            }
            return maxsum;
        }
}
int main(int argc, char *argv[])
{
        int a[] = {-2,1,-3,4,-1,-2,1,-5,9};
        int start=0, end=8;
        Solution ss;
        while(start<=end) cout << a[start++] <<" ";
        cout << endl;
        cout << ss.find_maxsubary(a,9,start,end)<< endl;
        cout << ss.find_maxsubary(a,9)<< endl;
        while(start<=end) cout << a[start++] <<" ";
        cout << endl;
        return 0;
}

