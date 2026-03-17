#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using ull = unsigned long long int;
using ll = long long int;

int main() {
  std::string input;
  std::deque<ll> stack;
  std::getline(std::cin, input);

  for (ull i = 0; i < input.size(); i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      ll number = 0;
      while (input[i] != ' ' && i < input.size()) {
        number = number * 10 + (input[i] - '0');
        i++;
      }
      stack.push_back(number);
    }
    if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
      ll number;
      if (input[i] == '+') number = *(stack.end() - 1) + *(stack.end() - 2);
      if (input[i] == '-') number = *(stack.end() - 2) - *(stack.end() - 1);
      if (input[i] == '*') number = *(stack.end() - 1) * *(stack.end() - 2);
      stack.pop_back();
      stack.pop_back();
      stack.push_back(number);
    }
  }

  std::cout << stack.back() << '\n';
  return 0;
}