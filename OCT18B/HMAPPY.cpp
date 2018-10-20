#include <bits/stdc++.h>

#define LL long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL N, M;
    LL A[100005], B[100005];

    LL sum_A=0;
    cin>>N>>M;

    for (LL i=0; i<N; i++) 
    {
        cin>>A[i];
        sum_A += A[i];
    }

    for (LL i=0;i<N;i++)
    {
        cin>>B[i];
    }

    if (M >= sum_A)
    {
        cout<<"0";
        return 0;
    }

    LL step = 100000000000000000LL;
    LL start = 0;
    LL end = 1000000000000000000LL;
    bool done = false;

    LL y;

    while (!done)
    {
        for (y=start; y<=end; y += step)
        {
            LL sum_blocks_on_or_above = 0;
            for (LL i=0; i<N; i++)
            {
                LL blocks_below = y / B[i];
                LL blocks_on_or_above = max(0LL, A[i] - blocks_below);
                sum_blocks_on_or_above += blocks_on_or_above;
            }
            
            if (sum_blocks_on_or_above <= M) 
            {
                if (step==1) 
                {
                    done = true;
                    break;
                }

                end = y;
                start = y - step;
                step = step / 10;
                break;
            }
        }
    }

    for (LL i=0; i<N; i++)
    {
        LL blocks_below = y / B[i];
        LL blocks_on_or_above = max(0LL, A[i] - blocks_below);
        A[i] -= blocks_on_or_above;
        M -= blocks_on_or_above;
    }

    LL max_A_cross_B = A[0] * B[0]; 
    for (LL i=0; i<N; i++)
    {
        if (A[i]*B[i] > max_A_cross_B)
            max_A_cross_B = A[i] * B[i];
    }

    cout<<max_A_cross_B;

}
