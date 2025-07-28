#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

struct Coord {
  int x;
  int y;
  int z;
  Coord(int x, int y, int z) : x(x), y(y), z(z) {
  }
};

class Graph {
 public:
  std::vector<std::vector<std::vector<int>>> graph;
  std::vector<std::vector<std::vector<int>>> dist;
  int n;
  int X;
  int Y;
  int Z;
  Graph(int n) : n(n){
    dist.resize(n);
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
      graph[i].resize(n);
      dist[i].resize(n);
      for (int j = 0; j < n; ++j) {
        graph[i][j].resize(n, 0);
        dist[i][j].resize(n, INT_MAX);
        for (int k = 0; k < n; ++k) {
          char x = 0;
          std::cin >> x;
          if (x == '.') {
            graph[i][j][k] = 1;
          } else if (x == 'S') {
            graph[i][j][k] = 2;
            X = i;
            Y = j;
            Z = k;
          }
        }
      }
    }
  }
  void BFS() {
    std::queue<Coord> q;
    q.push(Coord(X, Y, Z));
    dist[X][Y][Z] = 0;
    while (!q.empty()) {
      Coord from = q.front();
      q.pop();
      const std::vector<Coord> d = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
      for (const auto& [dx, dy, dz] : d) {
        int x = from.x + dx;
        int y = from.y + dy;
        int z = from.z + dz;
        if (x < n && y < n && z < n && x >= 0 && y >= 0 && z >= 0 && graph[x][y][z] != 0 && dist[x][y][z] == INT_MAX) {
          dist[x][y][z] = dist[from.x][from.y][from.z] + 1;
          q.push(Coord(x, y, z));
        }
      }
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  Graph g(n);
  g.BFS();
  bool b = true;
  int min = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g.dist[0][i][j] != INT_MAX) {
        min = std::min(min, g.dist[0][i][j]);
        b = true;
      }
    }
  }
  if (b) {
    std::cout << min;
  } else {
    std::cout << -1;
  }
}
