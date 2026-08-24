class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
    int n,m;
    bool isPresent(vector<vector<char>>& board, string word,int i,int j,int idx){
        if(idx == word.size())return true;
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(word[idx] != board[i][j]) return false;

        char temp = board[i][j];
        board[i][j] = '#';
        for(int x = 0; x<dir.size();x++){
            int _i = i + dir[x][0];
            int _j = j + dir[x][1];
            if(isPresent(board, word, _i,_j,idx+1)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i =0; i<n; i++ ){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0] && isPresent(board, word, i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};