class Solution {
    vector<vector<int>> cubs;
    int n;
    vector<vector<int>> memory;

    int LIS(int i, int prev) {
        if(i == n) {
            return 0;
        }

        int &ans = memory[i][prev];
        if(ans != -1) {
            return ans;
        }

        int takeOption{};
        if(prev == n || (cubs[i][0] >= cubs[prev][0] && cubs[i][1] >= cubs[prev][1] && cubs[i][2] >= cubs[prev][2])) {
            takeOption = cubs[i][2] + LIS(i + 1, i);
        }
        int leaveOption = LIS(i + 1, prev);

        return ans = max(takeOption, leaveOption);
    }
    

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        cubs = cuboids;
        n = cubs.size();
        memory.resize(n, vector<int>(n + 1, -1));
        
        return LIS(0, n);
    }
};
