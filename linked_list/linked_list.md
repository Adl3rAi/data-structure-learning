# Linked List

- [Linked List](#linked-list)
  - [Define a Linked List](#define-a-linked-list)
  - [Print a Linked List](#print-a-linked-list)
  - [Insert at the begin](#insert-at-the-begin)
  - [Insert at the end](#insert-at-the-end)
  - [Insert at any position](#insert-at-any-position)
  - [Delete element at any position](#delete-element-at-any-position)
  - [Reverse the linked list](#reverse-the-linked-list)
  - [Reverse print the linked list](#reverse_print_the_linked_list)

---

## Define a Linked List

```cpp
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

```cpp
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

## Reverse Print the linked list

`reversePrint()` won't change the orders of the elements in the linked list

[Source code for reverse print](https://github.com/Adl3rAi/data-structure-learning/blob/main/linked_list/reverse_print.cpp)

```cpp
void reversePrint() {
  Node* temp = head;
  if(temp != NULL) {
    if(temp->next != NULL) {
      reversePrint(temp->next);
    }
    cout << temp->data << " ";
  }
}
```
