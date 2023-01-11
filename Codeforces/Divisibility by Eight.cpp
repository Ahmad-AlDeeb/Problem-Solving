                                                    // problem link: https://codeforces.com/problemset/problem/550/C
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
    string num; cin >> num;
    vector<int> dig (num.size(), 0);
    for(int i{}; i<num.size(); i++)
        dig[i] = num[i] - '0'; // Subtracting '0' to convert each character into digit


    int ans{};
    for(int i{}; i < dig.size(); i++) {
        if(dig[i]==0 || dig[i]==8) {cout << "YES" << endl << dig[i]; return 0;}

        for(int j{i+1}; j<dig.size(); j++) {
            ans = (dig[i]*10) + dig[j]; // we concat 2 digits and check its devisability by 8
            if (ans % 8 == 0) {cout << "YES" << endl << ans; return 0;}

            for(int k{j+1}; k<dig.size(); k++) {
                ans = (dig[i]*100) + (dig[j]*10) + dig[k]; // we concat 3 digits and check its devisability by 8
                if (ans % 8 == 0) {cout << "YES" << endl << ans; return 0;}
            }
        }
    }
    cout << "NO";
}
