#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

class Graph {
 public:
  std::vector<std::pair<int, int>> graph;
  std::vector<int> dist;
  int n;
  int m;
  int X;
  int Y;
  int Q;
  Graph(int n, int m, int X, int Y, int Q) : n(n), m(m), X(X - 1), Y(Y - 1), Q(Q) {
    dist.resize(n * m, INT_MAX);
    for (int i = 0; i < Q; ++i) {
      int x, y;
      std::cin >> x >> y;
      --x;
      --y;
      graph.emplace_back(x, y);
    }
  }
  void BFS() {
    std::queue<int> q;
    int v = X * m + Y;
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
      int from = q.front();
      q.pop();
      const std::vector<std::pair<int, int>> d = {{-1, 2}, {1, -2}, {-2, 1}, {2, -1}, {-2, -1}, {-1, -2}, {2, 1}, {1, 2}};
      for (const auto& [dx, dy] : d) {
        int x = from / m + dx;
        int y = from % m + dy;
        int to = from + dx * m + dy;
        if (x < n && y < m && x >= 0 && y >= 0 && dist[to] == INT_MAX) {
          dist[to] = dist[from] + 1;
          q.push(to);
        }
      }
    }
  }
};

int main() {
  int n, m, X, Y, Q;
  std::cin >> n >> m >> X >> Y >> Q;
  Graph g(n, m, X, Y, Q);
  g.BFS();
  int sum = 0;
  for (int i = 0; i < Q; ++i) {
    int k = g.graph[i].first * m + g.graph[i].second;
    if (g.dist[k] == INT_MAX) {
      std::cout << -1;
      return 0;
    }
    sum += g.dist[k];
  }
  std::cout << sum;
}
