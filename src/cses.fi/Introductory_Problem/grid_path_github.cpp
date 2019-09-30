// https://cses.fi/problemset/task/1625
#include <bits/stdc++.h>

using namespace std;

string s;
int g[7][7];

int f(int x, int y, int i, char m) {

  if (i == 48) return 1;
  if (g[6][0]) return 0;
  if (m == 'L' && (y == 0 || g[x][y-1]) && x > 0 && x < 6 && !g[x-1][y] && !g[x+1][y]) return 0;
  if (m == 'R' && (y == 6 || g[x][y+1]) && x > 0 && x < 6 && !g[x-1][y] && !g[x+1][y]) return 0;
  if (m == 'U' && (x == 0 || g[x-1][y]) && y > 0 && y < 6 && !g[x][y-1] && !g[x][y+1]) return 0;
  if (m == 'D' && (x == 6 || g[x+1][y]) && y > 0 && y < 6 && !g[x][y-1] && !g[x][y+1]) return 0;
  if (s[i] == '?') {
    int r[] = {-1, 0, 1, 0};
    int c[] = {0, -1, 0, 1};
    int k = 0;
    for (int j = 0; j < 4; j++) {
      int xx = x + r[j];
      int yy = y + c[j];
      if (xx < 0 || xx > 6) continue;
      if (yy < 0 || yy > 6) continue;
      if (g[xx][yy]) continue;
      g[xx][yy] = true;
      k += f(xx, yy, i + 1, "ULDR"[j]);
      g[xx][yy] = false;
    }
    return k;
  }
  if (s[i] == 'L') y--;
  else if (s[i] == 'R') y++;
  else if (s[i] == 'U') x--;
  else if (s[i] == 'D') x++;
  if (y < 0 || y > 6) return 0;
  if (x < 0 || x > 6) return 0;
  if (g[x][y]) return 0;
  g[x][y] = true;
  int k = f(x, y, i + 1, s[i]);
  g[x][y] = false;
  return k;
}


int main() {
  cin >> s;
  g[0][0] = true;
  cout << f(0, 0, 0, 0) << endl;
}
