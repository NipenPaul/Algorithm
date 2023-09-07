/**
Assignment: Shortest Path Algorithm
Problem: Solve the problem of your theory assignment_01 (a) problem using only dijks'tra algorithm.
Name: Nipen Paul
Student ID: 174038
Subject: Algorithm Design & Analysis Sessional
using c++ language
*/

#include <bits/stdc++.h>

using namespace std;

const int LIM = (int)1e3;
const int INF = (int) 1e9+7;
const int BLACK = 2;
const int WHITE = 1;
int node, edge;
int matrix[LIM][LIM];
int distances[LIM];
int color[LIM];
int path[LIM];
map<string, int> ma;
map<int, string> maPath;

void dijkstra(int source)
{
	for(int i = 1; i <= node; i++)
	{
		if(matrix[source][i] != 0)
		{
			distances[i] = matrix[source][i];
			path[i] = source;
		}
		else
			distances[i] = INF;
		color[i] = WHITE;
	}
	distances[source] = 0;
	int u = source;
	color[u] = BLACK;
	for(int j = 1; j <= node; j++)
	{

		int minDistance = INF;
		for(int i = 1; i <= node; i++)
		{
			if(color[i] == WHITE && minDistance >= distances[i])
			{
				u = i;
				minDistance = distances[i];
			}
		}
		color[u] = BLACK;
		for(int v = 1; v <= node; v++)
		{
			if(matrix[u][v] != 0 && color[v] == WHITE)
			{
				if(distances[v] > matrix[u][v] + distances[u])
				{
					distances[v] = matrix[u][v] + distances[u];
					path[v] = u;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r",stdin);
    cin >> node >> edge;
    string str1, str2;
    int weight, ind = 1;
    while(edge--)
    {
        getchar();
    	getline(cin, str1);
    	getline(cin, str2);
    	cin >> weight;
    	if(ma[str1] == 0)
    	{
    		maPath[ind] = str1;
    		ma[str1] = ind++;
    	}
    	if(ma[str2] == 0)
    	{
    		maPath[ind] = str2;
    		ma[str2] = ind++;
    	}
    	matrix[ma[str1]][ma[str2]] = weight;
    	matrix[ma[str2]][ma[str1]] = weight;
    }

    string source, destination;
    getchar();
    getline(cin, source);
    getline(cin, destination);

    dijkstra(ma[source]);

    cout << source << " to " << destination;
    cout << " Minimum distance is: " << distances[ma[destination]] << "\n";

    cout << "\nPath:";
    std::vector<int> vecPath;
    int tem = ma[destination];
    while(path[tem] != path[ma[source]])
    {
    	vecPath.push_back(tem);
    	tem = path[tem];
    }
    vecPath.push_back(tem);
    reverse(vecPath.begin(), vecPath.end());

    for(int i = 0; i < vecPath.size(); i++)
    {
    	if(i+1 == (int)vecPath.size())
    		cout << maPath[vecPath[i]] << "\n";
    	else
    		cout << maPath[vecPath[i]] << " -> ";
    }
	return 0;
}

/**
input.txt exectly same format given, because input sapce and enter as a character..
...................................................................................
8 10
Malibu
Santa Barbara
45
Malibu
Los Angeles
20
Santa Barbara
Los Angeles
30
Los Angeles
San Diego
100
Los Angeles
Riverside
25
Santa Barbara
Barstow
45
Barstow
Riverside
75
Riverside
Palm Spring
75
Riverside
San Diego
90
San Diego
El Cajon
15
Los Angeles
Barstow
*/
