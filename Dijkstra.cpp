#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll lim = 1e5 + 5;
const ll inf = 1e15 + 5;

struct Node
{
  ll At, cost;
  Node(ll _at, ll _cost)
  {
    At = _at;
    cost = _cost;
  }
};

bool operator < (Node A, Node B)
{
   return A.cost > B.cost;
}

struct Edge
{
  ll v, w;
};

vector<Edge> adj[lim];
priority_queue<Node> pq;
ll dist[lim];
ll path[lim];
ll n;

void dijkstra(int src)
{
     for(ll i = 0; i <= n; i++)
     {
        dist[i] = inf;
     }

     dist[src] = 0;
     pq.push(Node(src, 0));

     while(!pq.empty())
     {
        Node u = pq.top();
        pq.pop();

        //cout << u.cost << " " << u.At << "\n";

        if(u.cost != dist[u.At])
        {
			continue;
		}
		//cout << u.cost << " " << dist[u.At] << "\n";

        for(Edge e : adj[u.At])
        {
            if(dist[e.v] > u.cost + e.w)
            {
				dist[e.v] = u.cost + e.w;
				pq.push(Node(e.v, dist[e.v]));

				path[e.v] = u.At;
				//cout << u.At << " " << e.v << " \n";
            }
        }
     }
}


int main()
{
   ll m;
   cin >> n >> m;
   while(m--)
   {
      ll u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
   }
   dijkstra(1);
   if(dist[n] == inf)
   {
     cout << "-1\n";
   }
   else
   {
     vector<ll> vec;
     ll now = n;
     vec.push_back(now);
     while(now != 1)
     {
        now = path[now];
        vec.push_back(now);
     }
     for(ll i = vec.size() - 1; i >= 0; i--)
     {
        cout << vec[i] << " ";
	  }
     cout << '\n';
   }
   return 0;
}

