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
  std::vector<int> parent;
  bool is_cyclic;
  int V;
  int E;
  Graph(int n, int m) : V(n), E(m) {
    colored.resize(n, Color::WHITE);
    graph.resize(n);
    parent.resize(n, -1);
    is_cyclic = false;
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
  void DFSVisit(int v, Color color) {
    colored[v] = color;
    for (const int& u : graph[v]) {
      if (is_cyclic) {
        return;
      }
      if (colored[u] == Color::WHITE) {
        DFSVisit(u, (color == Color::GREY) ? Color::BLACK : Color::GREY);
      }
      if (colored[u] == colored[v]) {
        is_cyclic = true;
        return;
      }
    }
  }
  void DFS() {
    for (int i = 0; i < V && !is_cyclic; ++i) {
      if (colored[i] == Color::WHITE) {
        DFSVisit(i, Color::GREY);
      }
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph g(n, m);
  g.DFS();
  if (!g.is_cyclic) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}
