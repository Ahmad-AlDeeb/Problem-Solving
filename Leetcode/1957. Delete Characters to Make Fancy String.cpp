class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char current = '.';
        int count{};
        for(int i{}; i<s.size(); i++) {
            if(current == s[i]) {
                count++;
                if(count >= 3) continue;
            }
            else {
                current = s[i];
                count = 1;
            }

            ans += s[i];
        }

        return ans;
    }
};
