const int N = 1e5+2;
const int INF = 1e9;
int n; // take input, number of node
// weighted adjacency list.
// first element neighboring node
// second element weight of the edge
vector<pair<int, int>> adj[N];

struct Node
{
  int u, cost;
  Node() {} // default constructor
  Node(int _u, int _cost){
    u = _u;
    cost = _cost;
  }
};

bool operator<(Node A, Node B){
  // priority-queue is a max heap
  // so we need to compare the cost
  // in reverse order to get minimum
  // cost vertex at top
  return A.cost > B.cost;
}
priority_queue<Node> PQ;
// minimum cost so far for a node.

int cost[N];
// if the node is already taken
int taken[N];

int prim(){
  // INF = infinite, someting like 1e9
  for(int i = 0; i < n; i++){
    cost[i] = INF, taken[i] = 0;
  }
  // s is the vertex you want to start prim from
  int s = 0;
  cost[s] =  0;
  PQ.push(Node(s, 0));
  int ans = 0;
  while(!PQ.empty()){
    Node x = PQ.top();
    PQ.pop();

    if(taken[x.u]){
      // already visited.
      continue;
    }
    taken[x.u] = 1;
    ans += x.cost;
    for(auto v: adj[x.u]){
      if(taken[v.first]) continue;
      if(v.second  < cost[v.first]){
        // cost of current edge to v.first
        // is less than whatever we saw
        // so far.
        PQ.push(Node(v.first, v.second));
        cost[v.first] = v.second;
      }
    }
  }
  // printf("Cost of MST = %d\n", ans);
  return ans;
}