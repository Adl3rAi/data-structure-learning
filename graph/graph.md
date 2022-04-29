# Graph

```cpp
struct Edge
{
 	int startVertex;
  int endVertex;
  int weight; // a weighted graph
};
string vertex_list[MAX_SIZE];
Edge edge_list[MAX_SIZE];
```

## Graph representation

```cpp
int *A[8];
A[0] = new int[3];
A[1] = new int[3];
A[2] = new int[2];
...
A[7] = new int[4];
```



```cpp
struct Node {
  int data;
  int weight;
 	Node* next;
};
Node *A[8];
```

---

## Dynamic memory

```cpp
int * foo;
foo = new int [5];
```

The system dynamically allocates space for five elements of type `int` and `return`s a pointer to the first element of the sequence. Therefore, `foo` now points to a valid block of memory with space for five elements of type `int`

`foo` is a pointer, the no.n element pointed by `foo` can be accessed either with the `foo[n]` or the expression `*(foo+n)`

```cpp
delete foo;
delete[] foo;
```

