#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
        if(!n) return 0;
        int index = 0;
        for(int i=1; i<n; i++)
                if(A[index]!=A[i]) A[++index] = A[i];
        return index+1;
}

int main(int argc, char *argv[])
{
        int a[]= {1,1,2,2,2,2,2,2};
        int n = removeDuplicates(a,8);
        for(int i=0; i<n; i++) cout <<a[i] << " " ;
        cout << endl;
        return 0;
}
