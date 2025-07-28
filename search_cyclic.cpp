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
  std::vector<int> cyclic_path;
  std::vector<int> parent;
  std::vector<Color> colored;
  bool is_cyclic;
  int V;
  Graph(int n) : is_cyclic(false), V(n) {
    colored.resize(n, Color::WHITE);
    graph.resize(n);
    parent.resize(n, -1);
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
  void DFSVisit(int v) {
    colored[v] = Color::GREY;
    for (const int& u : graph[v]) {
      if (colored[u] == Color::WHITE) {
        parent[u] = v;
        DFSVisit(u);
      }
      if (colored[u] == Color::GREY && parent[v] != u && !is_cyclic) {
        is_cyclic = true;
        int p = v;
        cyclic_path.push_back(p + 1);
        while (parent[p] != -1 && parent[p] != u) {
          p = parent[p];
          cyclic_path.push_back(p + 1);
        }
        cyclic_path.push_back(u + 1);
        return;
      }
    }
    colored[v] = Color::BLACK;
  }
  void DFS() {
    for (int i = 0; i < V && !is_cyclic; ++i) {
      if (colored[i] == Color::WHITE) {
        DFSVisit(i);
      }
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  Graph g(n);
  g.DFS();
  if (!g.is_cyclic) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES" << '\n' << g.cyclic_path.size() << '\n';
  for (const auto& x : g.cyclic_path) {
    std::cout << x << " ";
  }
}
