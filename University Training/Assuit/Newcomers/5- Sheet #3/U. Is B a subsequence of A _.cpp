// problem: Gym - 351820D
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

    vector<int> a(n,0);
    for(int i{}; i<n; i++) cin >> a[i];
    vector<int> b(m,0);
    for(int i{}; i<m; i++) cin >> b[i];


    for(int j{}; j<m; j++) {
        bool success{false};
        for(int i{}; i<a.size(); i++)
            if(a.at(i)!=b.at(j))
                {a.erase(a.begin()+i); i--;}
            else {
                a.erase(a.begin()+i); i--;
                success=true; break;
            }
        if(!success) {cout << "NO"; return 0;}
    }
    cout << "YES";
}
