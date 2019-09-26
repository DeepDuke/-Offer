/*
2*n（2行n列)的矩形用2*1的小矩形填充，小矩形横着放，每次必须放两块，竖着放，一次则可以只放一块。
等价于每次跳一个台阶或者两个台阶，跳完n个台阶有几种跳法。本质还是斐波那契数列。
*/
class Solution {
public:
    int rectCover(int number) {
        if(number == 0 || number == 1 || number == 2) return number;
        int a = 1, b = 2;
        for(int i = 3; i <= number; i++){
            b += a;
            a = b - a;
        }
        return b;
    }
};