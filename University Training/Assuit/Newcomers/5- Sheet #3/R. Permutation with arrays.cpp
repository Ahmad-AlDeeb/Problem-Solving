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
    int n{}; cin >> n;
    vector<int> a(n,0), b(n,0);
    for(int i{}; i<n; i++) cin >> a[i];
    for(int i{}; i<n; i++) cin >> b[i];


    for(int i{}; i<n; i++) {
        bool success{false};
        for(int j{}; j<n; j++)
            if(a[i] == b[j]) {
                b.erase(b.begin()+j);
                success = true;
                break;
            }
        if(!success) {cout << "no"; return 0;}
    }
    cout << "yes";
}
