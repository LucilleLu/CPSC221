//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::swapUp(int i) {
    if(is_root(i)) return;
    if(heap[i] -> getBadness() < heap[parent(i)] -> getBadness()) {
        MazeState * temp = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = temp;
        swapUp(parent(i));
    }
}

void HeapPriorityQueue::add(MazeState *elem) {
    // TODO:  Implement this!
    heap.push_back(elem);
    int size = heap.size();
    swapUp(size - 1);
}

void HeapPriorityQueue::swapDown(int i, int size) {
    if (is_leaf(i)) return;
    int s = i;
    int left = first_child(i);
    int right = left + 1;
    if(left < size && heap[left] -> getBadness() < heap[s] -> getBadness())
        s = left;
    if(right < size && heap[right] -> getBadness() < heap[s] -> getBadness())
        s = right;
    if(s != i) {
        MazeState* tmp = heap[i];
        heap[i] = heap[s];
        heap[s] = tmp;
        swapDown(s, size);
    }
}

MazeState * HeapPriorityQueue::remove() {
  assert(!is_empty());
  // TODO:  Implement this!
    MazeState *return_maze = heap[0];
    int size = heap.size();
    heap[0] = heap[size - 1];
    heap.erase(heap.begin() + heap.size() -1);
    swapDown(0, size);
    return return_maze;
}

bool HeapPriorityQueue::is_empty() {
  // TODO:  Implement this!
    return heap.size() == 0;
}

// You might find these helper functions helpful...
int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

#endif
