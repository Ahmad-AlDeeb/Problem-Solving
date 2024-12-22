class Solution {

public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);

        long long currentNumber;
        for(int i{}; i < n; i++) {
            currentNumber = *s.begin();
            s.erase(s.begin());

            s.insert(currentNumber * 2);
            s.insert(currentNumber * 3);
            s.insert(currentNumber * 5);
        }
        return currentNumber;
    }
};
