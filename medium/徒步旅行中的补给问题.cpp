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


