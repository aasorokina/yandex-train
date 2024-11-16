#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using ull = unsigned long long int;
using ll = long long int;

std::deque<ll> calculate_answer(std::string const& input);

int main() {
  std::string input;
  std::deque<ll> stack;
  std::string polish_stack;
  std::deque<std::pair<char, int>> symbol_stack;
  bool wrong = 0;
  std::getline(std::cin, input);

  bool num = false;
  bool symb = false;
  bool br = false;
  int brackets = 0;
  for (ull i = 0; i < input.size() && wrong == false; i++) {
    if (input[i] >= '0' && input[i] <= '9' && num == false) {
      std::string number;
      while ((input[i] >= '0' && input[i] <= '9') && i < input.size()) {
        number += input[i];
        i++;
      }
      polish_stack.append(number + ' ');
      br = false;
      num = true;
      symb = false;
    }
    if ((input[i] == '+' || input[i] == '-' || input[i] == '*' ||
         input[i] == ' ') &&
        symb == false) {
      if (input[i] != ' ') {
        num = false;
      }
      if (input[i] == '+' || input[i] == '-') {
        if (i == 0 || br == true) polish_stack.append("0 ");
        while (!symbol_stack.empty() && symbol_stack.back().second <= 3 &&
               symbol_stack.back().first != '(') {
          polish_stack += symbol_stack.back().first;
          symbol_stack.pop_back();
        }
        symbol_stack.push_back({input[i], 3});
        symb = true;
        br = false;
      }
      if (input[i] == '*') {
        if (polish_stack.empty() || br == true) wrong = true;
        while (!symbol_stack.empty() && symbol_stack.back().second <= 2 &&
               symbol_stack.back().first != '(') {
          polish_stack += symbol_stack.back().first;
          symbol_stack.pop_back();
        }
        symbol_stack.push_back({input[i], 2});
        symb = true;
      }
    } else if (input[i] == '(' || input[i] == ')') {
      if (input[i] == '(') {
        brackets--;
        symbol_stack.push_back({input[i], 1});
        br = true;
        symb = false;
      } else if (input[i] == ')' && brackets < 0 && br == false) {
        brackets++;
        while (!symbol_stack.empty() && symbol_stack.back().first != '(') {
          polish_stack += symbol_stack.back().first;
          symbol_stack.pop_back();
        }
        symbol_stack.pop_back();
      } else
        wrong = true;
    } else {
      if (i < input.size() && input[i] != ' ') wrong = true;
    }
  }

  if (brackets != 0 || symb == true) {
    wrong = true;
  } else if (wrong != true) {
    while (!symbol_stack.empty()) {
      polish_stack += symbol_stack.back().first;
      symbol_stack.pop_back();
    }
    stack = calculate_answer(polish_stack);
  }

  if (wrong)
    std::cout << "WRONG\n";
  else
    std::cout << stack.back() << '\n';
  return 0;
}

std::deque<ll> calculate_answer(std::string const& input) {
  std::deque<ll> stack;
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
  return stack;
}