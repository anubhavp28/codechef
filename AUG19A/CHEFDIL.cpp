#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll T;
    cin>>T;
    char S[100005];
    while (T--) {
        cin>>S;
        ll l = strlen(S);
        ll c = 0;
        for (ll i=0; i<l; i++) {
            if (S[i] =='1') c++;
        }
        if (c % 2 == 0) cout<<"LOSE"<<"\n";
        else cout<<"WIN"<<"\n";
    }
}