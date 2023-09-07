/** Must be needded change the program..
    because same as copy paste problem..

    Writer: DarkLuckMan
*/

/*
save the file input.txt same directory
8
0 1
1 2
1 5
2 3 
2 4
3 0
4 5
4 6
5 6
5 7
6 7
*/

#include <bits/stdc++.h>
#define lim 1000
#define inf 1000000000
#define white 0
#define grey 1
#define black 2
using namespace std;

int node;
static int Time, ct;
int matrix[lim][lim], inverse[lim][lim];
vector<int> vec[lim];
int color[lim],d[lim], f[lim];

void dfs(int u)
{
	color[u] = grey;
	Time++;
	d[u] = Time;
	 int i = 0;
    while(i<node)
	{
		if(matrix[u][i] == 1)
		{
			if(color[i] == white)
			   dfs(i);
		}
		i++;
	}
	color[u] = black;
	Time++;
	f[u] = Time;
}
void dfs2(int u)
{
	color[u] = grey;
	vec[ct].push_back(u);
	int i = 0;
   while(i < node)
   {
	if(inverse[u][i] == 1)
	{
		if(color[i] == white)
		{
		   dfs2(i);
		}
	}
	i++;
   }
}

int main()
{
	freopen ("input.txt","r",stdin);
	cin >> node;
	int u, i;
	while(cin >> u >> i)
	{
		matrix[u][i] = 1;
		inverse[i][u] = 1;
	}

    i = 0;
    while(i<node)
	{		
		color[i] = white;
		f[i] = inf;
		d[i] = inf;
		i++;
	}
	Time = 0;
	 i = 0;
    while(i<node)
	{		
	
		if(color[i] == white)
			dfs(i);
		i++;
	}

	 i = 0;
    while(i<node)
	{				
		color[i] = white;
		i++;
	}
	 i = 0;
    while(i<node)
	{		
		int mx = -1, mxv = 0;
		 int j = 0;
		while(j<node)
		{		

			if(mxv < f[j])
			{
				if(color[j] == white){
					mxv = f[j];
					mx = j;
				}
			}
			j++;
		}

		if(mx != -1)
		{
			dfs2(mx);
			vec[ct].push_back(mx);
			reverse(vec[ct].begin(), vec[ct].end());
			ct++;
		}
		i++;

	}


	cout << "Total SCC is:" << ct << endl;
	cout << "The SCC's are:" << endl;
	 i = 0;
    while(i<ct)
	{
		int tem = vec[i].size() - 1;
		int j = 0;
	    while(j<tem)
		{	
			if(j == tem-1)
				cout << vec[i][j];
		    else
		    	cout << vec[i][j] << "-->";
		    j++;
		}
		cout << endl;
		i++;
	}
	return 0;
}