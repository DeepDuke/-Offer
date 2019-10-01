/*
用一个vector来模拟栈，再用一个来保存前n个入栈元素中最小的那个，空间复杂度O(n),时间复杂度O(1)
*/
class Solution {
public:
    void push(int value) {
        st.push_back(value);
        if(st.size() == 1){ 
            minVec.push_back(value);
        }else{
            minVec.push_back(value < minVec.back()? value:minVec.back());
        }
    }
    void pop() {
        st.pop_back();
        minVec.pop_back();
    }
    int top() {
        return st.back();
    }
    int min() {
        return minVec.back();
    }
private:
    vector<int> st, minVec;
};