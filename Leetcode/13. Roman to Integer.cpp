class Solution {
public:
    int romanToInt(string s) {
        map<char, int> value;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;

        int answer = value[s.back()];
        for(int i=s.size()-2; i>=0; i--) {
            int current = value[s[i]];
            
            if(current < value[s[i+1]])
                answer -= current;
            else
                answer += current;
        }
        return answer;
    }
};
