#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

std::unordered_map<int, int> countOccurrences(const std::vector<int>& array) {
    std::unordered_map<int, int> countMap;
    // 遍历数组中的每个元素
    for (int num : array) {
        // 如果元素已经在哈希表中，增加其计数
        if (countMap.find(num) != countMap.end()) {
            countMap[num]++;
        } else {
            // 如果元素不在哈希表中，将其插入并初始化计数为1
            countMap[num] = 1;
        }
    }
    
    return countMap;
}

std::vector<int> findKeysWithCountGreaterThanThree(const std::unordered_map<int, int>& countMap) {
    std::vector<int> result;
    
    // 遍历哈希表中的每个键值对
    for (const auto& pair : countMap) {
        // 检查value是否大于3
        if (pair.second >= 3) {
            // 如果value大于3，将key添加到结果容器中
            result.push_back(pair.first);
        }
    }
    
    return result;
}

std::vector<int> findKeysWithCountTwo(const std::unordered_map<int, int>& countMap) {
    std::vector<int> result;
    
    // 遍历哈希表中的每个键值对
    for (const auto& pair : countMap) {
        // 检查value是否大于3
        if (pair.second >= 2) {
            // 如果value大于3，将key添加到结果容器中
            result.push_back(pair.first);
        }
    }
    return result;
}

std::vector<int> solution(int n, int max, const std::vector<int>& array) {
    // Edit your code here
    std::unordered_map<int, int> result = countOccurrences(array);
    vector<int>vec3 = findKeysWithCountGreaterThanThree(result);
    vector<int>vec2 = findKeysWithCountTwo(result);
    std::sort(vec3.begin(), vec3.end(), greater<int>());
    std::sort(vec2.begin(), vec2.end(), greater<int>());

    if(vec3.empty()){return {0, 0};}
    if(!vec2.empty()){

    for (int a : vec3) {
        for (int b : vec2) {
            if( vec3.back()==1 && ( 3 * 1 + 2 * b <= max) ){
                if(b!=1) return {1, b};
            }
            if( vec3.back()==1 && ( 3 * 1 + 2 * a <= max) ){
                if(a!=1 ) return {1, a};
            }

            if(vec2.back()==1 && ( 3 * a + 2 * 1 <= max) && a!=1){return {a, 1};}

            cout<<a<<" "<<b<<endl;
            cout<<3*a + 2 * b<<endl;
            cout<<"走到这里了吗？"<<endl;

            if(vec2.back()!=1 && 3*a + 2*b <= max && a!=b) {
                cout<<"为什么不跳出？"<<endl;
                return {a, b};
            }

        }
    }
    }



    
    
    // 输出结果
    /*
    for (const auto& pair : result) {
        std::cout << "Number: " << pair.first << ", Count: " << pair.second << std::endl;
    }
    for (int num : vec3) {
        std::cout << "num3: "<< num << " ";
    }
    for (int num : vec2) {
        std::cout << "num2: "<<num << " ";
    }
    */

    return {0, 0};
}



int main() {
    // Add your test cases here
    
    std::vector<int> result1 = solution(31, 42,{3,3,11,12,12,2,13,5,13,1,13,8,8,1,8,13,12,9,2,11,3,5,8,11,1,11,1,5,4,2,5});
    std::cout << (result1 == std::vector<int>{8, 5}) << std::endl;

    //std::vector<int> result2 = solution(9, 37, {9, 9, 9, 9, 6, 6, 6, 6, 13});
    //std::cout << (result2 == std::vector<int>{6, 9}) << std::endl;

    //std::vector<int> result3 = solution(9, 40, {1, 11, 13, 12, 7, 8, 11, 5, 6});
    //std::cout << (result3 == std::vector<int>{0, 0}) << std::endl;

    return 0;
}
