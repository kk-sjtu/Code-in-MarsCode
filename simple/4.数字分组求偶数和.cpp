// step 1
// 将输入数组的每一个元素的每一位数分别提取出来，然后统计每个元素的奇数位和偶数位的个数，最后返回奇数位的个数和偶数位的个数之和。

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    // Please write your code here

    int len = numbers.size();
    vector<int> even;
    vector<int> odd;
    // if len is even number, candidate must be even th odd , eventh even

    // every item in vector , % % %
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        int num = *it;
        even[ it-numbers.begin() ] = 0;
        odd[it-numbers.begin()]=0;
        while(num){
            even[ it-numbers.begin() ] += (num%10+1)%2; 
            odd[it-numbers.begin()] += (num%10)%2;
            num = num/10;
        }

    }
    for(int i=0;i<len;i++){
            cout<<"even:"<<even[i]<<",";

    }
    for(int i=0;i<len;i++){
            cout<<"odd:"<<odd[i]<<",";
    }

    return 1;
}

int main() {
    // You can add more test cases here
    std::cout << (solution({123, 456, 789}) == 14) << std::endl;
    std::cout << (solution({123456789}) == 4) << std::endl;
    std::cout << (solution({14329, 7568}) == 10) << std::endl;
    return 0;
}

// step 2
// 加入了动态规划

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
    int len = numbers.size();
    vector<int> even(len, 0); // 每个数字组中的偶数数量
    vector<int> odd(len, 0);  // 每个数字组中的奇数数量
    for (int i = 0; i < len; ++i) {
        int num = numbers[i];
        while (num) {
            int digit = num % 10;
            if (digit % 2 == 0) {
                even[i] += 1; // 偶数位
            } else {
                odd[i] += 1;  // 奇数位
            }
            num /= 10;
        }
    }

    // 动态规划数组，dp[0]表示当前选择的数字之和为偶数的方法数，dp[1]表示当前选择的数字之和为奇数的方法数
    vector<int> dp(2, 0);
    dp[0] = 1; // 初始状态，选择0个数字，和为偶数的方法数为1

    // 遍历每个数字组，更新动态规划数组
    for (int i = 0; i < len; ++i) {
        vector<int> new_dp(2, 0);
        new_dp[0] = dp[0] * even[i] + dp[1] * odd[i];
        new_dp[1] = dp[0] * odd[i] + dp[1] * even[i];
        dp = new_dp;
    }
    cout<<dp[0]<<"  "<<dp[1]<<endl;
    return dp[0]; // 返回使得新数的各位数字之和为偶数的方法数
}


int main() {
    // You can add more test cases here
    std::cout << (solution({123, 456, 789}) == 14) << std::endl;
    std::cout << (solution({123456789}) == 4) << std::endl;
    std::cout << (solution({14329, 7568}) == 10) << std::endl;
    return 0;
}