#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int> > permute_recursive(vector<int> &num) {
        vector<vector<int> > ret;
        if(num.size()==1){
                vector<int> v;
                v.push_back(num[0]);
                ret.push_back(v);
                return ret;
        }

        int val = num.back();
        num.pop_back();
        vector<vector<int> > lower = permute_recursive(num);

        for(int i=0; i<lower.size(); i++){
                for(int pos=0; pos<lower[i].size()+1; pos++){
                        vector<int> v;
                        for(int m=0,n=0; m<=pos || n<lower[i].size(); m++){
                                if(m==pos) v.push_back(val);
                                else v.push_back(lower[i][n++]);
                        }
                        ret.push_back(v);
                }
        }
        return ret;
}


void print(vector<vector<int> > v)
{
        for(int i=0; i<v.size(); i++){
                for(int j=0; j<v[i].size(); j++){
                        cout << v[i][j]<< " ";
                }
                cout << endl;
        }
}

#define SIZ 128
int a[SIZ];

int main()
{

        int n = 7;
        for(int i=0; i<n; i++) a[i] = i+1;

        vector<int> v(a, a+n);
        vector<vector<int> > vv = permute_recursive(v);
        print(vv);
        return 0;
}
