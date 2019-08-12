#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll M[10][100005];
char L[100005];
char R[100005];
ll _pow10[200010];
const ll m = 1000000007LL;

ll modsub(ll a, ll b) {
    ll c = (a - b) % m;
    if (c < 0) return m + c;
    else return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    M[1][0] = 1;
    M[2][0] = 3;
    M[3][0] = 6;
    M[4][0] = 10;
    M[5][0] = 15;
    M[6][0] = 21;
    M[7][0] = 28;
    M[8][0] = 36;
    M[9][0] = 45;

    ll a = 45;
    ll b = 0; 
    for (ll i=1; i<100001; i++) {
        M[1][i] = ( ((M[1][i-1]*10) % m) + modsub(a,b) ) % m;
        b = a;
        a = (a * 100) % m;
    }

    ll x = -1;
    ll k = 1;
    for (ll i=1; i<100001; i++) {
        x = k;
        k = (k * 10) % m;
        for (ll j=2; j<10; j++) {
            M[j][i] = ((M[j-1][i] + M[1][i]) % m + ((j-1) * ((k * k) % m)) % m - ((j-1) * ((x * x) % m)) % m ) % m;  
        }
    }

    _pow10[0] = 1;
    for (ll i=1; i<200003; i++) {
        _pow10[i] = ( _pow10[i-1] * 10 ) % m;
    }

    ll T, NL, NR;
    cin>>T;
    while(T--) {
        cin>>NL>>L;
        cin>>NR>>R;

        ll e, s=0, j=0, pd=-1, d;
        for (ll i=0; i<NL; i++) {
            e = NL - 1 - i;
            d = L[i] - '0';
            s = (s + M[d][e]) % m;
            s = (s + (((j*d) % m )* _pow10[e] ) % m ) % m;
            if (pd!=-1 && pd < d) { 
                s = modsub(s, (pd * _pow10[e+e]) % m );
            }
            else if (pd == d) {
                s = modsub(s, (pd * _pow10[e]) % m );
            }
            if (pd != d) {
                j = ( j + ((d*_pow10[e]) % m) ) % m;
            }
            pd = d;   
        }


        ll a = s;
        ll xx = j;
        s=0; j=0; pd=-1;
        for (ll i=0; i<NR; i++) {
            e = NR - 1 - i;
            d = R[i] - '0';
            s = (s + M[d][e]) % m;
            s = (s + (((j*d) % m )* _pow10[e] ) % m ) % m;
            if (pd!=-1 && pd < d) { 
                s = modsub(s, (pd * _pow10[e+e]) % m );
            }
            else if (pd == d) {
                s = modsub(s, (pd * _pow10[e]) % m );
            }
            if (pd != d) {
                j = ( j + ((d*_pow10[e]) % m) ) % m;
            }
            pd = d;   
        }
        cout<<modsub(s, (a - xx) % m)<<endl;
    }

}
