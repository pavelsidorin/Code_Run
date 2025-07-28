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
  std::vector<Color> colored;
  std::vector<std::vector<int>> components;
  int V;
  int E;
  Graph(int n, int m) : V(n), E(m) {
    colored.resize(n, Color::WHITE);
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
      int v, u;
      std::cin >> v >> u;
      --v;
      --u;
      if (v != u) {
        graph[u].push_back(v);
        graph[v].push_back(u);
      }
    }
  }
  void DFSVisit(int v, int k) {
    colored[v] = Color::GREY;
    for (const int& u : graph[v]) {
      if (colored[u] == Color::WHITE) {
        DFSVisit(u, k);
      }
    }
    colored[v] = Color::BLACK;
    components[k].push_back(v + 1);
  }
  void DFS() {
    int k = 0;
    for (int i = 0; i < V; ++i) {
      if (colored[i] == Color::WHITE) {
        components.emplace_back();
        DFSVisit(i, k);
        ++k;
      }
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph g(n, m);
  g.DFS();
  std::cout << g.components.size() << '\n';
  for (const auto& component : g.components) {
    std::cout << component.size() << '\n';
    for (const int& x : component) {
      std::cout << x << " ";
    }
    std::cout << '\n';
  }
}
