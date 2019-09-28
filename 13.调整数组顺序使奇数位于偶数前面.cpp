/*
以空间换时间
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        queue<int> odd, even;
        for(const auto& num: array){
            if(num&1) odd.push(num);
            else even.push(num);
        }
        int i = 0;
        while(i< array.size()){
            while(!odd.empty()){
                array[i] = odd.front();
                odd.pop();
                i++;
            }
            while(!even.empty()){
                array[i] = even.front();
                even.pop();
                i++;
            }
        }
    }
};