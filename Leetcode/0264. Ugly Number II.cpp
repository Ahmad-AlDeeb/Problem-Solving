////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Using Set Solution  /////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Using Min Heap solution /////////////////////////////
class Solution {

public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long>> pq;
        unordered_set<long long> seenNumbers;
        vector<int> primeNumbers {2, 3, 5};
        
        pq.push(1);
        seenNumbers.insert(1);

        long long currentNumber;
        for(int i{}; i < n; i++) {
            currentNumber = pq.top();
            pq.pop();

            for(auto primeNumber : primeNumbers) {
                long long newNumber = primeNumber * currentNumber;
                
                if(seenNumbers.count(newNumber) == 0) {                    
                    seenNumbers.insert(newNumber);
                    pq.push(newNumber);
                }
            }
        }
        return currentNumber;
    }
};

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Using DP ////////////////////////////////////
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> uglyNumbers(n);
        uglyNumbers[0] = 1;

        int index2{}, index3{}, index5{};
        int multipleOf2 = 2;
        int multipleOf3 = 3;
        int multipleOf5 = 5;

        for(int index{1}; index < uglyNumbers.size(); index++) {

            uglyNumbers[index] = min({multipleOf2, multipleOf3, multipleOf5});

            if(multipleOf2 == uglyNumbers[index]) {
                index2++;
                multipleOf2 = 2 * uglyNumbers[index2];
            }
            if(multipleOf3 == uglyNumbers[index]) {
                index3++;
                multipleOf3 = 3 * uglyNumbers[index3];
            }
            if(multipleOf5 == uglyNumbers[index]) {
                index5++;
                multipleOf5 = 5 * uglyNumbers[index5];
            }
        }
        return uglyNumbers[n - 1];
    }
};
