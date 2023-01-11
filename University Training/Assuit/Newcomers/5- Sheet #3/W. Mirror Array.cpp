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
    int matrix[n][m];
    for(int i{}; i<n; i++)
        for(int j{}; j<m; j++)
            cin >> matrix[i][j];

    for(int i{}; i<n; i++) {
        for(int j{m-1}; j>=0; j--)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
