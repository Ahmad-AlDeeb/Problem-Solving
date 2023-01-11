                                                    // problem link: https://codeforces.com/problemset/problem/816/B
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

void accumulate(vector<int> &vec) { // accumulate vector values
    for(ll i{1}; i<vec.size(); i++)
        vec[i] += vec[i-1];
}

int main() { IOS
    ll n{}, k{}, q{}; cin >> n >> k >> q;
    // where the index is the temperature value & the value is vote count
    vector<int> vote (200002, 0); // size is 200,000 + 2 | one for indexing starts from 0 and another for vote[r+1] line

    ll l, r;
    for(ll i{}; i<n; i++) { //  to get votes for all temp from all recipes
        cin >> l >> r;
        vote[l] += 1; // starting temp for the recipe
        vote[r+1] -= 1; // ending temp for the recipe
    }
    accumulate(vote); //  increment votes for each temperature in each recipe range from l to r

    for(int v{}; v<vote.size(); v++) { // converting the temp that has at least k votes to 1 and others to 0 so we can accumulate them later
        if(vote[v] >= k) vote[v] = 1;
        else vote[v] = 0;
    }
    accumulate(vote); // increment count for each temperature in each question range from l(or a) to r(or b)

    for(ll i{}; i<q; i++) { // by getting accumulative sum on r minus accumulative sum before l we know how many good temp in range
        cin >> l >> r;
        cout << vote[r] - vote[l-1] << endl;
    }
}
