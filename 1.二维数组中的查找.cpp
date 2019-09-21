/*
从右上角开始，如果当前值比target小，则往下边找（增大的方向）；当前值比target大则往左边找（减小的方向）。当前点有种二分点的感觉。
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int i = 0, j = col - 1;
        while(i >= 0 && i < row && j >= 0 && j < col){
            if(array[i][j] < target){
                i++;
            }else if(array[i][j] > target){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};