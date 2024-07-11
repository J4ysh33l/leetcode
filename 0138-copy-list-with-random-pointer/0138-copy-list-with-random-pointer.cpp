class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Creating a mapping from the original node to its copy
        std::unordered_map<Node*, Node*> nodeMap;
        
        // Step 1: Create all the new nodes and populate the map
        Node* curr = head;
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Step 2: Assign next and random pointers
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }
        
        // Return the head of the copied list
        return nodeMap[head];
    }
};