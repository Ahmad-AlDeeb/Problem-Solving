class Solution {
public:
    int getArea(vector<int>& height, int l, int r) {
        return min(height[l],height[r]) * abs(l-r);
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        int answer{};

        for(int left{}, right{n-1}; left<right;) {
            answer = max(answer, getArea(height, left, right));
            
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return answer;
    }
};
