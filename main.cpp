
#include <iostream>
#include "LLWrapper.h"

int main(int argc, char* argv[]) {
    LLWrapper<int> * head = new LLWrapper<int>(10);
    head->insert(20);
    head->insert(5);
    head->insert(10);
    head->print();
    delete head;
    return 0;
  
}
