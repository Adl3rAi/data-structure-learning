

## Define a Stack

Stack is **Last-in-last-out(LILO)** data structure.

- [Define a Stack](#define-a-stack)
- [Push an element into the stack](#push-an-element-into-the-stack)
- [Pop an element out of the stack](#pop-an-element-out-of-the-stack)

---

C++ has STL of `stack`, which has the methods:

`push()`, `pop()`, `top()`, `empty()`

Firstly, we can struct a Stack by using linked list

## Push an element into the stack

```c++
Node* Push(Node* top, int x) {
  Node* temp = new Node();
  temp->data = x;
  if(top != NULL) {
    temp->next = top;
  }
  top = temp;
}
```

## Pop an element out of the stack

```c++
Node* Pop(Node* top) {
  Node* temp = top;
  if(top == NULL) {
    return top;
  }
  top = top->next;
  delete(temp);
  return top;
}
```

