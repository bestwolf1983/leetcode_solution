#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    string multipy(string num1, string num2){
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> tmp(len1 * len2 + 1, 0);
        int total = 0;
        int i = 0; int j = 0;
        for(; i  < len1; i++){
            int jinwei = 0;
            int v1 = num1[len1 - 1 - i] - '0';
            //if(v1 == 0) continue;
            j = 0;
            for(; j < len2; j++){
                int r = v1 * (num2[len2 - 1 - j] - '0') + jinwei + tmp[i + j];
                jinwei = r / 10;
                tmp[i + j] = r % 10;
            }
            while(jinwei > 0){
                int old = tmp[i + j];
                tmp[i + j] = (old + jinwei) % 10;
                jinwei = (old + jinwei) / 10;
                j++;
            }
        }
        total = i - 1 + j;
        if(tmp[total - 1] == 0) return "0";
        string result(total, '0');
        for(int k = 0; k < total; k++){
            result[k] = tmp[total -1 - k] + '0';
        }
        return result;
    }
};

int main(){
    Solution s;
    string string1 = "9133";
    string string2 = "0";
    string string3 = s.multipy(string1, string2);
    cout << string3 << endl;
}
