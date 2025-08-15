#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

using lb = long double;

constexpr lb eps = 1e-16;
using namespace std;

lb r;

lb oj(lb x1, lb y1, lb z1, lb x2, lb y2, lb z2) {
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) < 0) {
        return 0;
    }
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

lb hu(lb x1, lb y1, lb z1, lb x2, lb y2, lb z2) {
    lb d = oj(x1, y1, z1, x2, y2, z2);
    lb num = 2 * r * r - d * d;
    num = 1.0 * num / (2 * r * r);
    if (num > 1) {
        num = 1;
    } else if (num < -1) {
        num = -1;
    }
    return r * acos(num);
}

// struct Point
struct Point {
    lb x, y, z;
};

void solve() {
    lb a1, b1, c1, a2, b2, c2, a3, b3, c3;
    lb x1, y1, z1;
    lb x2, y2, z2;
    lb x3, y3, z3;

    cin >> r;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3;

    x3 = r * a1 / sqrt(a1 * a1 + b1 * b1 + c1 * c1);
    y3 = r * b1 / sqrt(a1 * a1 + b1 * b1 + c1 * c1);
    z3 = r * c1 / sqrt(a1 * a1 + b1 * b1 + c1 * c1);

    x2 = r * a2 / sqrt(a2 * a2 + b2 * b2 + c2 * c2);
    y2 = r * b2 / sqrt(a2 * a2 + b2 * b2 + c2 * c2);
    z2 = r * c2 / sqrt(a2 * a2 + b2 * b2 + c2 * c2);

    x1 = r * a3 / sqrt(a3 * a3 + b3 * b3 + c3 * c3);
    y1 = r * b3 / sqrt(a3 * a3 + b3 * b3 + c3 * c3);
    z1 = r * c3 / sqrt(a3 * a3 + b3 * b3 + c3 * c3);

    Point p1, p2, p3;
    p1 = {x1, y1, z1};
    p2 = {x2, y2, z2};
    p3 = {x3, y3, z3};

    // std::cerr << x1 << " " << y1 << " " << z1 << '\n';
    // std::cerr << x2 << " " << y2 << " " << z2 << '\n';
    // std::cerr << x3 << " " << y3 << " " << z3 << '\n';

    Point np1, np2, np3;
    np1 = {r, 0, 0};

    np2.x = x1 * x2 + y1 * y2 + z1 * z2;
    np2.x /= r;
    if (r * r - np2.x * np2.x < 0) {
        np2.y = 0; 
    } else {
        np2.y = sqrtl(r * r - np2.x * np2.x);
    }
    np2.z = 0;

    np3.x = x1 * x3 + y1 * y3 + z1 * z3;
    np3.x /= r;

    np3.y = x2 * x3 + y2 * y3 + z2 * z3;
    // std::cerr << np3.y << " " << x2 << " " << x3 << " " << y2 << " " << y3 << " " << z2 << " " << z3 << '\n';
    // np3.y /= r;
    // std::cerr << np3.y << '\n';
    np3.y -= np2.x * np3.x;
    np3.y /= np2.y;

    if (r * r - np3.x * np3.x - np3.y * np3.y < 0) {
        np3.z = 0;
    } else {
        np3.z = sqrtl(r * r - np3.x * np3.x - np3.y * np3.y);
    }

    // std::cerr << np1.x << " " << np1.y << " " << np1.z << '\n';
    // std::cerr << np2.x << " " << np2.y << " " << np2.z << '\n';
    // std::cerr << np3.x << " " << np3.y << " " << np3.z << '\n';

    lb pzx = np3.x, pzy = np3.y;
    lb tzx = np2.x, tzy = np2.y;
    lb thiP = atan2(pzy, pzx), thiT = atan2(tzy, tzx);
    lb ans = 1e9;
    if (thiP < thiT + eps && thiP > -eps) {
        // 在里面
        lb ang = 0;
        if (sqrtl(pzx * pzx + pzy * pzy) / r > 1) {
            ang = 1;
        } else if (sqrtl(pzx * pzx + pzy * pzy) / r < -1) {
            ang = -1;
        } else {
            ang = sqrtl(pzx * pzx + pzy * pzy) / r;
        }
        lb thi = acos(ang);
        ans = thi * r;
    } else {
        // 不在
        ans = std::min(hu(np3.x, np3.y, np3.z, np1.x, np1.y, np1.z),
                       hu(np3.x, np3.y, np3.z, np2.x, np2.y, np2.z));
    }
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
