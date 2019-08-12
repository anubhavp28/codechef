#include <bits/stdc++.h>
#define ll long long int
using namespace std;
    
ll euler_tour[300005];

void euler(bool vis[], vector<ll> adj[], int u, int &indx) 
{ 
    vis[u] = 1; 
    euler_tour[indx++] = u;
    for (auto it : adj[u]) { 
        if (!vis[it]) { 
            euler(vis, adj, it, indx); 
            euler_tour[indx++] = u; 
        } 
    }
} 

const ll n = 200002;
void update(ll BIT[], ll x, ll delta)
{
    for(; x <= n; x += x&-x)
          BIT[x] += delta;
}

ll prefix(ll BIT[], ll x)
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}

ll fenwick1[200005];
ll fenwick2[200005];

ll _prev[200005];
ll C[200005];

int main() {
    ll T, N, u, v, p1, p2, p3;
    cin>>T;
    while(T--) {
        cin>>N;
        cin>>p1>>p2>>p3;
        vector<ll> tree[N+1];
        for (ll i=0; i<N-1; i++) {
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int indx = 0;
        bool vis[N+1];
        memset(vis, 0, sizeof(vis));
        euler(vis, tree, 1, indx);


        vector<ll> less_than[N+1];
        memset(fenwick1, 0, sizeof(fenwick1));
        for (ll j=0; j<200002; j++) _prev[j] = -1;
        for (ll i=0; i<indx; i++) {
            if (_prev[euler_tour[i]] == -1)
                update(fenwick1, euler_tour[i]+1, 1);
            C[i] = prefix(fenwick1, euler_tour[i]);   
            if (_prev[euler_tour[i]] != -1) {
                less_than[euler_tour[i]].push_back(C[i] - C[_prev[euler_tour[i]]]);
            }
            _prev[euler_tour[i]] = i;
        }

        vector<ll> greater_than[N+1];
        memset(fenwick2, 0, sizeof(fenwick2));
        for (ll j=0; j<200002; j++) _prev[j] = -1;
        for (ll i=0; i<indx; i++) {
            if (_prev[euler_tour[i]] == -1) {
                update(fenwick2, 1, 1);
                update(fenwick2, euler_tour[i], -1);
            }
            C[i] = prefix(fenwick2, euler_tour[i]);
            if (_prev[euler_tour[i]] != -1) {
                greater_than[euler_tour[i]].push_back(C[i] - C[_prev[euler_tour[i]]]);
            }
            _prev[euler_tour[i]] = i;
        }


        ll ans = 0;
        if ((p1==2 && p2==1 && p3==3) || (p1==3 && p2==1 && p3==2)) {
            for(ll i=1; i<=N; i++) {
                ll p = accumulate(greater_than[i].begin(), greater_than[i].end(), 0);
                ll g = N - i - p;
                ll s = N - i;
                ll a = p*g;
                for (auto j : greater_than[i]) {
                    a += j*(s - j);
                }
                a /= 2;
                ans += a;
            }
            cout<<ans<<'\n';
        }

        if ((p1==2 && p2==3 && p3==1) || (p1==1 && p2==3 && p3==2)) {
            for(ll i=1; i<=N; i++) {
                ll p = accumulate(less_than[i].begin(), less_than[i].end(), 0);
                ll g = i - 1 - p;
                ll s = i - 1;
                ll a = p*g;
                for (auto j : less_than[i]) {
                    a += j*(s - j);
                }
                a /= 2;
                ans += a;
            }
            cout<<ans<<'\n';
        }

        if ((p1==1 && p2==2 && p3==3) || (p1==3 && p2==2 && p3==1)) {
            for(ll i=1; i<=N; i++) {
                ll s1 = i - 1;
                ll s2 = N - i;
                ll p1 = accumulate(less_than[i].begin(), less_than[i].end(), 0);
                ll p2 = accumulate(greater_than[i].begin(), greater_than[i].end(), 0);
                ll g1 = i - 1 - p1;
                ll g2 = N - i - p2;
                ll a = g2*p1;
                for (ll j=0 ; j<greater_than[i].size(); j++) {
                    a += greater_than[i][j]*(s1 - less_than[i][j]);
                }
                ans += a;
            }
            cout<<ans<<'\n';
        }

    }
}
