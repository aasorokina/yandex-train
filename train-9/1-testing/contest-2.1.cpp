#include <algorithm>
#include <iostream>

char next_possible(char c) {
  if (c == 'a') return 'h';
  if (c = 'h') return 'a';
  return ' ';
}

int main() {
  int n, res = 0;
  std::cin >> n;
  std::string input;
  std::cin >> input;

  for (int i = 0; i < n; i++) {
    if (input[i] == 'a' || input[i] == 'h') {
      int count = 1;
      while ((i < n - 1) && input[i + 1] == next_possible(input[i])) {
        count++;
        i++;
      }
      res = std::max(res, count);
    }
  }

  std::cout << res << '\n';
  return 0;
}