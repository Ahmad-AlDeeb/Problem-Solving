#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pcc pair<char, char>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    int a{}, b{}, c{};
    vector<int> sorted_num(3, 0);
    for(int i{}; i<3; i++)
        cin >> sorted_num.at(i);

    vector<int> num {sorted_num};
    sort(sorted_num.begin(), sorted_num.end());

    for(int i:sorted_num) cout << i << endl;
    cout << endl;
    for(int i:num) cout << i << endl;
}
