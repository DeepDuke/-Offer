/*
注意类中vector的初始化方法
*/
class Solution {
public:
    //int table[40] = {0};
    vector<int> table = vector<int>(40, 0);
    int Fibonacci(int n) {
        if(n <= 0) return table[n];
        if(n == 1 || n==2 ) {
            table[n] = 1;
            return table[n];
        }
        table[n] = Fibonacci(n-1) + Fibonacci(n-2);
        return table[n];
    }
};