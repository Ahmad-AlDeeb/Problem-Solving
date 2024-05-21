class Solution {
public:
    bool is_valid(string s) {
        // Single punctuation case
        if(s.size() == 1 && (s.front() == '!' || s.front()=='.' || s.front()==',')) 
            return true;

        // Checking first char
        if(!islower(s.front()))
            return false;
        
        // Checking last char
        if(isdigit(s.back()) || s.back()=='-')
            return false;

        // Checking the rest of chars
        bool found_hyphen{false};
        for(int i{1}; i<s.size()-1; i++)
            if(!islower(s[i])) {
                if(s[i] == '-' && !found_hyphen)  {
                    found_hyphen = true;
                    if(!islower(s[i-1]) || !islower(s[i+1]))
                        return false;
                }
                else 
                    return false;
            }

        // Survived?
        return true;
    }
    
    int countValidWords(string sentence) {
        string current_word;
        
        int ans{};
        for(auto c : sentence) {
            if(c != ' ') 
                current_word += c;
            else {
                if(is_valid(current_word))
                    ans++;
                current_word.clear();
            }
        }

        if(is_valid(current_word))
            ans++;

        return ans;
    }
};
