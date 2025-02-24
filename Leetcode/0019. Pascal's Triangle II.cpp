class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;

        for(int i{}; i <= rowIndex; ++i) {
            vector<int> current(i + 1);
            current.front() = current.back() = 1;
            for(int j{1}; j < current.size() - 1; ++j) {
                current[j] = prev[j - 1] + prev[j];
            }
            prev = current;
        }
        return prev;
    }
};
