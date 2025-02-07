class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> count;
        vector<int> prefix(A.size());
        int counter{};

        for(int i{}; i < A.size(); ++i) {
            if(A[i] == B[i]) {
                counter++;
            }
            else {
                if(count[A[i]]++) {
                    counter++;
                }
                if(count[B[i]]++) {
                    counter++;
                }
            }

            prefix[i] = counter;
        }

        return prefix;
    }
};
