/*
解法1：
BST从小到大排序就是其中序遍历序列，利用中序和后序重建BST，若能重建，则是BST的后序遍历序列。
*/
class Solution {
public:
    bool build(vector<int> in, int inL, int inR, vector<int> post, int postL, int postR){
        int inSize = inR - inL, postSize = postR - postL;
        if(inSize != postSize) return false;
        
        int root = post[postR];
        int i = inL;
        for(; i <= inR;  i++){
            if(in[i] == root) break;
        }
        if(i > inR) return false;
        int numLeft = i-inL;
       
        if(numLeft > 0){
            bool buildLeft = build(in, inL, i-1, post, postL, postL+numLeft-1);
            if(buildLeft == false) return false;
        }
       
        if(i < inR){ // exist right subtree
            bool buildRight = build(in, i+1, inR, post, postL+numLeft, postR-1);
            if(buildRight == false) return false;
        }
        return true;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        vector<int> post = sequence;
        sort(sequence.begin(), sequence.end());
        return build(sequence, 0, sequence.size()-1, post, 0, post.size()-1);
    }
};
/*
根据BST的定义，递归判断，后序遍历序列 = [左子树结点，右子树结点，根结点]
递归判断左子树的结点是不是都比根结点小，右子树的结点是不是都比根结点大。
*/
class Solution2 {
public:
   bool judge(vector<int> sequence, int L, int R){
        if(L >= R) return true;
        int i = L;
        for(; i < R; i++){
            if(sequence[i] > sequence[R]) break;
    
        }
        for(int j = i; j < R; j++){
            if(sequence[j] <= sequence[R])
                return false;
        }
        return judge(sequence, L, i-1) && judge(sequence, i, R-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(!sequence.size()) return false;
        return judge(sequence, 0, sequence.size());
    }
};