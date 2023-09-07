#include<bits/stdc++.h>

using namespace std;

const int LIM = (int) 1e3+1;

int used[LIM], number[LIM];

void permutaion(int pos, int n)
{
    if(pos == n+1)
    {
        for(int i = 1; i <= n; i++)
        {
            printf("%d ", number[i]);
        }
        printf("\n");
    }
    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            used[i] = 1;
            number[pos] = i;
            permutaion(pos+1, n);
            used[i] = 0;
        }
    }
}

int main()
{
    permutaion(1, 3);
    return 0;
}
