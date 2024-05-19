class Solution {
public:
    map<int,int> cache;
    int tribonacci(int n) {
        if(n == 0) 
            return 0;
        if(n == 1 || n == 2) 
            return 1;
        
        if(cache.find(n) != cache.end())
            return cache[n];

        cache[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

        return cache[n];
    }
};
