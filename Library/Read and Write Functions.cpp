#include<cstdio>
#define ll long long
inline ll read() {
    ll x=0; char c=getchar(),f=1;

    for(;c<'0'||'9'<c;c=getchar())
        if(c=='-')
            f=-1;
    for(;'0'<=c&&c<='9';c=getchar())
        x = x*10 + c-'0';

    return x*f;
}
inline void write(ll x) {
    static char buf[20],len; len=0;

    if(x<0)
        x=-x,putchar('-');
    for(;x ;x/=10)
        buf[len++]=x%10+'0';
    if(!len)
        putchar('0');
    else
        while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}

