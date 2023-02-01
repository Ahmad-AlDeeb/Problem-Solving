vector<ll> sieve(ll n) {
    vector<bool>primes(n+1,true);
    for(ll i{2}; i*i<=n; i++)
        if(primes[i])
            for(ll j{i*i}; j<=n; j+=i)
                primes[j]=false;

    vector<ll>ans;
    for(ll i{2}; i<=n; i++)
        if(primes[i]) ans.pb(i);
    return ans;
}
