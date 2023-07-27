class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>s;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                  string row = "row"+to_string(i)+board[i][j];
                    string col = "col"+to_string(j)+board[i][j];
                    string box = "box"+to_string((i/3)*3+(j/3))+board[i][j];
                    
                    if(s.find(row)==s.end() && s.find(col)==s.end() && s.find(box)==s.end())
                    {
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    int n = board[i][j] - '0' - 1;
                    int k = 3*(i/3) + j/3;
                    if(row[i][n]!=0 || col[j][n]!=0 || box[k][n]!=0)    return false;
                    else    row[i][n] = col[j][n] = box[k][n] = 1;
                }
            }
        }

        return true;
    }
};
