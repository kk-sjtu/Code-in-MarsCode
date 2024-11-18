#include <string>
#include <iostream>
using namespace std;

std::string solution(const std::string& s) {
    string res;
    size_t firstNonZero = s.find_first_not_of('0');
    
    
    // 从第一个非'0'字符开始截取子字符串
    std::string s11 = s.substr(firstNonZero);
    cout<<s11<<endl;
    string s1;
    string s2;
    for(int i=0;i<s11.length();i++){
        if(s11[i]=='.'){
            s1 = s11.substr(0, i);
            s2 = s11.substr(i,s11.length());
            cout<<"s1"<<s1<<endl;
            cout<<"s2"<<s2<<endl;


            break;
        }
        if(i==s11.length()-1){
            s1 = s11;
            cout<<"s1"<<s1<<endl;
            s2 = "";

        }
    }


    int len1 = s1.size(); 
    int len2 = s2.size();
    int loc = len1%3;
    if(loc==0) loc+=3;
    string new_s1 = s1.substr(0,loc);

    for(int j = loc;j<len1;){
       string temp = s1.substr(j,j+3);
        new_s1 = new_s1 + ',' + s1.substr(j,3);
        cout<<new_s1<<endl;
        j+=3;
    }

    res = new_s1+s2;

    cout<<res<<endl;
    return res;
}

int main() {
    //std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    //std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
}