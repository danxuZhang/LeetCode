class LRUCache {
    class Node {
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

    void add_node(Node* node) {
        Node* prev_tail = tail->prev;
        prev_tail->next = node;
        node->prev = prev_tail;
        node->next = tail;
        tail->prev = node;
    }

    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    unordered_map<int, Node*> mp; // map key to node
    Node* head;
    Node* tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        remove_node(node);
        add_node(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* old_node = mp[key];
            remove_node(old_node);
        } 

        Node* node = new Node(key, value);
        mp[key] = node;
        add_node(node);

        if (mp.size() > capacity) {
            Node* to_remove = head->next;
            remove_node(to_remove);
            mp.erase(to_remove->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */