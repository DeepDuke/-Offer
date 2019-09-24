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

/********************** 更快的非递归版本 ***************************************/
class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        int a = 0, b = 1;
        for(int i = 2; i <= n; i++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};