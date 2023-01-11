                                                    // problem: Gym - 351820A
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    char team, trash;
    cin.get(team); cin.get(trash);
    char board[3][3];

    for(int i{}; i<3; i++) { // we store board in 2 dimensional vector and check if any row has 2 of our team mark and one space
        int c1{}, c2{}; // counters for team mark and space
        for(int j{}; j<4; j++) {
            char mark; cin.get(mark);
            if(mark == '|') { // if we read | it means we are at the end of the row
                if(i==2) break; // if it was the last row we just break
                else {cin.get(trash); break;} // if not the last row then we read the trash extra space and break
            }
            board[i][j] = mark;
            if(mark == ' ') c1++;
            if(mark == team) c2++;
        }
        if(c1==1 && c2==2) {cout << "Yes you can."; return 0;} // if we have 2 of our mark and one space then we can win
    }
    for(int i{}; i<3; i++) { // loop over columns to check if any of them has 2 of our team mark and one spcae
        int c1{}, c2{}; // counters for team mark and space
        for(int j{}; j<3; j++) {
            if(board[j][i] == ' ') c1++;
            if(board[j][i] == team) c2++;
        }
        if(c1==1 && c2==2) {cout << "Yes you can."; return 0;} // if we have 2 of our mark and one space then we can win
    }
    int c1{}, c2{};
    for(int i{}; i<3; i++) { // left to right diagonal check
        if(board[i][i] == ' ') c1++;
        if(board[i][i] == team) c2++;
    }
    if(c1==1 && c2==2) {cout << "Yes you can."; return 0;}

    c1=0; c2=0;
    for(int i{}; i<3; i++) { // right to left diagonal check
        if(board[i][2-i] == ' ') c1++;
        if(board[i][2-i] == team) c2++;
    }
    if(c1==1 && c2==2) {cout << "Yes you can."; return 0;}

    cout << "No you can't."; // if we reach here, means we couldn't find any row or column that is missing one move to win
}
