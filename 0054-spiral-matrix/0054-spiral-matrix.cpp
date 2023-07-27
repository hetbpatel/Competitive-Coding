// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> ans;
        int count=0;
        int total=row*col;
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        while(count<total){
            //print the starting row here
            for(int index=startingCol;count<total && index<=endingCol;index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            //print the ending col
            for(int index=startingRow;count<total && index<=endingRow;index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            //now for ending row
            for(int index=endingCol;count<total && index>=startingCol;index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            //to print starting col
            for(int index=endingRow;count<total && index>=startingRow;index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};

/*--------------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int R = matrix.size();
        int C = matrix[0].size();

        vector<int>ans;
        int r=0,c=0,dis=0;
        bool vis[R][C];

        memset(vis,false,sizeof(vis));

        for(int i=0;i<R*C;i++)
        {
            ans.push_back(matrix[r][c]);
            vis[r][c] = true;

            int x = r + dx[dis];
            int y = c + dy[dis];

            if(x>=0 and y>=0 and x<R and y<C and !vis[x][y])
            {
                r = x;
                c = y;
            }

            else
            {
                dis = (dis+1)%4;
                r = r + dx[dis];
                c = c + dy[dis];
            }
        }

        return ans;
    }
};
