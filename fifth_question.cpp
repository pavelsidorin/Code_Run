#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Graph {
 public:
  std::vector<std::vector<int>> graph;
  std::vector<int> dist;
  int V;
  int E;
  explicit Graph(int n, int k) : V(n + 1), E(k) {
    graph.resize(V);
    dist.resize(V, INT_MAX);
    for (int i = 0; i < E; ++i) {
      int left, right;
      std::cin >> left >> right;
      graph[left - 1].push_back(right);
      graph[right].push_back(left - 1);
    }
  }
  void BFS() {
    dist[0] = 0;
    std::queue<int> q;
    q.push(0);
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
  int n, k;
  std::cin >> n >> k;
  Graph graph(n, k);
  graph.BFS();
  if (graph.dist[n] == INT_MAX) {
    std::cout << "No";
  } else {
    std::cout << "Yes" << '\n';
    std::cout << graph.dist[n];
  }
}
