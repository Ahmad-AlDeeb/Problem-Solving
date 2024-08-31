class Solution {
public:
    int firstUniqChar(string s) {
        int exist[26];

        for(int i{}; i<s.size(); i++) 
            exist[s[i]-'a']++;
        
        int answer = -1;
        for(int i{}; i<s.size(); i++)
            if (exist[s[i]-'a'] == 1) {
                answer = i;
                break;
            }
        return answer;
    }
};
