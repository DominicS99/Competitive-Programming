/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> m;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        int val = node->val;
        if (m.count(val)) return m[val];

        Node * curr = new Node(val);
        m[val] = curr;
        for (Node * next : node->neighbors) {
            curr->neighbors.emplace_back(cloneGraph(next));
        }
        return curr;
    }
};
