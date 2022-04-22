# Linked List

>Abstract Data Type(ADT)
>
>* `print()`
>
>* `getLen()`
>
>* `insertAtBegin()`, `insert()`, `insertAtEnd()`
>* `delete()`
>* `reverse()`

---

## Define a Linked List

```c++
struct Node {
  int data;
  Node* next;
};
```

## Print a Linked List

```cpp
void Print() {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
```

## Insert at the begin

```c++
void insertAtBegin(int data) {
  Node* temp = new Node();
  temp->data = data;
  if(head != NULL) {
    temp->next = head;
  }
  head = temp;
}
```

## Insert at the end

```cpp
void insertAtEnd(int data) {
  Node* temp = head;
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->next = NULL;
  if(temp == NULL) {
    head = temp1;
    return;
  }
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = temp1;
}
```

## Insert at any position

```cpp
void insertAt(int data, int pos) {
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->next = NULL;
  if(pos == 0) {
    temp1->next = head;
    head = temp1;
    return;
  }
  Node* temp2 = head;
  for(int i = 0; i <= pos - 2; i++) {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}
```

## Delete element at any position

```cpp
void Delete(int pos) {
    Node* temp1 = head;
    if(pos == 0) {
        head = temp1->next;
        delete(temp1);
        return;
    }
    Node* temp2 = temp1->next;
    for(int i = 0; i <= pos-2; i++) {
        temp1 = temp1->next;
    }
    temp1->next = temp2->next;
    delete(temp2);
}
```

## Reverse the linked list

```cpp
void Reverse() {
  Node* prev = NULL;
  Node* current = head;
  while(current != NULL) {
    Node* next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
```

