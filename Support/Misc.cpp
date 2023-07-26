// CONST Variables
const vll di {0,0,1,-1};
const vll dj {1,-1,0,0};
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ld PI = 3.14159265358979323846;
// Ordered Set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set 

tree<long long, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
////////////////////////////////////////////////////////////
void coordinate_compress(vll &axis, ll start=2, ll step=2) {
    set<ll> s (axis.begin(), axis.end());
    map<ll,ll> index;

    ll i{};
    for(auto val:s)
        index[val] = start + (step * i++);

    for(auto &val:axis)
        val = index[val];
}
void coordinate_compress(vll &axis, vll &values, map<ll,ll> &index, ll start=2, ll step=2) {
    for(auto &val:axis)
        index[val] = 0;
    values.resize(start + step*axis.size());

    ll i{};
    for(auto &p:index) {
        p.S = start + (step * i++);
        values[p.S] = p.F;
    }

    for(auto &val:axis)
        val = index[val];
}
pair<ld,ld> quad(ld a, ld b, ld c) {
    ld sq = sqrt(abs( (b*b)-4.0*a*c ));
    return {(-b+sq)/(2*a), (-b-sq)/(2*a)};
}
// Difference of 2 squares
ll a,b;
void get_squares(ll n) {
    for(ll i = sqrt(n); i >= 1; i--)
        if(n%i == 0) {
            ll c = i;   //a-b
            ll d = n/i; //a+b
            if((c+d)%2 == 0 && (c-d)%2 == 0) {
                a = (c + d) / 2;
                b = (d - c) / 2;
                return;
            }
        }
}
// maximum subarray with negative values (Kadane's algorithm)
ll max_sub(vll &v) {
    ll mx {-MAX}, sum{};
    for (ll i{}; i<v.size(); i++) {
        sum += v[i];
        mx = max(mx,sum);
        if (sum < 0) sum = 0;
    }
    return mx;
}
    /////////////// Stress testing /////////////////
   while(true) {
//        ll n = 2601;
       ll n = rand()%10+1;
       if(fast(n) == slow(n)) cout << n << " OK!\n";
       else {
           cout << "NOT MATCHED!\n";
           cout << n << endl << slow(n) << " " << fast(n);
           break;
       }
   }
