#include <bits/stdc++.h>

using namespace std;

#define ll long long int

// ll q[100005]; // user-queries
ll A[100005]; // precomputed answers
ll board[200][200]; // 0 --> black, 1 --> white
ll R[2][200][200];
ll C[2][200][200];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, Q;
    char _s[250];
    memset(R, 0, sizeof(R));
    memset(C, 0, sizeof(C));
    memset(A, -1LL, sizeof(A));

    cin>>N>>M; // N rows, M columns
    for (ll i=0; i<N; i++)
    {
        cin>>_s;   
        for (ll j=0; j<M; j++) 
        {
            switch (_s[j])
            {
                case '0': board[i][j] = 0; break;
                case '1': board[i][j] = 1;
            }  
        }
    }

    for (ll c=0; c<2; c++)
    {
        for (ll i=0;i<N; i++)
        {   ll sum = 0;
            for (ll j=0;j<M; j++)
            {
                if ( (j % 2 == 0 && board[i][j] != c) || (j % 2 == 1 && board[i][j] != 1-c) )     
                    sum += 1;
                R[c][i][j] = sum;

            }
        }

        for (ll i=0;i<M; i++)
        {   ll sum = 0;
            for (ll j=0;j<N; j++)
            {
                if ( (j % 2 == 0 && board[j][i] != c) || (j % 2 == 1 && board[j][i] != 1-c) )    
                    sum += 1;
                C[c][i][j] = sum;
            }
        }

    }

    for (ll i=0; i<N; i++)
        for (ll j=0; j<M; j++)
        {
            ll m = max(N, M);
            ll size = 1;
            ll cost0, cost1;
            if (board[i][j] == 0) {
                cost0 = 0;
                cost1 = 1;
            }
            if (board[i][j] == 1) {
                cost0 = 1;
                cost1 = 0;
            }
            A[cost0] = max(A[cost0], size);
            A[cost1] = max(A[cost1], size);

            for (size = 2; size<=m; size++)
            {
                ll x1 = i, y1 = j;
                ll x2 = i + size - 1, y2 = j + size - 1;
                
                if (x2 >= N || y2 >= M)
                    break;
                
                // calculate cost0
                ll c = (size % 2 == 0) ? 1 : 0;
                c = (y1 % 2 == 0) ? c : !c;
                if ( y1 - 1 > -1)
                    cost0 += R[c][x2][y2] - R[c][x2][y1 - 1];
                else
                    cost0 += R[c][x2][y2];
                
                c = (size % 2 == 0) ? 1 : 0;
                c = (x1 % 2 == 0) ? c : !c;
                if ( x1 - 1 > -1)
                    cost0 += C[c][y2][x2 - 1] - C[c][y2][x1 - 1];
                else
                    cost0 += C[c][y2][x2 - 1];

                // calculate cost1
                c = (size % 2 == 0) ? 0 : 1;
                c = (y1 % 2 == 0) ? c : !c;
                if ( y1 - 1 > -1)
                    cost1 += R[c][x2][y2] - R[c][x2][y1 - 1];
                else
                    cost1 += R[c][x2][y2];
                
                c = (size % 2 == 0) ? 0 : 1;
                c = (x1 % 2 == 0) ? c : !c;
                if ( x1 - 1 > -1)
                    cost1 += C[c][y2][x2 - 1] - C[c][y2][x1 - 1];
                else
                    cost1 += C[c][y2][x2 - 1];

                A[cost0] = max(A[cost0], size);
                A[cost1] = max(A[cost1], size);

            }

        }

    ll max_till_now = -1;
    for (ll i=0; i<100004; i++)
    {
        if (A[i] > max_till_now)
            max_till_now = A[i];

        A[i] = max_till_now;
    }

    cin>>Q;
    ll qq;
    for (ll q=0; q<Q; q++)
    {
        cin>>qq;
        qq = min(100002LL, qq);
        cout<<A[qq]<<'\n';
    }
}