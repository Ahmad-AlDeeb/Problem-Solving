///////////////// O(n) - O(n) /////////////////
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_left(n), max_right(n), min_max(n);
        
        // Get the max left for each element.
        int mx = height.front();
        for(int i{1}; i<n; i++) {
            max_left[i] = mx;
            mx = max(mx, height[i]);
        }
        
        // Get the max right for each element.
        mx = height.back();
        for(int i{n-2}; i>=0; i--) {
            max_right[i] = mx;
            mx = max(mx, height[i]);
        }

        // Get the minimum of max left and max right for each element.
        for(int i{}; i<n; i++) {
            min_max[i] = min(max_left[i], max_right[i]);
        }

        // Calculate the answer
        int answer{};
        for(int i{}; i<n; i++) {
            answer += max(0, min_max[i] - height[i]);
        }
        return answer;
    }
};


///////////////// O(n) - O(1) /////////////////
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int answer{};
        int max_left = height.front();
        int max_right = height.back();

        for(int l{1},r{n-2}; l<=r;) {
            
            if(max_left <= max_right) {
                answer += max(0, max_left - height[l]);
                max_left = max(max_left, height[l]);
                l++;
            }
            else {
                answer += max(0, max_right - height[r]);
                max_right = max(max_right, height[r]);
                r--;
            }
            
        }
        return answer;
    }
};
