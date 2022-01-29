#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;
enum { UNVISITED = -1, EXPLORED = -2, VISITED = -3 };           // three flags
vector<int> dfs_num; 
vector<int> dfs_parent;  
bool flag = false;
bool cycleCheck(int u, vector<vector<int> > &adj) { // check edge properties
  dfs_num[u] = EXPLORED;                         // color u as EXPLORED
  for (auto &v : adj[u]) {                   // C++17 style, w ignored
    if (dfs_num[v] == UNVISITED) {               // EXPLORED->UNVISITED
      dfs_parent[v] = u;                         // a tree edge u->v
      cycleCheck(v, adj);
    }
     else if (dfs_num[v] == EXPLORED) {           // EXPLORED->EXPLORED
     // cout<<1<<endl;
      flag = true;
      return true;
    }
  }
  dfs_num[u] = VISITED;                          // color u as VISITED/DONE
  return false;
}

int acyclic(vector<vector<int> > &adj, int n) {
  dfs_num.assign(n, UNVISITED);
  dfs_parent.assign(n, -1);
  //write your code here
  for (size_t i = 0; i < n; i++)
  {
    bool status = cycleCheck(i, adj);
    //std::cout<<status;
    if (flag){
      return true;
    }
  }
  
  return 0;
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
  
  std::cout << acyclic(adj, n);
}
