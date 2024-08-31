class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        for(auto c:s) {
            if(isdigit(c) || isalpha(c)) 
                result.push_back(tolower(c));
        }

        int size = result.size();
        bool success {true};
        for(int i{},j{size-1}; i<size/2; i++,j--)
            if(result[i] != result[j]) success=false;
        return success;
    }
};
