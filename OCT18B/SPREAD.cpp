#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T, N;
    ll A[100005];
    cin>>T;
    while (T--) 
    {
        cin>>N;
        ll sum = 0, val;
        for (ll i=0; i<N; i++) {
            cin>>val;
            sum += val;
            A[i] = sum;
        }
            
        ll knows = 0;
        ll day = 0;
        while (knows < N - 1) {
            knows += A[knows];
            day++;
        }
        cout<<day<<'\n';
    }
}
