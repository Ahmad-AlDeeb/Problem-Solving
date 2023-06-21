// source: CP-4 Part (2) Page (22-23)
// get count of divisors without getting divisors (using fun fact of prime factors)
ll numDiv(ll n) {
    ll cnt{1};
    for(ll i{2}; i*i<=n; i++) {
        ll power{};
        while(n%i==0) n/=i, power++;
        cnt *= power + 1;
    }
    return (n!=1)? cnt*2:cnt; // last factor = n^1
}
// get sum of divisors without getting divisors (using geometric progression + fun fact of prime factors)
ll sumDiv(ll n) {
    ll ans{1};
    for(ll i{2}; i*i<=n; i++) {
        ll multi{i}, sum{1};;
        while(n%i == 0) {
            n /= i;
            sum += multi;
            multi *= i;
        }
        ans *= sum;
    }
    if(n != 1) ans *= (n+1); // N^2-1/N-1 = N+1
    return ans;
}
