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
const ll P = 1e9+7;
ll inv(ll a) {
    return mod_pow(a,P-2,P);
}
ll Fact[100010];
ll C(ll n, ll k) {
    if(n<k) return 0;
    return ( ((Fact[n]*inv(Fact[k]))%P) * inv(Fact[n-k]) ) % P;
}
void ini_fact() { // O(n)
    Fact[0]=1;
    for(ll i{1}; i<100010; i++)
        Fact[i] = (Fact[i-1]*i) % P;
}
