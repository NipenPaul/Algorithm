#include<bits/stdc++.h>

using namespace std;

const int lim = 1e2 + 5;
bool checkPrime[lim];
vector<int>primes;

void sieve()
{
    checkPrime[1] = true;
    for(int i = 2; i * i < lim; i++)
    {
        if(!checkPrime[i])
        {
            for(int j = i * 2; j < lim; j += i)
            {
                checkPrime[j] = true;
            }
        }
    }
}
int main()
{
    sieve();
    for(int i = 1; i < lim; i++)
    {
        if(!checkPrime[i])primes.emplace_back(i);
    }
    for(auto it : primes)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
