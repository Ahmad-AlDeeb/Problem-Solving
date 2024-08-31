class Solution {
public:
    bool isValid(string s) {
        map<char,char> match;
        match['}']='{';
        match[']']='[';
        match[')']='(';
        
        stack<char> st;
        for(int i{}; i<s.size(); i++) {
            // closing 
            if(s[i]=='}' || s[i]==']' || s[i]==')') {
                if(st.empty() || match[s[i]] != st.top())
                    return false;
                st.pop();
            }
            // opening
            else st.push(s[i]);
        }

        if(st.empty()) return true;
        else           return false;
    }
};
