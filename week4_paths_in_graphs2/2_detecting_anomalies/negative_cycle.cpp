#include <bits/stdc++.h>


using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;
const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main() {
  int V, E;cin>>V>>E;
  vector<vii> AL(V, vii());
  while (E--){
    int u, v, w;cin>>u >>v>>w;
    AL[u-1].emplace_back(v-1,w);
  }
  vi dist(V, INF); dist[0]=0;
  for (size_t i = 0; i < V-1; i++)
  {
    bool modified = false;
    for (int u;u<V;u++){
      if (dist[u] != INF){
        for (auto &edgePair: AL[u]){
          int v = edgePair.first;
          int w = edgePair.second;
          if(dist[u]+w >= dist[v])continue;
          dist[v] = dist[v]+w;
          modified = true;
        }
      }
    }
    if(modified){
      break;
    }
  }
  bool negativeCycle = false;
  for (size_t u = 0; u < V; u++)
  {
    if(dist[u]!=INF){
      for (auto &edgePair: AL[u]){
          int v = edgePair.first;
          int w = edgePair.second;
          if(dist[v] > dist[u]+w)negativeCycle = true;
        }
    }
  }
  cout<< negativeCycle <<endl;
  
  
}
