#include <bits/stdc++.h>
 
using i64 = long long;
 
constexpr int N = 20 + 10;
 
struct POS {
    int x, y;
};
 
int n;
 
POS npc[N]; //
 
bool map[105][105]; //
int pw[N];          //
POS dirc[5] = {{0, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 0}};
 
bool vali(POS p) {
    return p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= n;
}
 
void solve() {
    int m, sx, sy;
    std::cin >> n >> m >> sx >> sy;
 
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            map[i][j] = 0;
        }
    }
 
    map[sx][sy] = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        map[x][y] = 1;
        npc[i] = {x, y};
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> pw[i];
    }

    int q;
    std::cin >> q;
    std::vector<std::pair<char, char>> op;
    for (int i = 1; i <= q; i++) {
        char s, c;
        std::cin >> s >> c;
        op.push_back({s, c});
    }
    int idx = 0;
    for (const auto &[s, c] : op) {
        idx++;
        if (idx == m + 1)
            idx = 1;
        auto &[nx, ny] = npc[idx];
        if (s == 'N') {
            // y++
            if (map[nx][ny + 1]) {
                std::cout << "Illegal Operation!" << '\n';
                return;
            }
            map[nx][ny] = 0;
            ny++;
            map[nx][ny] = 1;
        } else if (s == 'S') {
            // y--
            if (map[nx][ny - 1]) {
                std::cout << "Illegal Operation!" << '\n';
                return;
            }
            map[nx][ny] = 0;
            ny--;
            map[nx][ny] = 1;
        } else if (s == 'W') {
            // x--
            if (map[nx - 1][ny]) {
                std::cout << "Illegal Operation!" << '\n';
                return;
            }
            map[nx][ny] = 0;
            nx--;
            map[nx][ny] = 1;
        } else if (s == 'E') {
            // x++
            if (map[nx + 1][ny]) {
                std::cout << "Illegal Operation!" << '\n';
                return;
            }
            map[nx][ny] = 0;
            nx++;
            map[nx][ny] = 1;
        }
 
        if (c == '+') {
            pw[idx]++;
        } else if (c == '-') {
            pw[idx]--;
        }
 
        if (pw[idx] < 0) {
            std::cout << "Illegal Operation!" << '\n';
            return;
        }
 
        if (vali({nx, ny}) == 0) {
            std::cout << "Illegal Operation!" << '\n';
            return;
        }
 
        // 操作合法
        std::cout << "Legal Operation!" << '\n';
        bool mustescape = 1;
        std::vector<POS> ok;
        for (int d = 0; d <= 4; d++) {
            // 判断到所有小怪的曼哈顿距离和其攻击半径
            int tox = sx + dirc[d].x, toy = sy + dirc[d].y;
            if (vali({tox, toy}) == 0)
                continue;
            bool isok = 1;
            for (int i = 1; i <= m; i++) {
                if (std::abs(tox - npc[i].x) + std::abs(toy - npc[i].y) <= pw[i]) {
                    isok = 0;
                    break;
                }
            }
            if (isok) {
                mustescape = 0;
                ok.push_back({tox, toy});
            }
        }
        if (mustescape) {
            std::cout << "Escape!" << '\n';
            return;
        }
        // 找最小
        POS lst;
        int max = 0;
        for (const auto &[okx, oky] : ok) {
            int mindis = 1e9;
            for (int i = 1; i <= m; i++) {
                if (std::abs(okx - npc[i].x) + std::abs(oky - npc[i].y) < mindis) {
                    mindis = std::abs(okx - npc[i].x) + std::abs(oky - npc[i].y);
                }
            }
            if (mindis > max) {
                max = mindis;
                lst = {okx, oky};
            }
        }
        map[sx][sy] = 0;
        std::cout << lst.x << " " << lst.y << '\n';
        sx = lst.x, sy = lst.y;
        map[sx][sy] = 1;
    }
    std::cout << "Grandmaster General Kangaroo!" << '\n';
}
 
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
