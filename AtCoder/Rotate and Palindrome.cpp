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
#include<map>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>

string s;
ll make_palindrome_cost(int start, ll b, ll a) {
    ll cost{};

    for(ll end=s.size()-1; start<end; start++,end--)
        if(s[start] != s[end])
            cost+=b;
    return cost+a;
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n,a,b;  cin >> n >> a >> b >> s;
    vector<ll>costs;
    ll size = s.size();

    for(ll i{},extra{}; i<size; i++,extra+=a) {
        costs.push_back(make_palindrome_cost(i,b,extra));
        s.push_back(s[i]);
    }

    sort(costs.begin(),costs.end());
    cout << costs.front();
}
