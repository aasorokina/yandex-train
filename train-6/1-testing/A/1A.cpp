#include <iostream>

int main() {
  int x, y, x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
  std::string res;

  if (x >= x1 && x <= x2) res = (y > y2) ? "N" : "S";
  else if (y >= y1 && y <= y2) res = (x > x2) ? "E" : "W";
  else if (x < x1) res = (y > y2) ? "NW" : "SW";
  else if (x > x2) res = (y > y2) ? "NE" : "SE";

  std::cout << res << "\n";
  return 0;
}