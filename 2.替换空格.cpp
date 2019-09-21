/*
在字符原数组上进行操作。计算出有多少个空格和新字符串的长度。使用two pointers的方法，从后向前复制，遇到空格则替换为"%20"。
当两个pointer相遇时所有空格已经替换完。
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int originalLength = 0; // exclude '\0'
        int numOfBlank = 0;
        int i = 0;
        while(str[i] != '\0'){
            originalLength++;
            if(str[i] == ' ')
                numOfBlank++;
            i++;
        }
        int newLength = originalLength + 2*numOfBlank;
        int q = newLength, p = originalLength; // start from '\0'
        while(p < q){
            if(str[p] != ' '){
                str[q--] = str[p--];
            }else{
                str[q--] = '0';
                str[q--] = '2';
                str[q--] = '%';
                p--;
            }
        }
	}
};