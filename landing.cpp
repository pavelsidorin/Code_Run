#include <iostream>
#include <vector>

struct Coord {
  int x;
  int y;
  Coord(int x, int y) : x(x), y(y) {
  }
};

enum class Color {
  WHITE = 0,
  GREY = 1,
  BLACK = 2
};

class Graph {
 public:
  std::vector<std::vector<int>> graph;
  std::vector<std::vector<Color>> colored;
  int count_traps;
  int n;
  int m;

  explicit Graph(int n, int m) : n(n), m(m) {
    graph.resize(n);
    colored.resize(n);
    count_traps = 0;
    for (int i = 0; i < n; ++i) {
      graph[i].resize(m);
      colored[i].resize(m, Color::WHITE);
      for (int j = 0; j < m; ++j) {
        std::cin >> graph[i][j];
      }
    }
  }

  void DFSVisit(int i, int j, std::vector<Coord>& sorted) {
    colored[i][j] = Color::GREY;
    std::vector<Coord> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& [dx, dy] : d) {
      int x = i + dx;
      int y = j + dy;
      if (x >= 0 && x < n && y >= 0 && y < m && colored[x][y] == Color::WHITE && graph[x][y] == graph[i][j]) {
        DFSVisit(x, y, sorted);
      }
    }
    sorted.emplace_back(i, j);
    colored[i][j] = Color::BLACK;
  }

  void DFS() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (colored[i][j] == Color::WHITE) {
          std::vector<Coord> sorted;
          DFSVisit(i, j, sorted);
          bool b = false;
          for (const auto& from : sorted) {
            std::vector<Coord> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (const auto& [dx, dy] : d) {
              int x = from.x + dx;
              int y = from.y + dy;
              if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] < graph[from.x][from.y]) {
                b = true;
                break;
              }
            }
            if (b) {
              break;
            }
          }
          if (!b) {
            ++count_traps;
          }
        }
      }
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph graph(n, m);
  graph.DFS();
  std::cout << graph.count_traps;
}
