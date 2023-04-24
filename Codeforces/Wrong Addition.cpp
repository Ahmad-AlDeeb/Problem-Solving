#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e9+7;
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};
string letters{" abcdefghijklmnopqrstuvwxyz"};

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll tc; cin >> tc;
    while(tc--) {
        string a,s; cin >> a >> s;

        string b;
        ll j=s.size()-1;
        for(ll i=a.size()-1; i>=0&&j>=0; i--) {
            string temp;
            if(a[i] > s[j])
                temp = to_string(10-((a[i]-'0')-(s[j]-'0'))),j-=2;
            else temp = to_string((s[j]-'0')-(a[i]-'0')),j--;
            b += temp;
        }
        reverse(all(b));
        if(j!=-1)
            b = s.substr(0,j+1)+b;


        if(b.size()!=a.size()) {
            ll zeros = b.size()-a.size();
            zeros = abs(zeros);

            string temp;
            while(zeros--) temp.pb('0');
            if(a.size() < b.size()) a = temp+a; else b = temp+b;
        }



        string result;
        for(ll i=a.size()-1; i>=0; i--) {
            ll dig1 = a[i]-'0';
            ll dig2 = b[i]-'0';
            string temp = to_string(dig1+dig2);
            reverse(all(temp));
            result += temp;
        }
        reverse(all(result));

        reverse(all(b));
        while(b.back()=='0') b.pop_back();
        reverse(all(b));

        if(result == s) cout << b; else cout << -1;
        cout << endl;
    }
}
