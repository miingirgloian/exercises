#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> left, right;

        for(int i=0; i<s.size(); i++){
            left.push(s[i]);
        }

        while(!left.empty()){
            if(right.empty() || !match(left.top(), right.top())) {
                right.push(left.top());
                left.pop();
            } else {
                left.pop();
                right.pop();
            }
        }

        return right.empty();
    }
    bool match(char a, char b)
    {
        return (a=='('&&b==')' || a=='['&&b==']' || a=='{'&&b=='}');
    }
};
int main()
{
    string str("()0");
//    string str("()[]{}");
//    string str("([)]");
//    string str("())");
    Solution ss;
    cout<< ss.isValid(str) << endl;
    return 0;
}
