class Solution {
public:
    int getBouquets(vector<int>& bloomDay, int k, int days) {
        int count{}, consecutive{};
        for(auto flower : bloomDay) {
            if(flower - days <= 0) {
                consecutive++;
                if(consecutive == k) {
                    count++;
                    consecutive = 0;
                }
            }
            else {
                consecutive = 0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long) m*k > bloomDay.size()) {
            return -1;
        }
        
        int answer{1000000000};
        int l{1}, r{answer};
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(getBouquets(bloomDay, k, mid) >= m) {
                r = mid - 1;
                answer = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return answer;
    }
};
