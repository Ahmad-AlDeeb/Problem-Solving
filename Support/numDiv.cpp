ll numDiv(ll n) {
    ll cnt{1};
    for(ll i{2}; i*i<=n; i++) {
        ll power{};
        while(n%i==0) n/=i, power++;
        cnt *= power + 1;
    }
    return (n!=1)? cnt*2:cnt; // last factor = n^1
}
