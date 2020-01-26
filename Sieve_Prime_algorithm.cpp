#include<bits/stdc++.h>

using namespace std;

const int lim = 1e3 + 1;

int prime[lim], nprime;
bool visited[lim];

void sive(int n)
{
   int i, j, limit = sqrt(n) + 2;
   visited[1] = 1;
   for(i = 4; i <= n; i += 2) visited[i] = 1;
   prime[nprime++] = 2;

   for(i = 3; i <= n; i += 2)
   {
      if(!visited[i])
      {
        prime[nprime++] = i;
        if(i <= limit)
        {
           for(j = i * i; j <= n; j += i * 2)
           {
             visited[j] = 1;
           }
        }
      }
   }
}

int main()
{
  sive(20);
  cout << nprime << '\n';
  return 0;
}

