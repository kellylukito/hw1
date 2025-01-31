/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>

//helper function print list
void printList(Node*head, const char*label){
  std::cout << label << ": ";
  while (head != NULL){
    std::cout << head->value << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

//helper function to delete list
void deleteList(Node*head){
  while (head != NULL){
    Node*temp = head;
    head = head->next;
    delete temp;
  }
}

int main(int argc, char* argv[])
{
  //test case 1: mix odd and even numbers
  Node*list1 = new Node{1,new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};
  Node*odds1 = NULL;
  Node*evens1 = NULL;

  std::cout << "Original List";
  printList(list1, "");
  split(list1, odds1, evens1);
  printList(odds1, "Odds");
  printList(evens1, "Evens");

  deleteList(odds1);
  deleteList(evens1);

  //test case 2: all even numbers
  Node*list2 = new Node{2, new Node{4, new Node{6, new Node{8, nullptr}}}};
  Node*odds2 = NULL;
  Node*evens2 = NULL;

  std::cout << "\nOriginal List";
  printList(list2, "");
  split(list2, odds2, evens2);
  printList(odds2, "Odds");
  printList(evens2, "Evens");

  deleteList(odds2);
  deleteList(evens2);

  //test case 3: empty list
  Node*list3 = NULL;
  Node*odds3 = NULL;
  Node*evens3 = NULL;

  std::cout << "\nTesting empty list:\n";
  split(list3, odds3, evens3);
  printList(odds3, "Odds");
  printList(evens3, "Evens");

  return 0;
}
