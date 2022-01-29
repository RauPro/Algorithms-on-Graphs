#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
enum { UNVISITED = -1, VISITED = -2 };                     // basic flags

vector<int> dfs_num; 
vector<int> ts;

void dfs(vector<vector<int> > &adj, int u) {
  dfs_num[u] = VISITED;
  for (auto &v : adj[u])
    if (dfs_num[v] == UNVISITED)
      dfs(adj, v);
  ts.push_back(u);                               // this is the only change
}     

vector<int> toposort(vector<vector<int> > adj, int n) {
  dfs_num.assign(n, UNVISITED);                  // global variable
  ts.clear();                                    // global variable
  for (int u = 0; u < n; ++u)                    // same as finding CCs
    if (dfs_num[u] == UNVISITED)
      dfs(adj, u);
  reverse(ts.begin(), ts.end());                 // reverse ts or
  return ts;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj, n);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
