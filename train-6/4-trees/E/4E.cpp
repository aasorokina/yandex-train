#include <iostream>
#include <vector>

int dfs(std::vector<std::vector<int>> &graph, int vertex, int parent,
        std::vector<int> &result);

int main() {
  int n, a, b;
  std::cin >> n;
  std::vector<int> result(n);
  std::vector<std::vector<int>> graph(n);

  for (int i = 0; i < n - 1; i++) {
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(graph, 0, -1, result);

  for (auto item : result) std::cout << item << ' ';
  std::cout << '\n';

  return 0;
}

int dfs(std::vector<std::vector<int>> &graph, int vertex, int parent,
        std::vector<int> &result) {
  int size = 1;

  for (int child : graph[vertex]) {
    if (child != parent) {
      size += dfs(graph, child, vertex, result);
    }
  }

  result[vertex] = size;
  return size;
}