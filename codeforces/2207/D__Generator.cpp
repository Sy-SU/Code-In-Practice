#include<bits/stdc++.h>

using i64 = long long;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int rng(int l, int r) { // [l, r]
    return rnd() % (r - l + 1) + l;
}

void generate_tree(int n, int &v) {
    // 生成无根树，树的边一定是n-1条，且保证每个节点都有连接
    std::vector<std::pair<int, int>> edges;
    std::vector<int> degree(n + 1, 0); // 记录每个节点的度数（与其他节点的连接数）

    // 生成树的边
    for (int i = 2; i <= n; i++) {
        int parent = rng(1, i - 1); // 随机选择一个节点作为边的另一端
        edges.push_back({parent, i});
        degree[parent]++; // 父节点度数加1
        degree[i]++; // 当前节点度数加1
    }

    // 确保 v 不是叶子节点
    // 找到一个度数大于1的节点作为 v
    std::vector<int> non_leaf_nodes;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > 1) { // 该节点的度数大于1，不是叶子节点
            non_leaf_nodes.push_back(i);
        }
    }


    v = non_leaf_nodes[rng(0, non_leaf_nodes.size() - 1)]; // 从非叶子节点中随机选择 v

    std::cout << v << "\n";

    // 打印树的边
    for (auto& edge : edges) {
        std::cout << edge.first << " " << edge.second << "\n";
    }
}

int main() {
    int t = 1; // 设置测试用例的数量，可以根据需要修改
    std::cout << t << "\n";
    
    // 生成每个测试用例
    for (int _ = 0; _ < t; _++) {
        int n = rng(3, 100); // 随机生成节点数量，范围 [3, 500000]
        int k = rng(1, n); // 随机生成冷却时间
        int v; // Cyndaquil的起始节点，确保它不是叶子节点

        std::cout << n << " " << k << " ";
        generate_tree(n, v); // 生成无根树的结构并确定 v
    }

    return 0;
}