#include <bits/stdc++.h>

#define ll long long int

using namespace std;

vector<ll> C(1000005, 0);

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void update(ll min, ll max) {
    min += 1;
    max += 2;
    for(; min<=1000001; min += min & (-min))
        C[min] += 1;

    for(; max<=1000001; max += max & (-max))
        C[max] -= 1;
}

ll goodpairs(ll K) {
    K++;
    ll sum = 0;
    for (; K > 0; K -= K & (-K))
        sum += C[K];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, Q, X, Y, R, K;
    double dmin, dmax;
    vector<vector<ll>> circles;
    vector<ll> circle;
    cin>>N>>Q;
    circles.resize(N);
    for (ll i=0; i<N; i++)
    {
        cin>>X>>Y>>R;
        circle = {X, Y, R};
        circles[i] = circle;
    }

    for (ll i=0; i<N; i++)
        for (ll j=i+1; j<N; j++) 
        {
            
            double x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
            double x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
            double dist = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );

            dmax = dist + r1 + r2;
            if (dist > r1 + r2) // No overlap
                dmin = dist - r1 - r2;
            else if (dist <= abs(r1 - r2)) // Inside
                dmin = 2*max(r1, r2) - dmax;
            else
                dmin = 0; 
            
            update(ceil(dmin), floor(dmax));
        }
    
    for (ll i=0; i<Q; i++) {
        cin>>K;
        cout<<goodpairs(K)<<'\n';
    }

}