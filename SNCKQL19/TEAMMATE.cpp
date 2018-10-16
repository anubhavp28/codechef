#include <bits/stdc++.h>

#define ll long long int

#define mm 1000000007LL

using namespace std;

pair<ll, ll> extendedGCD(ll A, ll B)
{
    if (B==0)
    {
        return make_pair(1LL, 0LL);
    }
    pair<ll, ll> p = extendedGCD(B, A % B);
    return make_pair(p.second, p.first - (A/B)*p.second);
}

ll modinv(ll j)
{
    ll inv;
    pair<ll, ll> p = extendedGCD(j, 1000000007LL);
    inv = ( p.first % 1000000007LL + 1000000007LL ) % 1000000007LL;
    return inv;
}

ll fact(ll x)
{
    ll ans = 1;
    for (ll i=2; i<=x; i++)
        ans = (ans * (i % mm) ) % mm;  
    return ans;
}   

ll pow2(ll K)
{
    ll c = 1;
    for (ll i=0; i<K; i++)
        c = ( c << 1 ) % mm;
    return c;
}

ll S[100005];
ll J[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T, N;
    cin>>T;
    while (T--)
    {
        ll ans = 1, z;
        cin>>N;
        for (ll i=0; i<N; i++) {
            cin>>S[i];
        }
        sort(S, S + N);
        ll index = 0;
        ll value = S[N-1];
        memset(J, 0LL, sizeof(J));
        for (ll i=N-1;i>=0; i--)
        {
            if (S[i] != value)
            { 
                value = S[i];
                index++;
            }
            J[index]++;
        }
        for (ll i=0; i<=index; i++)
        {
            if (J[i] % 2 == 0)
            {
                ll t = 1;
                t = pow2(J[i] / 2);
                t *= fact(J[i] / 2);
                t = t % mm;
                t = modinv(t);
                ans *= ( fact(J[i]) * t ) % mm;
                ans = ans % mm;
            }
            else
            {
                ll t = 1;
                t = pow2(J[i] / 2);
                t *= fact(J[i] / 2);
                t = t % mm;
                t = modinv(t);
                ans *= ( fact(J[i] - 1) * t ) % mm;
                ans = ans % mm;
                ans *= ( J[i+1] * J[i] ) % mm;
                ans = ans % mm;
                J[i+1]--;
            }
        }
        cout<<ans<<'\n';
    }
}