vll P; vector<bool> Prime(N,true);
void sieve() { // (1e7 < 1s) <-- O(n loglogn)
    Prime[0]= Prime[1]=false;

    for(ll i{2}; i<N; ++i) if(Prime[i]) {
            for(ll composite{i+i}; composite<N; composite+=i)
                Prime[composite]=false;
            P.pb(i);
        }
}
// 49 (N=11) (SZ=4)
// 10201 (N=102) (SZ=26)
// 994009 (N=1003) (SZ=168)
// 99460729 (N=10004) (SZ=1229)
// 10000600009 (N=100005) (SZ=9593)
// 1000006000009 (N=1000006) (SZ=78499)
// 99999820000081 (N=10000007) (SZ=664579)
bool prime(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    if(n < N) return Prime[n];
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i)
        if(n%P[i] == 0) return false;
    return true;
}
vll PF(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    vll factors;
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        while(n%P[i] == 0)
            n/=P[i], factors.pb(P[i]);
    }

    if(n!=1) factors.pb(n);
    return factors;
}
vll PF() {
    vll PF_cnt(10000007);
    for(ll i{2}; i<=PF_cnt.size(); ++i)
        if(!PF_cnt[i]) // if true then i is prime
            for(ll j{i}; j<=PF_cnt.size(); j+=i)
                ++PF_cnt[j];
    return PF_cnt;
}
vll div(ll x) {
    vll div;
    for(ll i{1}; i*i<=x; i++)
        if(x%i == 0) {
            div.pb(i);
            if(i*i != x) div.pb(x/i);
        }
    return div;
}
ll div_cnt(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    ll cnt{1};
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        ll power{};
        while(n%P[i] == 0) n/=P[i], ++power;
        cnt *= power+1;
    }
    return (n!=1)? 2*cnt:cnt;
}
ll div_sum(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    ll sum{1};
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        ll multi{P[i]}, total{1};
        while(n%P[i] == 0)
            n/=P[i], total+=multi, multi*=P[i];
        sum *= total;
    }

    if(n!=1) sum *= (n+1); // N^2-1/N-1 = N+1
    return sum;
}
vector<vll> multi(ll x) { // 2*1e6
    vector<vll> multi(x+1);
    for(ll div{1}; div<=x; div++)
        for(ll i{div}; i<=x; i+=div)
            multi[i].pb(div);
    return multi;
}
ll euler(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    ll co{n};
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        if(n%P[i] == 0) co -= co / P[i];
        while(n%P[i] == 0) n/=P[i];
    }

    if(n!=1) co -= co/n;
    return co;
}
vll euler() {
    vll co(10000007);
    for(ll i{1}; i<co.size(); ++i)
        co[i]=i;
    for(ll i{2}; i<co.size(); ++i)
        if(co[i]==i) // if  true then i is prime
            for(ll j{i}; j<=co.size(); j+=i)
                co[j] = (co[j]/i) * (i-1);
    return co;
}
