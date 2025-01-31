#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

//helper function to print list
void printList(ULListStr&list){
  cout << "List (size=" << list.size() << "): ";
  for(size_t i=0; i<list.size(); i++){
    cout << list.get(i) << " ";
  }
  cout << endl;
}

int main(int argc, char* argv[])
{
  ULListStr dat;
  //test 1: empty list
  cout << "\n=== Test 1: Empty List ===\n";
  cout << "Empty list size: " << dat.size() << endl;

  //test 2: push_back on empty list and multiple items
  cout << "\n=== Test 2: Push_back test ===\n";
  dat.push_back("a");
  cout << "After first push_back: ";
  printList(dat);
  cout << "Front: " <<dat.front() << "Back: " << dat.back() << endl;

  //add more items to test array fill
  for(int i=0; i<10; i++){
    dat.push_back(to_string(i));
  }
  cout << "After multiple push_backs: ";
  printList(dat);

  //test 3: push_front
  cout << "\n=== Test 3: Push_front test ===\n";
  dat.push_front("front1");
  dat.push_front("front2");
  cout << "After push_fronts: ";
  printList(dat);
  cout << "Front: " << dat.front() << ", Back: " << dat.back() << endl;

  //test 4: pop operations
  cout <<"\n=== Test 4: Pop tests ===\n";
  dat.pop_front();
  cout << "After pop_front: ";
  printList(dat);

  dat.pop_back();
  cout << "After pop_back: ";
  printList(dat);

  //test 5: edge cases - empty list
  cout << "\n=== Test 5: Empty list through pops ===\n";
  while(dat.size() > 0){
    cout << "Popping back: " << dat.back() << endl;
    dat.pop_back();
  }
  cout << "Size after emptying: " << dat.size() << endl;

  //test 6: multiple operations
  cout << "\n=== Test 6: Mulitple operations sequence ===\n";
  dat.push_back("first");
  dat.push_back("second");
  dat.push_front("front");
  cout << "After sequence: ";
  printList(dat);

  //test 7: test array wraparound
  cout << "\n=== Test 7: Array wraparound test ===\n";
  ULListStr wrap;
  //fill first node
  for(int i=0; i<10; i++){
    wrap.push_back(to_string(i));
  }
  //add to front to test wraparound
  wrap.push_front("wrap1");
  wrap.push_front("wrap2");
  cout << "After wraparound: ";
  for(size_t i=0; i<wrap.size(); i++){
    cout << wrap.get(i) << " ";
  }
  cout << endl;

  //test 8: get value at location
  cout << "\n=== Test 8: Get value at location ===\n";
  cout << "First value: " << wrap.get(0) << endl;
  cout << "Middle value: " << wrap.get(wrap.size()/2) << endl;
  cout << "Last value: " << wrap.get(wrap.size()-1) << endl;

  try{
    cout << "Attempting to access invalid location..." << endl;
    wrap.get(100); //throw exception
  }
  catch(const std::invalid_argument& e){
    cout << "Successfully caught invalid location access" << endl;
  }

  cout << "\nAll tests completed!\n";
  return 0;
}
