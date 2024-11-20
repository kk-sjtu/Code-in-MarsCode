// 还没有ac，先传上
// 题目读错了。获得怪物属性这句话，可能没啥用

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


// version 2
#include <iostream>
#include <vector>
#include <algorithm>

int solution(int n, int H, int A, std::vector<int> h, std::vector<int> a) {
    // 动态规划，最长递增子序列
    // dp[i] 表示考虑前 i 个怪物，且需要击败第 i 个怪物，此时的最大击败数量
    int ans = 0;
    std::vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        // 打不过当前怪物，选择跳过
        if (h[i] >= H || a[i] >= A) {
            continue;
        }
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (h[i] > h[j] && a[i] > a[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        ans = std::max(ans, dp[i]);
    }
    return ans;
}

int main() {
    // 测试用例
    std::cout << solution(3, 4, 5, {1, 2, 3}, {3, 2, 1}) << std::endl; // 输出：1
    std::cout << solution(5, 10, 10, {6, 9, 12, 4, 7}, {8, 9, 10, 2, 5}) << std::endl; // 输出：2
    std::cout << solution(4, 20, 25, {10, 15, 18, 22}, {12, 18, 20, 26}) << std::endl; // 输出：3
    return 0;
}