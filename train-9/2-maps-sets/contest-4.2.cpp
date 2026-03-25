#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, res = 0;
  std::cin >> n;
  std::string input;
  std::vector<std::string> words;
  for (int i = 0; i < n; i++) {
    std::cin >> input;
    words.push_back(input);
  }

  std::sort(words.begin(), words.end(), std::less());

  bool match = true;
  int temp = 0;
  for (int j = 0, len = words.back().length(); j < len && match; j++) {
    res = temp;
    for (int i = 0, size = words.size() - 1; i < size && match; i += 2) {
      if (words[i][j] == words[i + 1][j]) {
        temp = j + 1;
      } else {
        match = false;
      }
    }
  }

  if (match) res = temp;

  std::cout << res << '\n';

  return 0;
}