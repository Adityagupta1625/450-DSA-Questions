// Soduko Solver

// Probelm Link: https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    void empty(vector<vector<char>>& board,int& row,int& col){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    break;
                }
            }
        }
    }
     bool isValid(vector<vector<char>>& board,int row,int col,char val){
        for(int i=0;i<9;i++){
            if(board[row][i]==val)
                return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==val)
                return false;
        }
         
        int r=row-(row%3);
        int c=col-(col%3);
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(board[i][j]==val)
                    return false;
            }
        }
        
        return true;
    }
    bool helper(vector<vector<char>>& board){
        int r=-1;
        int c=-1;
        empty(board,r,c);
        if(r==-1 && c==-1)
            return true;
        
        
        for(char k='1';k<='9';k++){
            if(isValid(board,r,c,k)){
                board[r][c]=k;
                if(helper(board)==true){
                    return true;
                }
                else{
                    board[r][c]='.';
                }
            }
            
        }
        return false;
    }
   
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);  
    }
};