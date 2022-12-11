#include<bits/stdc++.h>

using namespace std;

const int lim = 1e2 + 5;
bool prime[lim];
vector<int>all_prime;

void sieve()
{
    prime[1] = true;
    for(int i = 2; i * i < lim; i++)
    {
        if(!prime[i])
        {
            for(int j = i * 2; j < lim; j += i)
            {
                prime[j] = true;
            }
        }
    }
}
int main()
{
    sieve();
    for(int i = 1; i < lim; i++)
    {
        if(!prime[i])all_prime.emplace_back(i);
    }
    for(auto it : all_prime)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
