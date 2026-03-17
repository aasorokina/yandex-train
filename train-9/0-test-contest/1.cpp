#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::reverse(input.begin(), input.end());
  std::stringstream ss(input);
  std::deque<char> res;

  char c = 0;
  while (ss.get(c)) {
    char letter;
    if (c == '#') {
      char last, first;
      ss >> last >> first;
      int num = (first - '0') * 10 + (last - '0');
      letter = 'j' - 10 + num;
    } else {
      letter = 'j' - 10 + (c - '0');
    }
    res.push_front(letter);
  }

  for (auto it = res.begin(), end = res.end(); it != end; ++it) {
    std::cout << *it;
  }
  std::cout << '\n';

  return 0;
}
