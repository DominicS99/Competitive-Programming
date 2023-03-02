#include <iostream>

int main() {
  int h, k, v, s, a = 0;
  std::cin >> h >> k >> v >> s;
  while (h > 0) {
    v += s;
    v -= std::max(1, v/10);
    if (v >= k) h++;
    if (v > 0 && v < k) {
      h--;
      if (h == 0) v = 0;
    }
    if (v <= 0) {
      h = 0; v = 0;
    }
    a += v;
    if (s > 0) s--;
  }
  std::cout << a;
  return 0;
}
