#include <iostream>
#include "MaxHeap.h"

using std::cout;
using std::cin;
using std::endl;
using namespace Alg477;

int main() {
    std::string input = "OTXGSPNAERAIM";  // <-- change input
    MaxHeap heap(input);
    cout << "Heap elements: " << heap << endl << endl;

    cout << "Before heapify:" << endl;
    heap.printTree();

    heap.heapifyAll();  // <-- calls heapify

    cout << endl << "After heapify:" << endl;
    heap.printTree();

    return 0;
}
