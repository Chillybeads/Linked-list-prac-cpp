# Linked List in C++

A templated singly linked list in C++, built from a `Node<T>` class and an `LLWrapper<T>` class that manages the list head. Practical 5, COS 110.

## Project structure

| File | Purpose |
|------|---------|
| `Node.h` | `Node<T>` class: a single list node with insert, remove, search, print, size and list deletion |
| `LLWrapper.h` | `LLWrapper<T>` class: wraps the head pointer and exposes a safe interface to the list |

## Features

- Generic: works with any type `T`
- Insert a value or splice in another list
- Remove a value
- Search for a value (returns a wrapper around the matching node)
- Print the list and get its size
- Peek at the head value
- Frees all nodes when the wrapper is destroyed

## Usage

```cpp
#include "LLWrapper.h"

int main() {
    LLWrapper<int> list;
    list.insert(3);
    list.insert(7);
    list.print();
    list.remove(3);
    return 0;
}
```

## Build

```bash
g++ -std=c++98 main.cpp -o prac
./prac
```

