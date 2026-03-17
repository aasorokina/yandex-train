#include <algorithm>
#include <iostream>

using ll = long long;

int main() {
  ll p, v, q, m, res;
  std::cin >> p >> v >> q >> m;

  ll min = std::min(p, q);
  if (min < 0) {
    p += -min;
    q += -min;
  }

  res = (v * 2 + 1) + (m * 2 + 1);

  if (p < q) {
    if (p + v >= q - m) {
      res -= (p + v - (q - m) + 1);
      if (p + v >= q + m) {
        res = v * 2 + 1;
      }
    }

  } else if (p > q) {
    if (q + m >= p - v) {
      res -= (q + m - (p - v) + 1);
      if (q + m >= p + v) {
        res = m * 2 + 1;
      }
    }

  } else {
    res = std::max(v, m) * 2 + 1;
  }

  std::cout << res << "\n";
  return 0;
}
