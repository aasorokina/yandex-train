#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using ull = unsigned long long int;
using ll = long long int;

char get_action(std::string &temp, ull &number);

int main() {
  ull n;
  std::cin >> n;
  getchar();
  std::deque<ull> stack;
  std::deque<ull>prefix(1, 0);
  
  for (int i = 0; i < n; i++) {
    std::string temp;
    ull number = 0;
    std::getline(std::cin, temp);
    char action = get_action(temp, number);

    if(action == '+'){
      stack.push_back(number);
      prefix.push_back(prefix.back()+ number);
    }
    else if(action == '-'){
      std::cout << stack.back() << '\n';
      stack.pop_back();
      prefix.pop_back();
    }
    else if(action == '?'){
      std::cout << (prefix.back() - prefix[prefix.size() - number - 1]) << '\n';
    }
  }
 
  return 0;
}

char get_action(std::string &temp, ull &number){
  char action = temp[0];
  for (ull i = 1; i < temp.size(); i++) {
    number = number * 10 + (temp[i] - '0');
  }
  return action;
}