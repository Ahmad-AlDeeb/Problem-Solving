class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t min_size{200};
        for(auto str : strs)
            min_size = min(min_size, str.size());

        string answer;
        for(int i{}; i<min_size; i++) {
            bool success{true};
            char tar = strs[0][i];

            for(int j{}; j<strs.size(); j++)
                if(strs[j][i] != tar)
                    success = false;

            if(success)
                answer += tar;
            else
                break;
        }
            

        return answer;
    }
};
