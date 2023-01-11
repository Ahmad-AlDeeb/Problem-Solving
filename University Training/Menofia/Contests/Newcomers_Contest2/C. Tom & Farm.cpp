                                        // problem link: https://codeforces.com/group/jfviGllBoY/contest/379280/problem/C
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
    int dot{}; vector<int> row, col;

    char farm[n][m], cell;
    for(int i{}; i<n; i++)
        for(int j{}; j<m; j++) {
            cin >> farm[i][j];
            if(farm[i][j] == '.') {
                row.push_back(i);
                col.push_back(j);
            }
        }


    for(int i{}; i<row.size(); i++) {
        int x{row.at(i)}, y{col.at(i)};

        if(x+1<n && farm[x+1][y] == 'c') continue; // down
        if(x-1>=0 && farm[x-1][y] == 'c') continue; // up
        if(y+1<m && farm[x][y+1] == 'c') continue; // right
        if(y-1>=0 && farm[x][y-1] == 'c') continue; // left

        if(x+1<n && y-1>=0 && farm[x+1][y-1] == 'c') continue; // down-left
        if(x+1<n && y+1<m && farm[x+1][y+1] == 'c') continue; // down-right
        if(x-1>=0 && y-1>=0 && farm[x-1][y-1] == 'c') continue; // up-left
        if(x-1>=0 && y+1<m && farm[x-1][y+1] == 'c') continue; // up-right

        dot++;
    }
    cout << dot;
}
