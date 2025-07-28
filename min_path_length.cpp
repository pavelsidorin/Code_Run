#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

class Graph {
 public:
  std::vector<std::vector<int>> graph;
  std::vector<int> dist;
  bool is_cyclic;
  int V;
  Graph(int n) : is_cyclic(false), V(n) {
    graph.resize(n);
    dist.resize(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int x;
        std::cin >> x;
        if (x == 1) {
          graph[i].push_back(j);
        }
      }
    }
  }
  void BFS(int v) {
    std::queue<int> q;
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
      int from = q.front();
      q.pop();
      for (const auto& to : graph[from]) {
        if (dist[to] == INT_MAX) {
          dist[to] = dist[from] + 1;
          q.push(to);
        }
      }
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  Graph g(n);
  int source, sink;
  std::cin >> source >> sink;
  --source;
  --sink;
  g.BFS(source);
  std::cout << ((g.dist[sink] == INT_MAX) ? -1 : g.dist[sink]);
}
