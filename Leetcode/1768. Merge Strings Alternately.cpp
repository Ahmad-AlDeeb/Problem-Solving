class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer;
        
        int i{};
        for(; i<word1.size() && i<word2.size(); i++) {
            answer += word1[i];
            answer += word2[i];
        }

        for(; i<word1.size(); i++)
            answer += word1[i];

        for(; i<word2.size(); i++)
            answer += word2[i];

        
        return answer;    
    }
};
