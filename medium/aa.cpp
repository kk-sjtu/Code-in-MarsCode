// 还没有ac，先传上

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Monster {
    int health;
    int attack;
};

int solution(int n, int H, int A, vector<int> h, vector<int> a) {
    vector<Monster> monsters(n);
    for (int i = 0; i < n; ++i) {
        monsters[i] = {h[i], a[i]};
    }

    // dp[i][j] 表示在前 i 个怪物中，击败 j 个怪物时的最大血量和攻击力
    vector< vector<pair<int, int>> > dp(n + 1, vector<pair<int, int>>(n + 1, {0, 0}));
    dp[0][0] = {H, A};

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            // 不击败第 i 个怪物
            dp[i][j] = dp[i - 1][j];
            // 尝试击败第 i 个怪物
            if (j > 0 && dp[i - 1][j - 1].first > monsters[i - 1].health && dp[i - 1][j - 1].second > monsters[i - 1].attack) {
                dp[i][j] = max(dp[i][j], {monsters[i - 1].health, monsters[i - 1].attack});
            }
        }
    }

    int maxMonsters = 0;
    for (int j = 0; j <= n; ++j) {
        if (dp[n][j].first > 0 && dp[n][j].second > 0) {
            maxMonsters = max(maxMonsters, j);
        }
    }

    return maxMonsters;
}

int main() {
    // 测试用例
    cout << solution(3, 4, 5, {1, 2, 3}, {3, 2, 1}) << endl; // 输出：1
    cout << solution(5, 10, 10, {6, 9, 12, 4, 7}, {8, 9, 10, 2, 5}) << endl; // 输出：2
    cout << solution(4, 20, 25, {10, 15, 18, 22}, {12, 18, 20, 26}) << endl; // 输出：3
    return 0;
}