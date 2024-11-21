/* version1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::string solution(int n, std::string template_, std::vector<std::string> titles) {
    // 解析模板，找出所有通配符的位置
    vector<pair<int, int>> wildcards;
    int i = 0;
    while (i < template_.size()) {
        if (template_[i] == '{') {
            int start = i;
            while (i < template_.size() && template_[i] != '}') i++;
            wildcards.push_back({start, i});
        }
        i++;
    }

    // 用于存储结果的字符串
    string result;

    // 遍历每个标题
    for (int t = 0; t < n; t++) {
        string title = titles[t];
        int ti = 0;  // 标题的指针
        int wi = 0;  // 通配符的指针
        bool match = true;

        // 遍历模板
        for (int i = 0; i < template_.size(); i++) {
            if (wi < wildcards.size() && i == wildcards[wi].first) {
                // 跳过通配符部分
                i = wildcards[wi].second;
                wi++;

                // 跳过标题中的任意字符，直到遇到下一个与模板匹配的字符
                while (ti < title.size() && title[ti] != template_[i + 1]) {
                    ti++;
                }
            } else {
                // 匹配非通配符部分
                if (ti < title.size() && template_[i] == title[ti]) {
                    ti++;
                } else {
                    match = false;
                    break;
                }
            }
        }

        // 检查标题是否完全匹配
        if (match && ti == title.size()) {
            result += "True,";
        } else {
            result += "False,";
        }
    }

    // 移除最后一个逗号
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {
    // 你可以添加更多测试用例
    std::vector<std::string> testTitles1 = {"adcdcefdfeffe", "adcdcefdfeff", "dcdcefdfeffe", "adcdcfe"};
    std::vector<std::string> testTitles2 = {"abcdefg", "abefg", "efg"};

    std::cout << (solution(4, "ad{xyz}cdc{y}f{x}e", testTitles1) == "True,False,False,True") << std::endl;
    std::cout << (solution(3, "a{bdc}efg", testTitles2) == "True,True,False") << std::endl;

    return 0;
}
*/


// version2


#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;


bool checkSubstrings(const std::vector<std::string>& substrings, const std::string& S) {
    size_t last_end = 0; // 记录上一个子串的末尾位置

    for (const auto& a : substrings) {
        size_t pos = S.find(a, last_end);
        if (pos == std::string::npos) {
            return false; // 当前子串不是 S 的子串
        }
        last_end = pos + a.size(); // 更新上一个子串的末尾位置

        if(substrings.back().back()!='}'){
            if(substrings.back().back()!=S.back()){
                return false;
            }
        }
    return true; // 所有子串都满足条件
}

vector<string> extractFixedParts(const string& template_) {
    vector<string> fixedParts;
    size_t i = 0;
    while (i < template_.size()) {
        if (template_[i] == '{') {
            // 跳过通配符部分
            while (i < template_.size() && template_[i] != '}') {
                ++i;
            }
            ++i; // 跳过右“}”
        } else {
            // 记录固定部分的起始位置
            size_t start = i;
            while (i < template_.size() && template_[i] != '{') {
                ++i;
            }
            // 提取固定部分并添加到结果向量中
            fixedParts.push_back(template_.substr(start, i - start));
        }
    }
    return fixedParts;
}

std::string solution(int n, std::string template_,
                     std::vector<std::string> titles) {

    vector<pair<int, int>> wildcards;
    int i = 0;
    while (i < template_.size()) {
        if (template_[i] == '{') {
            int start = i;
            while (i < template_.size() && template_[i] != '}') i++;
            wildcards.push_back({start, i});
        }
        i++;
    }

    vector<string> s = extractFixedParts(template_);
    vector<string> result(n, "False");
    for(int i=0;i<n;i++){
        if(checkSubstrings(s,titles[i])){
            result[i] = "True";
        }

    }

    // 用于存储结果的字符串             
  // Please write your code here
  // ans format:"True,False,False,True"
  return std::accumulate(result.begin(), result.end(), std::string(),
                         [](const std::string& a, const std::string& b) {
                           return a.empty() ? b : a + "," + b;
                         });
}

int main() {
  //  You can add more test cases here
  std::vector<std::string> testTitles1 = {"adcdcefdfeffe", "adcdcefdfeff",
                                          "dcdcefdfeffe", "adcdcfe"};
  std::vector<std::string> testTitles2 = {
      "CLSomGhcQNvFuzENTAMLCqxBdj", "CLSomNvFuXTASzENTAMLCqxBdj",
      "CLSomFuXTASzExBdj",          "CLSoQNvFuMLCqxBdj",
      "SovFuXTASzENTAMLCq",         "mGhcQNvFuXTASzENTAMLCqx"};
  std::vector<std::string> testTitles3 = {"abcdefg", "abefg", "efg"};

  std::cout << (solution(4, "ad{xyz}cdc{y}f{x}e", testTitles1) ==
                "True,False,False,True")
            << std::endl;
  std::cout << (solution(6, "{xxx}h{cQ}N{vF}u{XTA}S{NTA}MLCq{yyy}",
                         testTitles2) == "False,False,False,False,False,True")
            << std::endl;
  std::cout << (solution(3, "a{bdc}efg", testTitles3) == "True,True,False")
            << std::endl;

  return 0;
}
