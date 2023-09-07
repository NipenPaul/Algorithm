/**
Courses: Algorithm Design & Analysis Sessional
Assignment Name: Kruskal Algorithm
Name: Nipen Paul
Student ID: 174038
*/
#include <bits/stdc++.h>
using namespace std;

struct Edges
{
	int u, v, weight;
};

void mergeSort(struct Edges array[], int left, int right)
{
  if(left >= right)return;
  int mid = (left + right) / 2;
  mergeSort(array, left, mid);
  mergeSort(array, mid+1, right);
  int len = right - left + 1;
  struct Edges tem[len];
  int l = left, r = mid+1, in = 0;
  while(l <= mid && r <= right)
  {
    if(array[l].weight < array[r].weight)
    {
      tem[in++] = array[l++];
    }
    else
    {
      tem[in++] = array[r++];
    }
  }
  while(l <= mid)
  {
     tem[in++] = array[l++];
  }
  while(r <= right)
  {
     tem[in++] = array[r++];
  }
  for(int i = 0; i < in; i++)
  {
    array[left++] = tem[i];
  }
}

void Union(int parent[], int u, int v, int node)
{
	for(int i = 1; i <= node; i++)
	{
		if(parent[i] == v)
		{
			parent[i] = u;
		}
	}
}

int main(int argc, char const *argv[])
{
	///freopen("MST.txt", "r", stdin);
	int node, edge; cin >> node >> edge;
	struct Edges array[edge];
	int parent[node+1];
	for(int i = 1; i <= node; i++)
		parent[i] = i;
	for (int i = 0; i < edge; ++i)
	{
		cin >> array[i].u >> array[i].v >> array[i].weight;
	}
	mergeSort(array, 0, edge-1);

	int cost = 0, in = 0;
	struct Edges selectedEdage[node-1];
	for (int i = 0; i < edge; ++i)
	{
		int u = parent[array[i].u];
		int v = parent[array[i].v];
		if(parent[u] != parent[v])
		{
			Union(parent, u, v, node);
			cost += array[i].weight;
			selectedEdage[in++] = array[i];
		}
	}
	cout << "Total MST cost is: " << cost << '\n';
	cout << "Selected Edges list:\n";
	for (int i = 0; i < node-1; ++i)
	{
		cout << selectedEdage[i].u << " ";
		cout << selectedEdage[i].v << " ";
		cout << selectedEdage[i].weight << "\n";
	}
	return 0;
}

/**
MST.txt
7
12
1 2 2
1 3 2
1 4 1
2 5 1
2 4 5
3 4 1
3 6 2
4 5 1
4 6 6
4 7 5
5 7 3
6 7 10
*/
