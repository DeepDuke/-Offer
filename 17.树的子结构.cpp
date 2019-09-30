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
    bool isSubtree(TreeNode* parent, TreeNode* child){
        // judge if child tree is a subtree of parent tree, then have same root node
        if(child == nullptr) return true; // attention
        if(parent == nullptr) return false;
        
        if(parent->val != child->val) return false;
        else{
            return isSubtree(parent->left, child->left) && isSubtree(parent->right, child->right);
        }
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
        bool result = false;
        if(pRoot1->val == pRoot2->val){ // pRoot1中可能有多个节点和pRoot2的val相同
            result = isSubtree(pRoot1, pRoot2);
        }
        if(result == false){
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
};