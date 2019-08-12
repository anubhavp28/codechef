#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll T, N;
    ll A[1000005];
    cin>>T;
    while(T--) {
        cin>>N;
        for (ll i=0; i<N; i++) {
            cin>>A[i];
        }
        unordered_map<ll, ll> ma;
        unordered_map<ll, ll> mb;
        ll prefix_xor = 0;
        ll triples = 0;
        for (ll i=0; i<N; i++) {
            prefix_xor ^= A[i];
            if (prefix_xor == 0) {
                triples += i;
            }
            if (ma.count(prefix_xor)) {
                triples += ma[prefix_xor]*(i-1) - mb[prefix_xor] ;
            }
            ma[prefix_xor] += 1;
            mb[prefix_xor] += i;
        }
        cout<<triples<<'\n';
    }
    return 0;
}