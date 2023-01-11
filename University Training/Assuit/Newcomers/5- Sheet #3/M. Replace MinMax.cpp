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
    int n{}; cin >> n; vector<int>vec;
    int max{-100000}, mini{100000}, max_i{}, mini_i{};
    for(int i{}; i<n; i++) {
        int x{}; cin >> x; vec.push_back(x);
        if(x >= max) {max=x; max_i=i;}
        if(x <= mini) {mini = x; mini_i=i;}
    }
    vec[max_i] = mini;
    vec[mini_i] = max;
    for(int num:vec) cout << num << " ";
}
