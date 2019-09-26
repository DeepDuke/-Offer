/*
f(n) = f(1) + f(2) + f(3) + ... + f(n-1) ==> f(n) = 2^(n-1), 边界：f(1) = 0
*/
class Solution {
public:
    int compute(int n){
        // compute 2^n
        if(n == 0) return 1;
        if(n%2 == 0){
            int half = compute(n/2);
            return half*half;
        }else{
            return 2*compute(n-1);
        }
    }
    int jumpFloorII(int number) {
        // compute 2^(number-1)
        return compute(number-1);
    }
};