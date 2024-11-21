// version 1
// 暴力！
#include <vector>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution(std::vector<int> values) {
    // write code here
    vector<int> temp(values.size(),0);
   // vector<int> res;
    int ans=0;
    for(int i=0;i<values.size();i++){
        for(int j=0;j<values.size();j++){
            if(i!=j){
                temp[i] = max( temp[i],values[j] + values[i]-abs(i-j) );
        }
        ans = max(ans,temp[i]);
    }

    }
    return ans; // Placeholder return
}

int main() {
    std::cout << (solution({8, 3, 5, 5, 6}) == 11) << std::endl;
    std::cout << (solution({10, 4, 8, 7}) == 16) << std::endl;
    std::cout << (solution({1, 2, 3, 4, 5}) == 8) << std::endl;
    return 0;
}

// version2

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(std::vector<int> values) {
    int max_i = values[0] + 0; // 初始化 max_i
    int max_score = 0; // 初始化最大得分

    for (int j = 1; j < values.size(); ++j) {
        // 计算当前的得分
        int current_score = max_i + values[j] - j;
        // 更新最大得分
        max_score = max(max_score, current_score);
        // 更新 max_i
        max_i = max(max_i, values[j] + j);
    }

    return max_score;
}

int main() {
    std::cout << (solution({8, 3, 5, 5, 6}) == 11) << std::endl;
    std::cout << (solution({10, 4, 8, 7}) == 16) << std::endl;
    std::cout << (solution({1, 2, 3, 4, 5}) == 8) << std::endl;
    return 0;
}