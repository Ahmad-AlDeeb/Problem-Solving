const ld G_pos = (1+sqrt(5))/2;
const ld G_neg = (1-sqrt(5))/2;
ll fib(ll n) {
    return ( pow(G_pos,n) - pow(G_neg,n) ) / (ld)sqrt(5);
}
