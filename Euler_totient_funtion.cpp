#define int long long

int phi(int n)
{
    int ret = n;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            // i is a prime diveding n.
            while(n % i == 0)
            {
                // divide all the factors of i
                n /= i;
            }
            // same as: ret * (1 - 1/p)
            ret -= (ret / i);
        }
    }
    if(n > 1)
    {
        // there can be only one prime greater
        // than sqrt(n) that divides n
        ret -= (ret / n);
    }
    return ret;
}
