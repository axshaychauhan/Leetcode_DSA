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
       if(!head) return nullptr;
       
        for (Node* curr = head; curr; curr = curr->next->next) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
        }

        for (Node* curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
  
        }

        Node* newHead = head->next;
        for (Node* curr = head; curr; curr =curr->next) {
            Node* copy = curr->next;
            curr->next = copy->next;
            copy->next = curr->next? curr->next->next: nullptr;
        }

        return newHead;
    }
};