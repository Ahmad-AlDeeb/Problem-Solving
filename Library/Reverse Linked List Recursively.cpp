    Node* reverse(Node* cur) {
        if(cur and cur->next) {
            Node* rem = reverse(cur->next);
            rem->next = cur;
            cur->next = nullptr;
        }
        return cur;
    }
