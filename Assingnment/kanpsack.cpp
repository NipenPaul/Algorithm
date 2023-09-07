/**
Courses: Algorithm Design & Analysis Sessional
Assignment Name:Fractional Knapsack
Name: Nipen Paul
Student ID: 174038
*/

#include<bits/stdc++.h>

using namespace std;

void mergeSort(double w[], double b[], int ind[], int left, int right)
{
  if(left >= right)return;
  int mid = (left + right) / 2;
  mergeSort(w, b, ind, left, mid);
  mergeSort(w, b, ind, mid+1, right);
  int len = right - left + 1;
  double temW[len], temB[len];
  int temInd[len], l = left, r = mid+1, in = 0;
  while(l <= mid && r <= right)
  {
    if(w[l]*b[r] < w[r]*b[l])
    {
      temW[in] = w[l];
      temB[in] = b[l];
      temInd[in] = ind[l];
      in++;
      l++;
    }
    else
    {
      temW[in] = w[r];
      temB[in] = b[r];
      temInd[in] = ind[r];
      in++;
      r++;
    }
  }
  while(l <= mid)
  {
      temW[in] = w[l];
      temB[in] = b[l];
      temInd[in] = ind[l];
      in++;
      l++;
  }
  while(r <= right)
  {
      temW[in] = w[r];
      temB[in] = b[r];
      temInd[in] = ind[r];
      in++;
      r++;
  }
  for(int i = 0; i < in; i++)
  {
    w[left] = temW[i];
    b[left] = temB[i];
    ind[left] = temInd[i];
    left++;
  }
}

int main()
{
 /// freopen("input.txt", "r", stdin);
  int itemNumber;
  double maxWeight;
  cin >> maxWeight >> itemNumber;
  double w[itemNumber], b[itemNumber];
  int index[itemNumber];
  for(int i = 0; i < itemNumber; i++)
  {
    cin >> w[i];
    index[i] = i;
  }
  for(int i = 0; i < itemNumber; i++)
  {
    cin >> b[i];
  }
  mergeSort(w, b, index, 0, itemNumber-1);
  double totalProfit = 0;
  cout << "The item with weight is:\n";
  for(int i = 0; i < itemNumber; i++)
  {
    double ans = 0;
    if(maxWeight >= w[i])
      ans = w[i];
    else
      ans = maxWeight;
    maxWeight -= ans;
    totalProfit += ans*(b[i]/w[i]);
    if(ans > 0.00)
      cout << index[i]+1 << "(" << ans << ")";
    if(maxWeight)cout << ", ";
  }
  cout << "\nTotal Profit is: " << totalProfit << '\n';
	return 0;
}

/** input.txt
60 5
5 10 15 22 25
30 40 45 77 90
*/
