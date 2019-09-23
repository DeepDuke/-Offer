/*
旋转数组首元素大于尾元素，且除首尾以外的中间的元素要么比首元素大，要么比尾元素小。
用二分法，若区间中间元素比L元素大，则把L右移，若区间中间元素比R小，则把R左移。
当只剩两个元素时，rotateArray[L] < rotateArray[R]则说明该数组其实并没有旋转，
否则R所指元素是数组最小值。
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0){
            return 0;
        }
        int L = 0, R = rotateArray.size()-1;
        while(L < R-1){
            int mid = (L + R) / 2;
            if(rotateArray[mid] >= rotateArray[L]){
                L = mid;
            }else if(rotateArray[mid] <= rotateArray[R]){
                R = mid;
            }
        }
        if(rotateArray[L] < rotateArray[R]){
            return rotateArray[0]; // 没有旋转
        }
        return rotateArray[R];
    }
};