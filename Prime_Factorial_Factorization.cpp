#include<bits/stdc++.h>

using namespace std;

const int lim = 1e2;

vector<int> prime;
bool visited[lim];

vector<int> ans;
map<int, int> ma;
set<int> se;
set<int>::iterator it;

void sive()
{
   visited[1] = 1;
   for(int i = 4; i <= lim; i += 2)
   {
      visited[i] = 1;
   }
   prime.push_back(2);
   for(int i = 3; i <= lim; i += 2)
   {
      if(!visited[i])
      {
        prime.push_back(i);

        for(int j = i * i; j <= lim; j += i)
        {
          visited[j] = 1;
        }
      }
   }
}

int main()
{
   sive();
   int t;
   scanf("%d", &t);
   for(int test = 1; test <= t; test++)
   {
      int n;
      scanf("%d", &n);
      for(int i = 2; i <= n; i++)
      {
        int tem = i;
        for(int j = 0; prime[j] * prime[j] <= tem; j++)
        {
           if(tem % prime[j] == 0)
           {
               while(tem % prime[j] == 0)
               {
                 ans.push_back(prime[j]);
                 ma[prime[j]]++;
                 se.insert(prime[j]);
                 tem /= prime[j];
               }
           }
        }
        if(tem > 1)
        {
          ans.push_back(tem);
          se.insert(tem);
          ma[tem]++;
        }
      }

	 printf("Case %d: %d = ", test, n);
	 int len = se.size(), i = 0;
     for(it = se.begin(); it != se.end(); ++it)
     {
        i++;
        if(len == i)
        cout << *it << " (" << ma[*it] << ")";
        else
        cout << *it << " (" << ma[*it] << ") * ";
     }
     printf("\n");
      ans.clear();
      se.clear();
      ma.clear();
   }
  return 0;
}

