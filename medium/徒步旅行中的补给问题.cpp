#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



//version 1

// 先买粮食再吃
int solution(int n, int k, std::vector<int> data) {
    // Edit your code here
    int cost = 0;
    //int cur = 0;
    int now=0;
    int flag=0;
    int nums=0;
    for (auto cur = data.begin(); cur != data.end(); ++cur) {
        
            for(auto index = cur+1 ;index!=cur+1+k && nums<n;index++){
                if(*cur<= *index)
                    {
                        ++nums;
                        cost += *cur;
                        ++now ;
                        /*
                        cout<< "买当前第"<<flag<<"个:"<<cost<<endl;
                        cout<< "第"<<"cur"<<":"<<*cur<<endl;
                        cout<<"THE NUM OF NOW"<<":"<<now<<endl;
                        */
                        continue;
                        
                    }
                if(!now){
                    //cout<< "迫不得已买比较大的"<<"cur"<<":"<<*cur<<endl;
                    nums++;
                    now++;
                        cost += *cur;
                        break;
                }
                if(*cur>=*index /* && now */ )
                {
                    break;
                }
        /*
                if(!now){
                        cost += data[cur];
                        now += 1;
                        continue;
        }
        */
                
                
    }
                flag++;
                now -=1;
    }
    //cout<< cost;
    return cost;
}

int main() {
    // Add your test cases here
    std::cout << (solution(6, 3, {4, 1, 5, 2, 1,3}) == 9) << std::endl;
    std::cout << (solution(1, 1, {2})) << std::endl;
    return 0;
}

// version 2
// 测试了4个样例正确，但是solution(13, 6, {6,19,19,3,3,25,16,17,8,1,5,21,2} 失败了。自己用笔算了算，很多地方都是错误的。
// 看群有说，可能需要动态规划。等晚上再看一看


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 先买粮食再吃
int solution(int n, int k, std::vector<int> data) {
    int cost = 0;
    int now = 0;
    int nums = 0; // 吃了几次了，对应天数

    for (auto cur = data.begin(); cur != data.end(); ++cur) {
        // 检查是否需要购买食物
        if (now == 0) {
            cost += *cur;
            now = 1;
            nums++;
            cout<<"now=0:" <<*cur<<endl;
        }

        // 检查是否需要提前购买食物
        for (auto index = cur + 1; index != data.end() &&  nums < n && now<k; ++index) {
            if (*cur <= *index) {
                cost += *cur;
                now++;
                nums++;
                cout<<"TEST:" <<*cur<<endl;
                cout<<"index:" <<*index<<endl;
            } else {
                break;
            }
        }
        cur += 
        // 消耗一份食物
        now--;
    }

    return cost;
}

int main() {
    // Add your test cases here
   // std::cout << (solution(6, 3, {4, 1, 5, 2, 1, 3}) == 9) << std::endl;
    std::cout << (solution(13, 6, {6,19,19,3,3,25,16,17,8,1,5,21,2})) << std::endl;
    return 0;
}

// version 3

// 双端队列和滑动窗口

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int solution(int n, int k, std::vector<int> data) {
    deque<int> dq; // 双端队列，用于存储当前窗口内的最小值的索引
    vector<int> min_costs; // 存储每个窗口的最小值

    for (int i = 0; i < n; ++i) {
        // 移除不在窗口范围内的元素
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // 将当前元素加入双端队列，并保持队列单调递增
        while (!dq.empty() && data[dq.back()] >= data[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        // 记录每个窗口的最小值
        if (i >= k - 1) {
            min_costs.push_back(data[dq.front()]);
        }
    }

    int res = 0;
    int min = data[0];
    for (int i = 0; i < k; ++i) {
        if (data[i] >= min) {
            res += min;
        } else {
            min = data[i];
            res += min;
        }
    }

    for (int i = 1; i < min_costs.size(); ++i) {
        res += min_costs[i];
    }

    return res;
}

int main() {
    std::cout << solution(13, 6, {6, 19, 19, 3, 3, 25, 16, 17, 8, 1, 5, 21, 2}) << std::endl; // 输出：40

    return 0;
}


// version 4

// 动态规划

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solution(int n, int k, vector<int> data) {
    vector<int> dp(n, 0); // 动态规划数组，存储每一天的累计最小花费
    dp[0] = data[0]; // 第一天的花费就是第一个补给站的价格

    for (int i = 1; i < n; ++i) {
        int curCost = (i < data.size()) ? data[i] : INT_MAX; // 当前价格，如果没有补给站则为无穷大
        int minCost = dp[i - 1]; // 初始化为前一天的最小花费

        // 遍历前k天，找到最小的花费
        for (int j = 1; j <= k && i - j >= 0; ++j) {
            minCost = min(minCost, dp[i - j]);
        }

        dp[i] = minCost + curCost; // 今天的总花费等于前k天的最小花费加上今天的价格
    }

    return dp[n - 1]; // 返回最后一天的总花费
}

int main() {
    cout << solution(5, 2, {1, 2, 3, 3, 2}) << endl; // 输出：9
    cout << solution(6, 3, {4, 1, 5, 2, 1, 3}) << endl; // 输出：9
    cout << solution(4, 1, {3, 2, 4, 1}) << endl; // 输出：10
    cout << solution(13, 6, {6, 19, 19, 3, 3, 25, 16, 17, 8, 1, 5, 21, 2}) << endl; // 输出：40

    return 0;
}