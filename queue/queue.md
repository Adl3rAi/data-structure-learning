## Define a queue

Queue is a LIFO data structure

- [Define a queue](#define-a-queue)
- [Enqueue()](#enqueue)
- [Dequeue()](#dequeue)

## Enqueue()

```cpp
void Enqueue(int x) {
  Node* temp = new Node();
  temp->data = x;
  temp->next = NULL;
  if(front == NULL && rear == NULL) {
    front = temp;
    rear = temp;
    return
  }
  rear->next = temp;
  rear = temp;
}
```

## Dequeue()

```cpp
void Dequeue() {
  if(front == NULL) {
    return;
  }
  if(front == rear) {
    front = NULL;
    rear = NULL;
  }
  Node* temp = front;
  front = front->next;
  delete(temp);
}
```

