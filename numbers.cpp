#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>

enum class Color { WHITE = 0, GREY = 1, BLACK = 2 };

class Graph {
 public:
  std::vector<std::vector<int> > graph;
  std::vector<Color> colored;
  std::vector<int> dist;
  std::vector<int> parent;
  bool is_cyclic = false;
  void SetEdge(int v) {
    int n = v / 1000;
    if (n < 9) {
      graph[v].emplace_back(v + 1000);
    }
    if (v % 10 > 0) {
      graph[v].emplace_back(v - 1);
    }
    int c = v / 1000;
    graph[v].emplace_back((v % 1000) * 10 + c);
    int k = v / 10;
    graph[v].emplace_back(k + 1000 * (v % 10));
  }
  void Bfs(int v) {
    std::queue<int> q;
    colored[v] = Color::GREY;
    q.push(v);
    dist[v] = 0;
    parent[v] = -1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (const auto& edge : graph[x]) {
        if (colored[edge] == Color::WHITE) {
          colored[edge] = Color::GREY;
          dist[edge] = 1 + dist[x];
          parent[edge] = x;
          q.push(edge);
        }
      }
      colored[x] = Color::BLACK;
    }
  }
};

int main() {
  int start = 0;
  int finish = 0;
  std::cin >> start;
  std::cin >> finish;
  Graph gr;
  std::vector<int> ans;
  gr.graph.resize(10000);
  gr.colored.resize(10000, Color::WHITE);
  gr.dist.resize(10000, 9999999);
  gr.parent.resize(10000);
  for (int i = 1111; i < 10000; ++i) {
    if (i / 1000 == 0 || i % 10 == 0 || (i / 100) % 10 == 0 || (i / 10) % 10 == 0) {
      continue;
    }
    gr.SetEdge(i);
  }
  gr.Bfs(start);
  ans.push_back(finish);
  while (gr.parent[finish] != -1) {
    ans.push_back(gr.parent[finish]);
    finish = gr.parent[finish];
  }
  std::reverse(ans.begin(), ans.end());
  for (const auto& x : ans) {
    std::cout << x << '\n';
  }
}
