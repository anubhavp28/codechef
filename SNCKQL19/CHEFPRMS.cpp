#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bool primes[220];
    memset(primes, true, sizeof(primes));

    for (ll i=2; i<=200; i++) 
    {
        if (primes[i])
            for (ll j=2*i; j<=200; j += i)
                primes[j] = false;
    }

    bool semiprimes[220];
    memset(semiprimes, false, sizeof(semiprimes));

    for (ll N=2; N<=200; N++)
        for (ll i=2; i*i<N; i++)
            {
                ll q = N / i;
                ll m = N % i;
                if (m == 0 && primes[i] && primes[q])
                {
                    semiprimes[N] = true;
                    break;
                }
            }

    ll T, N;
    cin>>T;
    while (T--)
    {
        cin>>N;
        bool done = false;
        for (ll i=2; i<N; i++)
        {
            if (semiprimes[i] && semiprimes[N-i])
            {
                cout<<"YES\n";
                done = true;
                break;
            }
        }
        
        if (!done)
            cout<<"NO\n";
    }

}