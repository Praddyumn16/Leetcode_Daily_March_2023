class Node {
public:
    string val;
    Node* prev;
    Node* next;

    Node(string val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class BrowserHistory {
public:
    Node* root = new Node("kuchbhi");

    BrowserHistory(string homepage) {
        root->val = homepage;
    }
    
    void visit(string url) {
        root->next = new Node(url);
        Node* temp = root;
        root = root->next;
        root->prev = temp;
    }
    
    string back(int steps) {
        while(steps--) {
            if(!root->prev)
                return root->val;
            root = root->prev;
        }
        return root->val;
    }
    
    string forward(int steps) {
        while(steps--) {
            if(!root->next)
                return root->val;
            root = root->next;
        }
        return root->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */