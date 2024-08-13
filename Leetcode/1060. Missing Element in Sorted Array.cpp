class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int answer{1};
        int l{answer}, r{n};
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(!binary_search(arr.begin(), arr.end(), mid)) {
                return mid;
            }
            
            if(arr[mid-1] != mid) {
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
