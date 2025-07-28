#include <iostream>
#include <vector>
#include <algorithm>

enum class Color {
  WHITE = 0,
  GREY = 1,
  BLACK = 2
};

class Graph {
 public:
  std::vector<std::vector<int>> graph;
  std::vector<int> sorted;
  std::vector<Color> colored;
  bool is_cyclic;
  int V;
  int E;
  Graph(int n, int m) : is_cyclic(false), V(n), E(m) {
    colored.resize(n, Color::WHITE);
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
      int v, u;
      std::cin >> v >> u;
      --v;
      --u;
      graph[u].push_back(v);
    }
  }
  void DFSVisit(int v) {
    colored[v] = Color::GREY;
    for (const int& u : graph[v]) {
      if (is_cyclic) {
        return;
      }
      if (colored[u] == Color::WHITE) {
        DFSVisit(u);
      }
      if (colored[u] == Color::GREY) {
        is_cyclic = true;
        return;
      }
    }
    colored[v] = Color::BLACK;
    sorted.push_back(v + 1);
  }
  void DFS() {
    for (int i = 0; i < V; ++i) {
      if (colored[i] == Color::WHITE) {
        DFSVisit(i);
      }
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph g(n, m);
  g.DFS();
  if (g.is_cyclic) {
    std::cout << -1;
    return 0;
  }
  for (const auto& x : g.sorted) {
    std::cout << x << " ";
  }
}
