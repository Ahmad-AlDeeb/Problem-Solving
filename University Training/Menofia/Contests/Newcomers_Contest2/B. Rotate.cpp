                                        // problem link: https://codeforces.com/group/jfviGllBoY/contest/379280/problem/B
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
    ll matrix[m][n];
    for(int j{n-1}; j>=0; j--)
        for(int i{}; i<m; i++)
            cin >> matrix[i][j];

    for(int i{}; i<m; i++) {
        for(int j{}; j<n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

}
