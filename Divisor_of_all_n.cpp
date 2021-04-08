/// Divisor all n number..O(nlogn)
#include<iostream>
#include<vector>

using namespace std;

const int lim = 1e6 + 2;

vector<int> divisor[lim];

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i;  j <= n; j += i)
        {
            divisor[j].emplace_back(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(auto it : divisor[i])
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
