#include <bits/stdc++.h>
#define ll long long int
using namespace std;

double lambda(double k[], double c[], ll n) {
    double m = 0, j = 0;
    for (ll i=0; i<n; i++) {
        m += 1/k[i];
        j += 4*c[i]*k[i];
    }
    return sqrt(m/j);
}

double f(double x[], double c[], double n) {
    double v = 0;
    for (ll i=0; i<n; i++) {
        if (x[i] + c[i] < 0) return -1; 
        v += sqrt(x[i] + c[i]);
    }
    return v;
}

int main() {
    ll T, N;
    double k[100005];
    double c[100005];
    double x[100005];
    cout<<fixed<<setprecision(10);
    cin>>T;
    while(T--) {
        cin>>N;
        for (ll i=0; i<N; i++) {
            cin>>k[i];
        }
        for (ll i=0; i<N; i++) {
            cin>>c[i];
        }
        double l = lambda(k, c, N);
        double four_lsq = l * l * 4;
        for (ll i=0; i<N; i++) {
            x[i] = 1/(four_lsq * k[i] * k[i]) - c[i];
        }
        double ans = f(x, c, N);
        if (ans < 0 || isnan(ans)) { cout<<"-1"<<'\n'; }
        else { 
            cout<<ans<<" ";
            for (ll i=0; i<N; i++) {
                cout<<x[i]<<" ";
            }
            cout<<"\n";
        }
    }
}