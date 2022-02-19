#include <bits/stdc++.h>


using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
const ll INF = LONG_MAX; // INF = 1B, not 2^31-1 to avoid overflow

int main() {
  ll V, E;
  std::cin >> V >> E;
  vector<vii> AL(V, vii());
  while (E--)  {
    ll u, v,w; cin>>u>>v>>w;
    AL[u-1].emplace_back(v-1,w);
  }
  ll s, t;cin>>s>>t;
  t--;s--;
  vi dist(V, INF); dist[s] = 0;
  set<ii> pq;
  for (size_t u = 0; u < V; u++){
    pq.insert({dist[u], u});
  }
  while (!pq.empty())
  {
    pair<ll, ll> edge = *pq.begin();
    ll d = edge.first;
    ll u =  edge.second;
    pq.erase(pq.begin());
    for (auto &edgePair: AL[u]){
      ll v = edgePair.first;
      ll w = edgePair.second;
      if(dist[u]+w >= dist[v])continue;
      pq.erase(pq.find({dist[v], v}));
      dist[v] =  dist[u]+w;
      pq.insert({dist[v], v});
      //cout<< dist[v] << " " << v<<endl;
    }
    
  }
  cout<<dist[t]<<endl;
}
