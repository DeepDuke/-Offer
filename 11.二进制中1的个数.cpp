/*
解法1：
basic knowledge： 一个整数N和1做位运算与，可以判断N的二进制形式中末尾一位是1还是0。
如果题目输入的n是正整数，可以通过不停地把n右移一位，逐位&1来判断每一位是不是1。
考虑到n可能是负整数，因此此法不通，但是可以把1不停地左移一位来与n做位运算与，
这样就可以判断n的二进制形式中有多少个1，时间复杂度为O(k), k为n的二进制形式中的位数。
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         int flag = 1;
         while(flag != 0){
             if(n&flag){ // odd
                 cnt++;
             }
             flag = flag << 1;
         }
         return cnt;
     }
};
/*
解法2：
考虑到只要n!=0，则比如1100，其中至少有一个1，令1100-1得到1011，
1100 & 1011 ==> 1000 > 0 ==> 二进制数中至少有两个1 ==> 1000 & 0000 ==> 0000,
故而1100中有两个1。当n为负整数时，也满足，比如4位补码的情况下，-6的补码是1010(最高位1是符号位)：
1010(-6)&1001 ==> 1000 & 0111 ==> 0000, 故1010中有两个1。
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while(n != 0){
             cnt++;
             n = n & (n-1);
         }
         return cnt;
     }
};
/*
解法3：其实n为负整数时若不确定能不能用n&(n-1)的方法，可以这么干：把n转成unsigned int，这样就和正整数一样的操作了，
unsigned int和int二进制一样，只是解读方式不同
*/
class Solution {
public:
     int  NumberOf1(int n) {
         unsigned a = n;
         int cnt = 0;
         while(a != 0){
             cnt++;
             a = a & (a-1);
         }
         return cnt;
     }
};
