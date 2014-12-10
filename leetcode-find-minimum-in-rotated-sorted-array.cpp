#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0;
        int high = num.size() - 1;
        if(num[low] < num[high])
            return num[low];

        while(low < high - 1){
            int mid = low + (high - low) / 2; 
            while(mid < high && num[mid] == num[low]){
                mid++;
                low++;
            }
            if(mid == high){
                break;
            }
            if(num[mid] > num[low]){
                low = mid;
            }
            else {
                while(mid > low && num[mid] == num[high]){
                    mid--;
                    high--;
                }
                if(mid == low){
                    break;
                }
                if(num[mid] < num[high]){
                    high = mid;
                }
            }
        }
        return num[high];
    }
};

int main(){
    Solution s;
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(2);
    A.push_back(2);
    A.push_back(0);
    A.push_back(0);
    cout << s.findMin(A) <<endl;
}
