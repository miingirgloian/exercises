/*
 *Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 *For example,
 *Given:
 *s1 = "aabcc",
 *s2 = "dbbca",
 *
 *When s3 = "aadbbcbcac", return true.
 *When s3 = "aadbbbaccc", return false.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
        public:
                bool isInterleave(string s1, string s2, string s3)
                {
                        int i=0, j=0;
                        int len1 = s1.size(), len2 = s2.size();
                        if(len1+len2!=s3.size()) return false;


                        /*
                         *f(i,j)==1 indicates that substring (0,i-1) of s1 and 
                         *substring (0,j-1) of s2 is interleave of substring (0,i+j-1) of s3 
                         */

                        //vector<vector<bool> > f (len1+1,vector<bool>(len2+1, true));
                        //The line above is equvlent to the following commented lines 

                        bool **f = new bool* [len1+1];
                        for(i=0; i<len1+1; i++){
                                f[i] = new bool [len2+1];
                        }

                        f[0][0] = true;
                        for(i=1; i<len1+1; i++){
                                        f[i][0] = (s1[i-1]==s3[i-1] && f[i-1][0]);
                        }
                        for(i=1; i<len2+1; i++){
                                        f[0][i] = (s2[i-1]==s3[i-1] && f[0][i-1]);
                        }

                        for(i=1; i<=len1; i++){
                                for(j=1; j<=len2; j++){
                                        //if(s3[i+j-1]==s1[i-1] && s3[i+j-1]==s2[j-1]) 
                                                //f[i][j] = (f[i-1][j]||f[i][j-1]);
                                        //else if(s3[i+j-1]==s1[i-1]) f[i][j] = f[i-1][j];
                                        //else if(s3[i+j-1]==s2[j-1]) f[i][j] = f[i][j-1];
                                        //else f[i][j] = fflse;
                                        f[i][j] = (s3[i+j-1]==s1[i-1] && f[i-1][j]) || (s3[i+j-1]==s2[j-1] && f[i][j-1]);
                                }
                        }

                        return f[len1][len2];
                }
};

int main(int argc, char *argv[])
{
        string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
        string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
        string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
        
        Solution ss;
        cout << ss.isInterleave("", "", "") << endl;
        cout << ss.isInterleave(s1, s2, s3) << endl;
        cout << ss.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
        cout << ss.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
        cout << ss.isInterleave("ab", "bc", "bbac") << endl;
        cout << ss.isInterleave("a", "b", "ab") << endl;
        return 0;
}
