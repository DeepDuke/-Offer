/*
快速幂：要考虑base为0和是负数的情况
*/
class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0) return 0;
        if(exponent == 0) return 1;
        if(exponent < 0) {
            base = 1.0/base;
            exponent = -exponent;
        }
        if(exponent&1){
            return base*Power(base, exponent-1);
        }else{
            double half = Power(base, exponent/2);
            return half*half;
        }
    }
};