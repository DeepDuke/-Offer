/*
类似于归并排序合并两个有序数组
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode* root = nullptr;
        if(pHead1->val <= pHead2->val){
            root = pHead1;
            pHead1 = pHead1->next;
        }else{
            root = pHead2;
            pHead2 = pHead2->next;            
        }
        ListNode* head = root;
        while(pHead1 && pHead2){
            if(pHead1->val <= pHead2->val){
                root->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                root->next = pHead2;
                pHead2 = pHead2->next;
            }
            root = root->next;
        }
        while(pHead1){
            root->next = pHead1;
            pHead1 = pHead1->next;
            root = root->next;
        }
        while(pHead2){
            root->next = pHead2;
            pHead2 = pHead2->next;
            root = root->next;
        }
        return head;
    }
};