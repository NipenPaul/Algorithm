#include<bits/stdc++.h>

using namespace std;

const int lim = 1e2 + 2;
bool prime[lim];
vector<int>all_prime;
map<int, int> ma;
set<int> se;

void sieve()
{
    prime[1] = true;
    for(int i = 2; i * i <= lim; i++)
    {
        if(!prime[i])
        {
            for(int j = i * 2; j <= lim; j += i)
            {
                prime[j] = true;
            }
        }
    }
}
int pows(int x, int y)
{
    int sum = 1;
    for(int i = 1; i <= y; i++)
    {
        sum *= x;
    }
    return sum;
}
int main()
{
    sieve();
    for(int i = 1; i <= lim; i++)
    {
        if(!prime[i])all_prime.emplace_back(i);
    }
    int n; cin >> n;
    for(int i = 0; i < (int)all_prime.size();)
    {
        if(n % all_prime[i] == 0)
        {
            n /= all_prime[i];
            //cout << all_prime[i] << " ";
            ma[all_prime[i]]++;
            se.insert(all_prime[i]);
        }
        else
        {
            i++;
        }
        if(n == 1)break;
    }
    int sum = 1;
    for(auto it : se)
    {
        sum *= ((pows(it, ma[it]+1) - 1) / (it - 1));
    }
    cout << "sum Of Divisor = " << sum << endl;
    return 0;
}
