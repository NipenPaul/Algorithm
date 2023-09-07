/**
Please Don't copy deep..

input.txt
60 5
5 10 15 22 25
30 40 45 77 90
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
 /// freopen("input.txt", "r", stdin);
  double W;
  int n, i, j;
  cin >> W >> n;
  double w[n], b[n], MaxP = 0.0;
  int position[n];
  i = 0;
  while(i < n)
  {
    cin >> w[i];
    i++;
  }
  i = 0;
  while(i < n)
  {
    cin >> b[i];
    position[i] = i;
    i++;
  }

  i = 0;
  while(i < n)
  {
    j = i+1;
    while(j < n)
    {
        if(w[i]*b[j] > w[j]*b[i])
        {
          swap(w[i], w[j]);
          swap(b[i], b[j]);
          swap(position[i], position[j]);
        }
      j++;
    }
    i++;
  }
  cout << "The item with weight is:\n";
  i = 0;
  while(i < n)
  {
    double res = 0;
    if(W >= w[i])
      res = w[i];
    else
      res = W;
    W -= res;
    MaxP += res*(b[i]/w[i]);

    if(res != 0.0)
    cout << position[i]+1 << "(" << res << "), ";
  i++;
  }
  cout << "\nTotal Profit is: " << MaxP << '\n';
	return 0;
}
