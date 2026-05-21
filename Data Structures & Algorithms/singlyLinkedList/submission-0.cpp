class ListNode {
    public: 
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
public:

    ListNode* head;
    ListNode* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        ListNode* current = head;
        int i = 0;
        while(current != nullptr) {
            if(i == index) {
                return current->val;
            }
            i++;
            current = current->next;
        }

        return -1;
    }

    void insertHead(int val) {
        ListNode* newhead = new ListNode(val);
        newhead->next = head;
        head = newhead;
        if(tail == nullptr)  {
            tail = head;
        }
    }
    
    void insertTail(int val) {
        ListNode* newtail = new ListNode(val);
        if(tail == nullptr) {
            head = newtail;
            tail = newtail;
            return;
        }
        tail->next = newtail;
        tail = newtail;
    }

    bool remove(int index) {
        if(head == nullptr || index < 0) return false;

        if(index == 0) {
            ListNode* temp = head;
            head = head->next;
            if(head == nullptr) tail = nullptr;
            delete temp;
            return true;
        }

        int i = 0;
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr) {
            if (i + 1 == index) {
                ListNode* nodeToDelete = curr->next;
                curr->next = nodeToDelete->next;
                
                // If we deleted the tail, update the tail pointer
                if (curr->next == nullptr) {
                    tail = curr;
                }
                
                delete nodeToDelete; // Free the memory!
                return true;
            }
            i++;
            curr = curr->next;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> values;
        ListNode* current = head;
        while(current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }
        return values;
    }
};
