#include <bits/stdc++.h>

#define ll long long int

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


ll nck(ll N, ll K)
{
    if (N < K)
        return 0;
    ll c = 1;
    for (ll i=N; i>N-K; i--)
        c = ( c * (i % 1000000007LL) ) % 1000000007LL ;

    ll j = 1;
    for (ll i=K; i>1; i--)
        j = ( j * i ) % 1000000007LL;

    ll inv;
    pair<ll, ll> p = extendedGCD(j, 1000000007LL);
    inv = ( p.first % 1000000007LL + 1000000007LL ) % 1000000007LL;
    
    return ( c * inv ) % 1000000007LL;
}

ll twoK(ll K)
{
    ll c = 1;
    for (ll i=0; i<K; i++)
        c = ( c << 1 ) % 1000000007LL;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T, N, K;
    cin>>T;
    while (T--)
    {
        cin>>N>>K;
        ll ans = 0, temp=1;
        for (ll bins=1; bins<=K; bins++)
        {
            temp = 1;
            temp *= nck(N-K+1, bins) * nck(K-1, bins-1);
            temp = temp % 1000000007LL;
            temp *= twoK(bins);
            temp = temp % 1000000007LL;
            ans += temp;
            ans = ans % 1000000007LL;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
