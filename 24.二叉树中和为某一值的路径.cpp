/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        dfs(root, expectNumber);
        return result;
    }
private:
    vector<vector<int> > result;
    vector<int> tmp;
    
    void dfs(TreeNode* node, int expectNumber){
        if(!node) return;
        tmp.push_back(node->val);
        if(expectNumber - node->val == 0 && !node->left && !node->right){
            result.push_back(tmp);
        }else{
            dfs(node->left, expectNumber - node->val);
            dfs(node->right, expectNumber - node->val);
        }
        tmp.pop_back();
    }
};