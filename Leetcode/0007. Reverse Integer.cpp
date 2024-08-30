class Solution {
public:
    unsigned int getInt(vector<int> &digits) {
        // Remove left zeros
        int i = digits.size()-1;
        while(i>=0 && !digits[i])
            i--;

        // Calculate the answer
        unsigned int answer{};
        for(int power{}; i>=0; i--,power++) 
            answer += pow(10, power) * digits[i];
        return answer;
    }

    int reverse(int x) {
        bool negative{false};
        if(x < 0) negative = true;
        x = abs(x);

        vector<int> digits;
        while(x) {
            digits.push_back(x%10);
            x /= 10;
        }

        
        unsigned int answer{};
        if(digits.size() < 10)
            answer = getInt(digits);
        else {
            int first = digits.front();

            if(first > 2) 
                return 0;
            else if(first == 2) {
                answer = getInt(digits);
                
                if(answer-1 > INT_MAX) 
                    return 0;
                else if(answer-1 == INT_MAX && negative)
                    return answer * -1;
                    
            }
            else 
                answer = getInt(digits);
        }
        
        if(negative) 
            return answer * -1;
        else    
            return answer;
    }
};
