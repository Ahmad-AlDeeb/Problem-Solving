int const MAX = 1000 + 1;
enum {THICKNESS = 0, HEIGHT = 1};

class Solution {
    int memory[MAX];
    vector<vector<int>> b;
    int n, maxWidth;

    int getAnswer(int i) {
        if(i >= n) {
            return 0;
        }
        
        int &answer = memory[i];
        if(answer != -1) {
            return answer;
        }
        answer = INT_MAX;

        int totalWidth{}, maxHeight{};
        for(int j{i}; j < n; ++j) {
            totalWidth += b[j][THICKNESS];
            maxHeight = max(maxHeight, b[j][HEIGHT]);

            if(totalWidth > maxWidth) {
                break;
            }

            answer = min(answer, maxHeight + getAnswer(j + 1));
        }
        return answer;
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {        
        memset(memory, -1, sizeof(memory));
        b = books;
        n = b.size();
        maxWidth = shelfWidth;

        return getAnswer(0);
    }
};
