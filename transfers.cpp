#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <climits>

class Graph {
 public:
  std::vector<std::vector<int>> graph;
  std::vector<std::set<int>> lines;
  std::vector<int> dist;
  int n;
  int m;
  Graph(int n, int m) : n(n), m(m) {
    dist.resize(n, INT_MAX);
    lines.resize(m);
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
      int x;
      std::cin >> x;
      for (int j = 0; j < x; ++j) {
        int y;
        std::cin >> y;
        --y;
        lines[i].insert(y);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (lines[j].find(i) != lines[j].end()) {
          graph[i].push_back(j);
        }
      }
    }

  }
  void BFS0_1(int v) {
    std::deque<int> q;
    q.push_back(v);
    dist[v] = 0;
    std::vector<int> line;
    for (int i = 0; i < m; ++i) {
      const auto& l = lines[i];
      if (l.find(v) != l.end()) {
        line.push_back(i);
      }
    }
    while (!q.empty()) {
      int from = q.front();
      q.pop_front();
      for (const auto& x : line) {
        for (const auto& to : lines[x]) {
          if (dist[to] == INT_MAX) {
            q.push_front(to);
            dist[to] = dist[from];
          }
        }
      }
      for (const auto& x : graph[from]) {
        for (const auto& to : lines[x]) {
          if (dist[to] == INT_MAX) {
            q.push_back(to);
            dist[to] = dist[from] + 1;
          }
        }
      }
    }
  }
};

int main() {
  int n, m, source, sink;
  std::cin >> n >> m;
  Graph g(n, m);
  std::cin >> source >> sink;
  --source;
  --sink;
  g.BFS0_1(source);
  std::cout << ((g.dist[sink] == INT_MAX) ? -1 : g.dist[sink]);
}
