class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<unordered_set<int>> colSets(9);
      vector<unordered_set<int>> rowSets(9);
      vector<unordered_set<int>> boxSets(9);

      for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
          if(board[i][j] == '.') {
            continue;
          }
          int n = board[i][j] - '0';

          if(colSets[j].find(n) != colSets[j].end()) {
            return false;
          }
          colSets[j].insert(n);

          if(rowSets[i].find(n) != rowSets[i].end()) {
            return false;
          }
          rowSets[i].insert(n);

          if(boxSets[(i/3)*3 + (j/3)].find(n) != boxSets[(i/3)*3 + (j/3)].end()) {
            return false;
          }
          boxSets[(i/3)*3 + (j/3)].insert(n);
        }
      }

      return true;
    }
};

