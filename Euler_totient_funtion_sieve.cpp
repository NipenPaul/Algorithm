#define int long long
const int lim = 1e6 + 5;

int phi[lim];
bool mark[lim];

void sievephi(int n)
{
    int i, j;
    // initialization
    for(i = 1; i <= n; i++) ph[i] = i;
    mark[1] = 1;

    for(i = 2; i <= n; i++)
    {
        if(!mark[i])  // if i is prime
        {
            for(j = i; j <= n; j += i)
            {
                mark[i] = 1;
                // phi[j] will be divisible by i
                // so no need to worry
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

