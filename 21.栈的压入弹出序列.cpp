/*
用一个栈来不停的push进入pushV的元素，如果栈顶元素和popV的元素相同就出栈。
如果最后栈里没有元素那么，说明popV是正确的出栈序列。如果pushV的元素都进入了栈，
但栈里还有元素，说明popV不是出栈序列。
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int i = 0, j = 0;
        st.push(pushV[i]);
        while(!st.empty()){
            if(popV[j] == st.top()){
                st.pop();
                j++;
                if(st.empty() && i+1 < pushV.size()){
                    st.push(pushV[++i]);
                } 
            }else{
                if(i+1 < pushV.size()){
                    st.push(pushV[++i]);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
/*
更简洁的写法
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        for(int i = 0, j = 0; i < pushV.size(); i++){
            st.push(pushV[i]);
            while(!st.empty() && st.top() == popV[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};