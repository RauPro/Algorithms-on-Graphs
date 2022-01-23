#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;
enum { UNVISITED = -1, VISITED = -2 };
vector<int> dfs_num;
void dfs(vector<vector<int> > &adj, int u){
  dfs_num[u] = VISITED;
  for (size_t i = 0; i < adj[u].size(); i++)
  {
    if(dfs_num[adj[u][i]] == UNVISITED){
      dfs(adj, adj[u][i]);
    }
  }
  
}
int reach(vector<vector<int> > &adj, int x, int y) {
  dfs(adj, x);
  return dfs_num[y]==VISITED;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  dfs_num.assign(n, UNVISITED);
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
