#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>
#include "MaxHeap.h"

using std::string;
using std::vector;

namespace Alg477 {

    MaxHeap::MaxHeap() {
        m_heapArray = vector<char>();
    }

    MaxHeap::MaxHeap(string entries) {
        m_heapArray = stringToVector(entries);
    }

    std::ostream& operator<<(std::ostream& stream, const MaxHeap& heap) {
        size_t index;
        for (index = 0; index < heap.m_heapArray.size() - 1; ++index) {
            stream << heap.m_heapArray[index] << ", ";
        }

        stream << heap.m_heapArray[index];
        return stream;
    }

    void MaxHeap::heapifyAll() {
        // Heapify n/2 - 1 down to 0
        for (size_t n = m_heapArray.size(), index = n / 2; index --> 0;) {
            heapify(index);
        }
    }

    void MaxHeap::printTree() {
        size_t index = m_root;
        size_t lineHeight = height() + 1;
        for (; lineHeight --> 0; index = leftOf(index)) {
            printTreeLine(lineHeight, index);
            std::cout << std::endl;
        }
    }

    size_t MaxHeap::height() {
        return static_cast<size_t>(log2(m_heapArray.size()));
    }

    char MaxHeap::valueOf(size_t index) {
        return m_heapArray[index];
    }

    size_t MaxHeap::leftOf(size_t index) {
        return 2 * index + 1;
    }

    size_t MaxHeap::rightOf(size_t index) {
        return 2 * index + 2;
    }

    size_t MaxHeap::parentOf(size_t index) {
        return index / 2 - 1;
    }

    ///////////////////////////////////////////////////////////////////
    //                     heapify                                   //
    ///////////////////////////////////////////////////////////////////
    void MaxHeap::heapify(size_t index) { 
        size_t swappedIndex;

        while (index <= m_heapArray.size()) {
            std::cout << std::endl << index << ":" << std::endl;
            printTree();  // for tree view
            //std::cout << *this << std::endl;  // for linear view

            if (makeMax(index, swappedIndex) == false) break;
            index = swappedIndex;
        }
    }

    vector<char> MaxHeap::stringToVector(string str) {
        vector<char> vec;
        for (size_t index = 0; index < str.size(); ++index) {
            vec.push_back(str[index]);
        }
        return vec;
    }

    void MaxHeap::printTreeLine(size_t line, size_t index) {
        size_t i;
        printSpaces(pow(2, line) - 1);

        // Start at index; Go until 2 * index, skip 0 case, and ensure within array bounds
        for (i = index; i < 2 * index && i > 0 && i < m_heapArray.size() - 1; ++i) {
            std::cout << m_heapArray[i];
            printSpaces(pow(2, line + 1) - 1);
        }
        std::cout << m_heapArray[i];
    }

    void MaxHeap::printSpaces(size_t number) {
        for (size_t i = 0; i < number; ++i) {
            std::cout << ' ';
        }
    }

    //////////////////////////////////////////////////////////////////
    //                         makeMax                              //
    //////////////////////////////////////////////////////////////////
    bool MaxHeap::makeMax(size_t index, size_t& swapped) {
        auto size = m_heapArray.size();
        auto left = leftOf(index);
        auto right = rightOf(index);
        size_t max;

        if (left < size && valueOf(left) > valueOf(index))
            max = left;
        else
            max = index;
        if (right < size && valueOf(right) > valueOf(max))
            max = right;

        if (max != index) {
            swap(max, index);
            swapped = max;
            return true;
        }
        else return false;
    }

    void MaxHeap::swap(size_t index1, size_t index2) {
        std::swap(m_heapArray[index1], m_heapArray[index2]);
    }
}
