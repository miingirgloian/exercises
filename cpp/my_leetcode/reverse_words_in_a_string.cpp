//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//space not interesting must be cleared
#include <iostream>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        char c;
        int i, j, k;
        reduceSpace(s);
        int len = s.size();
        reverseWord(s, 0, len-1);
        i=0, j=0;
        int word_start=0;
        for(k=0; k<=len; k++){
            if(k==len || s[k] == ' ') {
                reverseWord(s, word_start, k-1);
                word_start = k+1;
            }
        }
    }
    void reduceSpace(string &s)
    {
        int space_count = 0;
        int i, k = 0;
        while(k<s.size()&& s[k]==' '){
            space_count++;
            k++;
        }
        s.erase(0,space_count);

        k = s.size()-1;
        space_count = 0;
        if(k>-1){
            while(s[k]==' '){
                space_count++;
                k--;
            }
            s.erase(k+1,space_count);
        }

        for(i=0; i<s.size(); i++){
            if(s[i]==' '){
                k = i+1;
                space_count = 0;
                while(k<s.size()&&s[k]==' '){
                    k++;
                    space_count++;
                }
                if(k<s.size()) s.erase(i+1, space_count);
            }
        }

    }
    void reverseWord(string &s, int start, int end)
    {
        char c;
        for(; start<end; start++,end--){
            c = s[start];
            s[start] = s[end];
            s[end] = c;
        }
    }
};

void print(string& s)
{
    int i=0;
    while(i<s.size()) {
        if(s[i]!=' ') cout << s[i];
        else cout<< '*';
        i++;
    }
    cout << endl;
}
int main()
{
    Solution ss;
    string s = " ";
    print(s);
    ss.reverseWords(s);
    print(s);
    return 0;
}
