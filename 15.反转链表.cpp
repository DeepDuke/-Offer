/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*
解法1:遍历链表以一个栈暂存，然后重建链表。
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return pHead;
        stack<ListNode*> st;
        while(pHead != nullptr){
            st.push(pHead);
            pHead = pHead->next;
        }
        ListNode* head = st.top();
        ListNode* temp = st.top();
        st.pop();
        while(!st.empty()){
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
};
/*解法2
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return pHead;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while(pHead != nullptr){
            next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};
