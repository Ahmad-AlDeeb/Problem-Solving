                                                    // problem link: https://codeforces.com/problemset/problem/16/A
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
    int n{}, m{}; cin >> n >> m;

    char flag[n][m], color{}; cin.get(color); // to read first /n character in the first line
    for(int i{}; i<n; i++) { // loop on each row
        for(int j{}; j<m+1; j++) { // loop on each column
            cin.get(color); // we read one digit as char

            // if it's the first digit in the row, we continue as there's no prev. digit to compare
            if(j==0) {flag[i][j] = color; continue;} 
            if(j==m) break; // if it's the last digit in the row, it's actually not a digit but it's a space indicating end of row
            else flag[i][j] = color; // if it's not the first or last digit we just assign what we read to the matrix flag

            if(flag[i][j] != flag[i][j-1]) // we compare only if it's not the first digit and if they are not the same,
                {cout << "NO"; return 0;} // then our ans is no and we return
        }
        if(i==0) continue; // if we are at the first row we can't compare the prev row so we just continue
        if(flag[i][0] == flag[i-1][0]) {cout << "NO"; return 0;} // otherwise we compare and if they are the same, ans is no
    }
    cout << "YES"; // if it pass all conditions in the 2 loops then our ans must be YES
}
