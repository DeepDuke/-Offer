/*
跳台阶本质是从1，2, 3开始的斐波那契数列，证明如下：
由于每次只能跳1步或者2步，记f(n)为跳到n级台阶有多少种跳法，
则抵达n级台阶之前要么是从第n-1级台阶跳过来的，要么是从第n-2级台阶跳过来的。
故f(n) = f(n-1) + f(n-2),显然是个斐波那契数列，边界条件是f(1)=1,f(2)=2。
*/
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0) return 0;
        if(number == 1 || number == 2) return number;
        int a = 1, b = 2;
        for(int i = 3; i <= number; i++){
            b += a;
            a = b - a;
        }
        return b;
    }
};