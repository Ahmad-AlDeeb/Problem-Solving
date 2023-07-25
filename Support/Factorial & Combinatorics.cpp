ll PP_fact(ll n, ll p) { // Legendre's formula
    ll exp{};
    for(ll i{p}; i<=n; i*=p)
        exp += n/i;
    return exp;
}
ll fact(ll n) {
    if(n <= 1) return 1;
    return (n * fact(n-1));
}
ll perm(ll n, ll r) {
    ll ans{1};
    for(ll i{n}; i>=n-r+1; i--) {
        ans *= i;
        ans %= M;
    }
    return ans;
}
ll comb(ll n, ll r) {
    ll ans{1}, div{1};
    for(ll i{r+1}; i<=n; i++) {
        ans *= i;
        ans /= div;
        div++;
    }
    return ans;
}
// CP-4 Combination calculation from Binomial Coefficient section page 36 (2nd book)
ll mod_pow(ll b, ll p, ll m) {
    if(!p) return 1;

    ll ans = mod_pow(b,p/2,m);
    ans = mod(ans*ans,m);

    if(p&1) ans = mod(ans*b,m);
    return ans;
}
// M is a prime number > N
ll inv(ll a) {     // Fermat's little theorem
    return mod_pow(a,M-2,M); // O(log p)
}
ll Fact[N];
void ini_fact() { // O(n)
    Fact[0]=1;
    for(ll i{1}; i<N; i++)
        Fact[i] = (Fact[i-1]*i) % M;
}
ll C(ll n, ll k) {
    if(n<k) return 0;
    return ( ((Fact[n] * inv(Fact[k]))%M) * inv(Fact[n-k]) ) % M;
}
ll Cat[N];
void ini_cat() {
    Cat[0]=1;
    for(ll n{}; n<N-1; n++)
        Cat[n+1] = ((4*n+2)%M * Cat[n]%M * inv(n+2)%M);
}
