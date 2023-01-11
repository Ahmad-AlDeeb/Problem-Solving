                                                    // problem link: https://atcoder.jp/contests/abc084/tasks/abc084_c
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
//#define S second
//#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    int n{}; cin >> n; n--; // we decrement number of station since we don't care about final station
    vector<int> C(n, 0), S(n, 0), F(n, 0); // vector for each time wait type
    for(int i{}; i<n; i++) // we store each vector with its time type
            { cin >> C[i]; cin >> S[i]; cin >> F[i]; }

    for(int i{}; i<n; i++) { // first loop print minimum time for each station
        ll t{ S[i] }; // we start time count with S time for i station
        for(int j{i}; j<n; j++) {
            t += C[j]; // increment each travel time to next station
            if(j == n-1) break; // if we reach last destination we stop

            // if starting time of next station is more than the time we needed to reach it, then update time with the new starting time.
            if(S[j+1] > t)
                t = S[j+1];
            else if(t % F[j+1] != 0) // if we reach the station after starting time but not at departure time, we wait for it.
                t += (F[j+1] - t%F[j+1]);
        }
        cout << t << endl;
    }
    cout << 0;
}
