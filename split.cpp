/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  //base case: if input list is empty
  if (in == nullptr){
    return;
  }

  //save next pointer and current Node
  Node* next = in->next;
  Node*current = in;

  //remove current node from input list
  in = next;
  current->next = nullptr;

  //current value is odd
  if(current->value % 2 ==1){
    //add to front of odds list
    current->next = odds;
    odds = current;
  }
  //current value is even
  else{
    //add to front of evens list
    current->next = evens;
    evens = current;
  }
  //recursive call the rest of the list
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
