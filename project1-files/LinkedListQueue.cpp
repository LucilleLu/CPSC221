//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  // TODO:  Initialize any member variables as needed in the constructor.
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedListQueue::add(MazeState *elem)
{
  // TODO:  Implement this.
    if (head == NULL) {
        head = new node;
        head -> data = elem;
        head -> next = NULL;
        tail = head;
        size++;
    } else {
        tail -> next = new node;
        tail -> next -> data = elem;
        tail -> next -> next = NULL;
        tail = tail -> next;
        size++;
    }
}

MazeState *LinkedListQueue::remove()
{
  // TODO:  Implement this.
    assert(!is_empty());
    MazeState *return_maze = head -> data;
    node* temp = head;
    head = head -> next;
    delete temp;
    size--;
    return return_maze;
    
}

bool LinkedListQueue::is_empty()
{
  // TODO:  Implement this.
    return size == 0;
}

LinkedListQueue::~LinkedListQueue()
{
  // TODO:  Implement the destructor.  Be sure to delete everything.
    while (head != NULL) {
        node* temp = head;
        head = head -> next;
        delete temp;
    }
}

#endif

