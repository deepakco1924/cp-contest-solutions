class Solution {
public:
    bool ispossible(int i,int j,vector<vector<int>>&grid){
        int n=grid.size();
        int x=0;
        int y=0;
        while(x<n and y<n){
            if(grid[i][x]!=grid[y][j])return false;
            x++;
            y++;
        }
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ispossible(i,j,grid))cnt++;
            }
        }
        return cnt;
        
    }
};