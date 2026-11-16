class Node{
public:
    Node* prev = nullptr;
    Node* next = nullptr;
    string url;
    Node(string url){
        this->url = url;
    }
};

class BrowserHistory {
private:
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* newnode = new Node(url);
        curr->next = newnode;
        newnode->prev = curr;
        curr = newnode;
    }
    
    string back(int steps) {
        while(steps--){
            if(curr->prev) curr = curr->prev;
            else break;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps--){
            if(curr->next) curr = curr->next;
            else break;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */