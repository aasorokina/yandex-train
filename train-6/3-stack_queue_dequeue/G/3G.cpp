#include <iostream>
#include <vector>

using ull = unsigned long long int;
using ll = long long int;

int main() {
  ull n, b, answer;
  std::cin >> n >> b;
  std::vector<ull> clients(n + 1, 0);

  for (ull i = 0; i < n; i++) {
    std::cin >> clients[i];
  }
  answer = 0;
  for (ull i = 0; i < n; i++) {
    if (clients[i] > b) clients[i + 1] += (clients[i] - b);
    answer += clients[i];
  }
  answer += clients[n];

  std::cout << answer << '\n';
  return 0;
}