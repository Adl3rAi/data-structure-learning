#include <iostream>
using namespace std;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int capacity);
    int parent(int i) { return (i-1);};
    int left(int i) {return (2*i + 1);};
    int right(int i) {return (2*i + 2);};
    void MinHeapify(int i);
    void insertKey(int k);
    void decreaseKey(int i, int new_val);
    int extractMin();
    void deleteKey(int i);
};
// constructor
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
void MinHeap::insertKey(int k)
{
    if(heap_size == capacity) {
        cout << "Overflow!";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::decreaseKey(int i, int new_val)
{
   harr[i] = new_val;
   while(i != 0 && harr[parent(i)] > harr[i]) {
       swap(&harr[parent(i)], &harr[i]);
       i = parent(i);
   }
}
int MinHeap::extractMin()
{
    if(heap_size <= 0) return -1;
    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l] < harr[i]) {
        smallest = l;
    }
    if(r < heap_size && harr[r] < harr[smallest]) {
        smallest = r;
    }
    if(smallest != i) {
        swap(&harr[i],&harr[parent(smallest)]);
        MinHeapify(smallest);
    }
}
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, -1);
    extractMin();
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    // h.deleteKey(0);
    // cout << h.extractMin() << " ";
}