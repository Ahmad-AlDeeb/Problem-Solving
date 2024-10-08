const int N = 500 + 1;

class Solution {
int memory[N][N];
string w1, w2;
int n1, n2;

int getMin(int i, int j) {
    if(i == n1 || j == n2) {
        return max((n1 - i), (n2 - j));
    }

    int &answer = memory[i][j];
    if(answer != -1) {
        return answer;
    }

    if(w1[i] == w2[j]) {
        return answer = getMin(i + 1, j + 1);
    }

    int changeOperation = 1 + getMin(i + 1, j + 1);
    int insertOperation = 1 + getMin(i    , j + 1);
    int deleteOperation = 1 + getMin(i + 1, j    );

    return answer = min({changeOperation, insertOperation, deleteOperation});
}

void printSteps(int i, int j) {
    if(i == n1 && j == n2) {
        return;
    }
    if(i == n1) {
        cout << w2.substr(j) << " was inserted at the end of " << w1 << endl;
        return;
    }
    else if(j == n2) {
        cout << w1.substr(i) << " was inserted at the end of " << w2 << endl;
        return;
    }

    int optimal = getMin(i, j);

    int changeOperation = 1 + getMin(i + 1, j + 1);
    int insertOperation = 1 + getMin(i    , j + 1);
    int deleteOperation = 1 + getMin(i + 1, j    );

    if(changeOperation == optimal) {
        cout << "Changed " << w1[i] << " in " << w1 << " to " << w2[j] << endl;
        printSteps(i + 1, j + 1);
    }
    else if(insertOperation == optimal) {
        cout << "Inserted " << w2[j] << " before " << w1[i] << endl;
        printSteps(i, j + 1);
    }
    else {
        cout << "Deleted " << w1[i] << " in " << w1 << endl;
        printSteps(i + 1, j);
    }
}

public:
    int minDistance(string word1, string word2) {
        w1 = word1;
        w2 = word2;
        n1 = w1.size();
        n2 = w2.size();
        memset(memory, -1, sizeof(memory));

        printSteps(0, 0);
        return getMin(0, 0);
    }
};
