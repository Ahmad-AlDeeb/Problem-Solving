class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        while(a.size() < b.size())
            a += "0";
        while(b.size() < a.size())
            b += "0";

        string sum;
        int carry{};
        for(int i{}; i<a.size(); i++) {
            int dig1 = a[i] - '0';
            int dig2 = b[i] - '0';
            int result = dig1 + dig2 + carry;

            if(result < 2) {
                sum += result + '0';
                carry = 0;
            }
            else if(result == 2) {
                sum += "0";
                carry = 1;
            }
            else if(result == 3) {
                sum += "1";
                carry = 1;
            }
        }
        if(carry) sum += "1";

        reverse(sum.begin(), sum.end());
        return sum;
    }
};
