#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;

vector<int> p;
const int INF = 1e9;
int aws = 0;
void printPath(int u){
  if (p[u] == -1) {return;}
  printPath(p[u]);
  aws++;
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  return aws == 0 ? -1 : aws;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  vector<int> dist(n, INF); dist[s] = 0;
  queue<int> q; q.push(s);
  p.assign(n,-1);
  while (!q.empty()){
    int u = q.front(); q.pop();
    if(u == t) break;
    for (size_t i = 0; i < adj[u].size(); i++){
      if (dist[adj[u][i]] != INF)continue;
      dist[adj[u][i]] = dist[u]+1;
      p[adj[u][i]] = u;
      q.push(adj[u][i]);
    }
  }
  printPath(t);
  std::cout << distance(adj, s, t);
}
