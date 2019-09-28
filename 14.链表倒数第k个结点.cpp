/*
设置两个指针，p和q, 让q先走k-1步，然后p,q再同时走，当q到达链表末尾时，p指向的就是倒数第k个结点。
注意边界条件
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k == 0 || pListHead == nullptr) return nullptr;
        ListNode* p = pListHead;
        ListNode* q = pListHead;
        for(int i = 0; i < k-1; i++){
            if(q->next != nullptr)
                q = q->next;
            else
                return nullptr;
        }
        while(q->next != nullptr){
            q = q->next;
            p = p->next;
        }
        return p;
    }
};