                                                    // problem link: https://codeforces.com/problemset/problem/266/A
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
    int ans{}, n{}; string color{}; cin >> n >> color;

    for(int i{}; i<n-1; i++)
        if(color[i] == color[i+1]) { // compare current stone color and next one
            ans++; // if they are the same we increment count and start comparing current and all next
            int j{i+2};
            for(; j<n; j++)
                if(color[i] == color[j]) ans++;
                else break;

            i = j-1; // we set i to j-1 just before where we stopped as the loop will increment i
        }
    cout << ans;
}
