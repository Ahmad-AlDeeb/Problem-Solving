class Solution {
public:
    double myPow(double x, int n) {
        if(!n) {
            return 1.0;
        }
        else if(!x) {
            return 0.0;
        }
        int absN = abs(n);
        bool isPositive = (x > 0 || ((absN % 2) == 0));

        double answer{1.0};
        while(absN) {
            if(absN&1) {
                answer *= x;
            }
            x *= x;
            absN /= 2;
        }
        
        if(n > 0) {
            return answer;
        }
        return 1/answer;
    }
};
