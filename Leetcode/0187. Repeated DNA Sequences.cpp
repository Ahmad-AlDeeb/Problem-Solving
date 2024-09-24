class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> answer;
        if(s.size() <= 10) {
            return answer;
        }

        unordered_map<string, int> count;
        string substr;

        for(int i{}; i < 10; ++i) {
            substr += s[i];
        }
        count[substr]++;

        for(int i{10}; i < s.size(); ++i) {
            substr += s[i];
            substr.erase(0, 1);
            count[substr]++;

            if(count[substr] == 2) {
                answer.push_back(substr);
            }
        }
        return answer;

    }
};
