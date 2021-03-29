#include<bits/stdc++.h>
//#define int long long

using namespace std;
const int lim = (int) 2e5 + 5;

int phi[lim];
bool mark[lim];
int dp[lim];

void sievephi(int n)
{
    int i, j;
    // initialization
    for(i = 1; i <= n; i++) phi[i] = i;

    mark[1] = 1;
    phi[1] = 1;

    for(i = 2; i <= n; i++)
    {
        if(!mark[i])  // if i is prime
        {
            for(j = i; j <= n; j += i)
            {
                mark[j] = 1;
                // phi[j] will be divisible by i
                // so no need to worry
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    sievephi(10);
    return 0;
}


