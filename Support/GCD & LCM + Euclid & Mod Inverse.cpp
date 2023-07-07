ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}
ll extEuclid(ll a, ll b, ll &x, ll &y) {
    ll x2 = y = 0;
    ll y2  = x = 1;
    while(b) {
        ll q {a/b};

        ll temp{b};
        b = a%b;
        a = temp;

        temp = x2;
        x2 = x-(q*x2);
        x = temp;

        temp = y2;
        y2 = y-(q*y2);
        y = temp;
    }
    return a; // a here = d = gcd(a,b)
}
ll mod_inverse(ll b, ll m) { // returns [ b^(-1) % m ] if possible
    ll x,y;
    ll d = extEuclid(b,m,x,y); // to get [ b*x + m*y = d ]
    if(d != 1) return -1; // to indicate failure

    return mod(x,m);
}
