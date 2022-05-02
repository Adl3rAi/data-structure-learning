## Define a binary heap

```cpp
class MinHeap
{
  int *harr;
  int capacity;
  int heap_size;
public:
  // Constructor
  MinHeap(int capacity);
  
  // to heapify a subtree with the root at given index
  void MinHeapify(int );
  
  int parent(int i) {return (i-1)/2;}
  int left(int i) {return (2*i + 1);}
  int right(int i) {return (2*i + 2);}
  
  // to extract the root which is the minimum element
  int extractMin();
  
  void decreaseKey(int i, int new_val);
  
  int getMin() {return harr[0]};
  
  void deleteKey(int i);
  
  void insertKey(int k);
};
```

## Insert an elment

```cpp
void MinHeap::insertKey(int k)
{
  if(heap_size == capacity) {
    cout << "Overflow";
    return;
  }
  heap_size++;
  int i = heap_size - 1;
  harr[i] = k;
  while(i != 0 && harr[parent(i)]>harr[i]) {
    swap(&harr[parent(i)], &harr[i]);
    i = parent(i);
  }
}
```

## Decrease a Key

```cpp
void MinHeap::decreaseKey(int i, int new_val)
{
  harr[i] = new_val;
  while(i != 0 && harr[parent(i)] > harr[i]) {
    swap(&harr[parent(i)],&harr[i]);
    i = parent(i);
  }
}
```

## Extract the minimum

```cpp
int MinHeap::extractMin()
{
	if(heap_size <= 0) return -1;
  if(heap_size == 1) {
    heap_size--;
    return harr[0];
  }
  int root = harr[0];
  harr[0] = harr[heap_size-1];
  heap_size--;
  MinHeapify(0);
  return root;
}
```

## Delete an element

```cpp
void deleteKey(int i) {
  decreaseKey(i,-1);
  extractMin();
}
```


## Heapify a subtree

```cpp
void MinHeap::MinHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if(l < heap_size && harr[l] > harr[i]) {
  	smallest = l;
  }
  if(r < heap_size && harr[r] > harr[smallest]) {
    smallest = r;
  }
  if(smallest != i) {
    swap(&harr[i], &harr[parent(smallest)]);
    MinHeapify(smallest);
  }
}
```

