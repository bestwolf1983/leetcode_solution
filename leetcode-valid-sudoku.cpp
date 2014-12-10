#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        //row check
        for(int i = 0; i < 9; i++){
            vector<int> tmp(9, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(tmp[board[i][j] - '1'] == 0)
                    tmp[board[i][j] - '1'] = 1;
                else return false;
            }
        }
        //column check
        for(int i = 0; i < 9; i++){
            vector<int> tmp(9, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(tmp[board[j][i] - '1'] == 0)
                    tmp[board[j][i] - '1'] = 1;
                else return false;
            }
        }
        //sub board check
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                vector<int> tmp(9, 0);
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[i + k][j + l] == '.') continue;
                        if(tmp[board[i + k][j + l] - '1'] == 0)
                            tmp[board[i + k][j + l] - '1'] = 1;
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};


bool Test(){
    vector<vector<char> > board(9, vector<char>(9, 0));
    board[0][0] = '.';
    board[0][1] = '8';
    board[0][2] = '7';
    board[0][3] = '5';
    board[0][4] = '4';
    board[0][5] = '3';
    board[0][0] = '2';
    board[0][0] = '1';
    board[1][0] = '2';
    board[2][0] = '3';
    board[3][0] = '4';
    board[4][0] = '5';
    board[5][0] = '6';
    board[6][0] = '7';
    board[7][0] = '8';
    board[8][0] = '9';
    Solution s;

    if(s.isValidSudoku(board))
        cout << "yes" << endl;
    else 
        cout << "no" << endl;
}

int main(){
    Test();
    return 0;
}
