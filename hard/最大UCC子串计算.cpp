#include <iostream>
#include <vector>
#include <string>
using namespace std;
// UUU  2 UCC 
// UUC  1 UCC
// UCU  1 UCC
// UCC  0
// CCC  1 UCCC
// CUU  2 CUCCU
// CUC  1 CUCC
// CCU  1 UCCU

// U 2 UCC
// C 2 UCC

// UU 2 UCC
// UC 1 UCC
// CC 1 UCC
// CU 2 UCC
int solution(int m, std::string s) {
    string te;
    int num=0;
    int sps=0;
    int len = s.size();
    int flag = len%3;
    for(int i=0;i<s.size();){
        te = s.substr(i, 3);
        if(te ==  "UUC" ||te ==  "UCU"|| te ==  "UUC" || te == "UCC" || te == "CCC" || te == "CUC" || te == "CCU" ) 
        {num++;}
        if(te == "UUU" || te == "CUU")
        {sps++;}
        
        cout<<te<<endl;
        i += 3;
        if (num>=m) return num;
    }
    if(num<m-1){
        if(sps < (m-1-num)/2) sps = sps;
        if(sps > (m-1-num)/2)sps =  (m-1-num)/2;
    }
    if(flag ==0 )return sps+num+(m-sps-num)/3;
    cout<<sps << " "<<num<<endl;
    if(flag==1 && m-num-sps >=2) return  sps+num+1+(m-1-sps-num)/3;
    return sps+num; // Placeholder
}

int main() {
    std::cout << (solution(3, "UCUUCCCCC") == 3) << std::endl;
    std::cout << (solution(6, "U") == 2) << std::endl;
    std::cout << (solution(2, "UCCUUU") == 2) << std::endl;
    return 0;
}