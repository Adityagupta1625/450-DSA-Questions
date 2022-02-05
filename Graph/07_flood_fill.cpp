// Probelm Link: https://leetcode.com/problems/flood-fill/

class Solution {
private:
    bool isSafe(int x,int y,int newcolor,int color,vector<vector<int>>& image){
        int n=image.size();
        int m=image[0].size();
        if((x>=0 && x<n) && (y>=0 && y<m) && 
           image[x][y]==color && image[x][y]!=newcolor)
                return true;
        return false;
    }
    void solve(vector<vector<int>>& image, int sr, int sc, 
        int newcolor,int c){
        if(isSafe(sr+1,sc,newcolor,c,image)){
             
             image[sr+1][sc]=newcolor;
             solve(image,sr+1,sc,newcolor,c);
        }
        
        if(isSafe(sr,sc+1,newcolor,c,image)){
            
             image[sr][sc+1]=newcolor;
             solve(image,sr,sc+1,newcolor,c);
        }
        
        if(isSafe(sr-1,sc,newcolor,c,image)){
          
             image[sr-1][sc]=newcolor;
             solve(image,sr-1,sc,newcolor,c);
        }
        
        if(isSafe(sr,sc-1,newcolor,c,image)){
            
             image[sr][sc-1]=newcolor;
             solve(image,sr,sc-1,newcolor,c);
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int c=image[sr][sc];
        
        if(c==newColor)
            return image;
        image[sr][sc]=newColor;        
        solve(image,sr,sc,newColor,c);
        return image;
    }
};