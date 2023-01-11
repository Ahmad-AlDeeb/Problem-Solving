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
    int a{}, b{}; cin >> a >> b;
    string a_bin = bitset<32>(a).to_string();
    string b_bin = bitset<32>(b).to_string();

    string sum{};
    for (int i=0; i<32; i++) {
        if (a_bin[i] == b_bin[i]) sum += "0";
        else sum += "1";
    }
    reverse(sum.begin(), sum.end());

    int ans{};
    for(int i{}; i<32; i++) {
        if(sum[i] == '0') continue;
        ans += pow(2,i);
    }
    cout << ans;
}
