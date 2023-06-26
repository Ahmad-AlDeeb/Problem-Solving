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
