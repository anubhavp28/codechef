#include <bits/stdc++.h>

#define ll long long int

using namespace std;

pair<ll, ll> reduced_digitsum(ll x) {
    ll digitsum = x;
    ll steps = 0;
    while (x > 9)
    {
        digitsum = 0;
        while (x != 0)
        {
            digitsum += x % 10;
            x = x / 10;
        }
        steps += 1;
        x = digitsum;
    }
    return make_pair(digitsum, steps);
}

ll digitsum(ll x) {
    ll digitsum = 0;
    while (x != 0)
    {
        digitsum += x % 10;
        x = x / 10;
    }
    return digitsum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T, N, D;
    
    ll rdigitsum[10];
    ll N_to_rdigitsum_steps[10];

    cin>>T;
    while (T)
    {
        cin>>N>>D;

        for (int i=0; i<9; i++)
        {
            pair<ll, ll> p;
            p = reduced_digitsum(N + i*D);
            rdigitsum[i] = p.first;
            N_to_rdigitsum_steps[i] = i + p.second;
        }

        ll minimised_N = rdigitsum[0];
        for (int i=0; i<9; i++) 
            minimised_N = min(minimised_N, rdigitsum[i]);

        queue<vector<ll>> BFSqueue;
        vector<ll> vec_push = {N, 0, 0};
        BFSqueue.push(vec_push);
        while (!BFSqueue.empty())
        {
            vector<ll> v = BFSqueue.front();
            BFSqueue.pop();

            if (v[0] == minimised_N)
            {
                cout<<minimised_N<<" "<<v[1]<<"\n";
                break;
            }

            if (v[0] > 9)
            {
                vec_push = {digitsum(v[0]), v[1] + 1, v[2]};
                BFSqueue.push(vec_push);
            }
            
            if (v[2] < 9 )
            {
                vec_push = {v[0] + D, v[1] + 1, v[2] + 1};
                BFSqueue.push(vec_push);
            }
            
        }
        T--;
        
    } 
}
