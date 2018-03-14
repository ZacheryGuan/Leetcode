/*
https://leetcodechina.com/explore/suan-fa/card/chu-ji-suan-fa/1/di-yi-zhang-jie/30/
*/

class Solution {
public:
    bool isPartValid(vector<char>& line){
        vector<char> a(9, 0);
        vector<char>::iterator it;
        
        for(int i=0; i<9; i++){
            a[i]='1'+i;
        }
        
        for(int i=0; i<9; i++){
            if(line[i] == '.')
                continue;
            it = find(a.begin(), a.end(), line[i]);
            if(it!=a.end())
                a.erase(it);
            else
                return false;
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        //line
        for(int i = 0; i<9; i++){
            if(!isPartValid(board[i]))
                return false;
        }
        
        //column
        for(int i = 0; i<9; i++){
            vector<char> column(9, 0);
            
            for(int j = 0; j<9; j++)
                column[j] = board[j][i];
            
            if(!isPartValid(column))
                return false;
        }
        
        //block
        for(int i = 0; i<7; i += 3){
            for(int j = 0; j<7; j +=3){
                vector<char> block(9, 0);
                
                for(int k = 0; k<9; k++){
                    block[k] = board[i+k/3][j+k%3];
                    // cout<<i+k/3<<", "<<j+k%3<<" ";
                    // cout<<block[k];
                }
                // cout<<endl;
                if(!isPartValid(block))
                    return false;
            }
        }
        
        return true;
    }
};