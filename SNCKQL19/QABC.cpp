#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll A[100005];
ll B[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T, N;
    cin>>T;
    while (T--)
    {
        cin>>N;
        for(ll i=0; i<N; i++)
            cin>>A[i];
        for (ll i=0; i<N; i++)
            cin>>B[i];
        bool done=false;
        for (ll i=0; i<N-2; i++)
        {
            ll diff = B[i] - A[i];
            if (diff < 0)
            {   
                done=true;
                cout<<"NIE\n";
                break;
            }
            A[i] += diff;
            A[i+1] += 2*diff;
            A[i+2] += 3*diff;
        }
        if (!done)
            for (ll i=0; i<N; i++)
                if (A[i] != B[i]) 
                {
                    cout<<"NIE\n";
                    done = true;
                    break;
                }
        if (!done)
            cout<<"TAK\n";
    }
}