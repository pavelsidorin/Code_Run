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
  std::vector<int> component;
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
  void DFS(int v = 0) {
    colored[v] = Color::GREY;
    for (const int& u : graph[v]) {
      if (colored[u] == Color::WHITE) {
        DFS(u);
      }
    }
    colored[v] = Color::BLACK;
    component.push_back(v + 1);
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph g(n, m);
  g.DFS();
  std::cout << g.component.size() << '\n';
  std::sort(g.component.begin(), g.component.end());
  for (const int& x : g.component) {
    std::cout << x << " ";
  }
}
