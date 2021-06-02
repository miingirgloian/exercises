#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        string str;
        int i,j;
        for(vector<string>::iterator it = tokens.begin(); it!=tokens.end(); it++){
            str = *it;
            if(str.size()!= 1 || str[0]>='0'&&str[0]<='9') st.push(str2int(str));
            else {
                i = st.top();
                st.pop();
                j = st.top();
                st.pop();
                switch (str[0]){
                case '+':
                    st.push(i+j);
                    break;
                case '-':
                    st.push(j-i);
                    break;
                case '*':
                    st.push(i*j);
                    break;
                case '/':
                    st.push(j/i);
                    break;
                default:
                    break;
                }
            }
        }
        return st.top();
    }
    int str2int(string str)
    {
        int n = 0, flag = 1, i;
        if(str[0]!='-') i = 0;
        else {
                i = 1;
                flag = -1;
        }
        for(; i<str.size(); i++){
            n *= 10;
            n += str[i]-'0';
        }
        return n*flag;
    }
};
int main()
{
    string str1[] = {"2","1","+","3","*"};
    string str3[] = {"4","13","5","/","+"};
    string str[] = {"-1","1","*","1","+"};
    vector<string> v;
    for(int i=0; i<5; i++){
        v.push_back(str[i]);
    }
    Solution ss;
    cout<< ss.evalRPN(v) << endl;
    return 0;
}
