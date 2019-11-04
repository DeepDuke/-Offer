/*
先复制除了random以外的信息，用一个map记录新旧链表的对应关系，
复制完整条链表后依据map来复制random信息。
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *newHead = copyNext(pHead);
        copyRandom(newHead, pHead);
        return newHead;
    }
private:
    map<RandomListNode*, RandomListNode*> record;
    RandomListNode* copyNext(RandomListNode* pHead){
        if(!pHead) return nullptr;
        RandomListNode* newHead = new RandomListNode(pHead->label);
        newHead->next = copyNext(pHead->next);
        record[pHead] = newHead;
        return newHead;
    }
    void copyRandom(RandomListNode* newHead, RandomListNode* pHead){
        if(!pHead) return;
        newHead->random = record[pHead->random];
        copyRandom(newHead->next, pHead->next);
    }
};