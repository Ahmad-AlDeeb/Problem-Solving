#define ll long long
class Solution {
public:
    int scoreOfParentheses(string s) {
        ll lvl{}, ans{};
        for(int i{}; i<s.size(); i++) {
            if(s[i]=='(' && s[i+1]==')') {
                ans+=pow(2LL,lvl);
                i++;
            }
            else if(s[i]=='(') lvl++;
            else               lvl--;
        }
        return ans;
    }
};
