ll max_sum(vector<ll>&vec, ll n, ll k) {
    ll max_sum{};
    for(ll i{}; i<=n-k; i++) {
        ll sum{};
        for(ll j{}; j<k; j++)
            sum += vec[i];
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}
