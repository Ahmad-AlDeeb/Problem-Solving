class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans{{arr[0], arr[1]}};
        int min_difference {arr[1]-arr[0]};

        for(int i{1}; i<arr.size()-1; i++) {
            int difference = arr[i+1] - arr[i];
            if(difference < min_difference) {
                ans.clear();
                min_difference = difference;
                ans.emplace_back(vector<int> {arr[i], arr[i+1]});
            } 
            else if (difference == min_difference) {
                ans.emplace_back(vector<int> {arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};
