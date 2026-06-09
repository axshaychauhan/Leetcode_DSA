/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    // Phase 1: weave each copy in right after its original
    for (Node* cur = head; cur; cur = cur->next->next) {
        Node* copy = new Node(cur->val);
        copy->next = cur->next;
        cur->next = copy;
    }
    // Phase 2: set randoms (copy of X is X->next)
    for (Node* cur = head; cur; cur = cur->next->next)
        cur->next->random = cur->random ? cur->random->next : nullptr;
    // Phase 3: un-weave BOTH chains into separate lists
    Node* copyHead = head->next;
    for (Node* cur = head; cur; cur = cur->next) {
        Node* copy = cur->next;
        cur->next = copy->next;
        copy->next = cur->next ? cur->next->next : nullptr;
    }
    return copyHead;
}
};