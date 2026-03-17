#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  int count = 0;

  std::string line;
  std::getline(std::cin, line);

  std::vector<std::string> matrix;
  for (int i = 0; i < n; i++) {
    std::getline(std::cin, line);
    matrix.push_back(line);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (matrix[i][j] == '.' && matrix[i][j + 1] == '.') count++;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == '.' && matrix[i + 1][j] == '.') count++;
    }
  }

  std::cout << count << '\n';

  return 0;
}
