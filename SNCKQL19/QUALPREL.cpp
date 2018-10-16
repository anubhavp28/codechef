#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll S[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T, K, N;
    cin>>T;
    while (T--)
    {
        cin>>N>>K;
        for (ll i=0; i<N; i++)
            cin>>S[i];
        sort(S, S + N, greater<ll>());
        ll cutoff = S[K - 1];
        ll teams = K;
        for (ll i=K; i<N && S[i]==cutoff; i++)
            teams++;
        cout<<teams<<"\n";
    }
}