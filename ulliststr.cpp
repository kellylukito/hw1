#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

//add an item to back of list
void ULListStr::push_back(const std::string& val){
  //if empty list, create first item
  if(empty()){
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    head_ = tail_ = newItem;
  }
  //if tail item's array is full, create new item
  else if(tail_->last == ARRSIZE){
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;
  }
  //Add to existing tail item's array
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

//add item to front of list
void ULListStr::push_front(const std::string& val){
  //if empty list, create first item
  if(empty()){
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    head_ = tail_ = newItem;
  }

  //if no space at front of head item's array, create new item
  else if(head_->first == 0){
    Item* newItem = new Item;
    newItem->val[ARRSIZE-1] = val;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
  }
  //add to front of existing head item's Array
  else{
    head_->first--;
    head_->val[head_->first] = val;
  }
  size_++;
}

//remove last item in list
void ULListStr::pop_back(){
  if(empty()) return;

  //decrease the last index and size
  tail_->last--;
  size_--;

  //if tail item is empty, remove it
  if(tail_->first == tail_->last){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_==NULL){
      head_ = NULL; //list now empty
    }
    else{
    tail_->next = NULL;
    }
    delete temp;
  }
}

//remove first item
void ULListStr::pop_front(){
  if(empty()) return;

  //increase first index and decrease size
  head_->first++;
  size_--;

  //if head becomes empty, remove it
  if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    if(head_==NULL){
      tail_ = NULL; //list now empty
    }
    else{
    head_->prev = NULL;
    }
    delete temp;
  }
}

//return last item
std::string const& ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

//return first item
std::string const& ULListStr::front() const{
  return head_->val[head_->first];
}

//get pointer to value at given loc
std::string* ULListStr::getValAtLoc(size_t loc) const{
  //check valid location
  if(loc>=size_) return NULL;
  
  Item*curr = head_;
  size_t currLoc = 0;

  //go through list
  while(curr!=NULL){
    if(currLoc + (curr->last - curr->first) > loc){
      return &curr->val[curr->first+(loc-currLoc)];
    }
    currLoc += curr->last - curr->first;
    curr = curr->next;
  }

  return NULL;
}