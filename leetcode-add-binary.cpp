#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        size_t b_len = a.length() > b.length() ? a.length() : b.length();
        vector<char> c(b_len + 1, 0);
        int jinwei = 0;
        int i = a.length() - 1, j = b.length() - 1, p = 0;
        while(i >= 0 && j >= 0){
            int r = (a[i] - '0') + (b[j] - '0') + jinwei; 
            c[p] = static_cast<char>(r % 2 + '0');
            jinwei = r / 2;
            i--; j--; p++;
        }
        while(i >= 0){
            int r = (a[i] - '0') + jinwei; 
            c[p] = static_cast<char>(r % 2 + '0');
            jinwei = r / 2;
            i--; p++;
        }
        while(j >= 0){
            int r = (b[j] - '0') + jinwei; 
            c[p] = static_cast<char>(r % 2 + '0');
            jinwei = r / 2;
            j--; p++;
        }
        if(jinwei != 0){
            //cout << "jinwei!" << p << endl;
            c[p++] = static_cast<char>(jinwei + '0'); 
        }
        string res;
        res.resize(p);
        for(int m = 0; m <= p - 1; m++){
            res[m] = c[p - 1 - m];
        }
        return res;
    }
};

int main(){
    Solution s;
    string s1 = "0";
    string s2 = "0";
    string s3 = s.addBinary(s1,s2);
    cout << s1 << "+"<< s2 << "="<< s3 << endl;
}
