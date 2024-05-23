class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int g = std::gcd(str1.size(), str2.size());

        
        for(int i{}, j{}; i<str1.size(); i++, j++, j%=g) 
            if(str1[i] != str1[j])
                return "";

        for(int i{}, j{}; i<str2.size(); i++, j++, j%=g) 
            if(str2[i] != str1[j])
                return "";
        
        string answer;
        for(int i{}; i<g; i++)
            answer += str1[i];
        return answer;
    }
};
