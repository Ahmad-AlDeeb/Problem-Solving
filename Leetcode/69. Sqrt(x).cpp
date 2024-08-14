class Solution {
public:
    int mySqrt(int x) {
        double l{0.0}, r{1000000000.0};
        for(int iter{}; iter<100; ++iter) {
            double mid = (l + r) / 2.0;
            if(mid * mid > x) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return l;
    }
};
