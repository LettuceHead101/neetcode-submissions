class DynamicArray {
public:
    vector<int> arr;
    int size;
    int capacity;
    DynamicArray(int capacity) {
        vector<int> temp(capacity);
        arr = temp;
        this->capacity = capacity;
        size = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity) {
            resize();
        }

        arr[size] = n;
        size += 1;
    }

    int popback() {
        size -= 1;
        return arr[size];
    }

    void resize() {
        // Handle the edge case where initial capacity was 0
        capacity = (capacity > 0) ? capacity * 2 : 1;
        
        vector<int> temp(capacity);
        for (int i = 0; i < size; i++) { // Only copy up to 'size', not 'capacity/2'
            temp[i] = arr[i];
        }
        arr = temp;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
