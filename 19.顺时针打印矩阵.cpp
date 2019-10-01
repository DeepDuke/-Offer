/*
向右，向下，向左，向上依次遍历，但是在遍历过程中要保证矩阵还有元素没遍历完，
即要求满足up<=down && left <= right。
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if(matrix.size() == 0) return result;
        int row = matrix.size(), col = matrix[0].size();
        int up = 0, down = row-1, left = 0, right = col-1;
        int totalNum = row * col;
        while(result.size() < totalNum){
            // 向右
            for(int i = left; i <= right && up <= down; i++){
                result.push_back(matrix[up][i]);
            }
            up++;
            // 向下
            for(int i = up; i <= down && right >= left; i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            // 向左
            for(int i = right; i >= left && down >= up; i--){
                result.push_back(matrix[down][i]);
            }
            down--;
            // 向上
            for(int i = down; i >= up && left <= right; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};