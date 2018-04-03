#ifndef __MAXHEAP_H_INCLUDE__
#define __MAXHEAP_H_INCLUDE__

#include <vector>

namespace Alg477 {

    class MaxHeap {

    public:
        MaxHeap();
        MaxHeap(std::string input);

        friend std::ostream& operator<<(std::ostream& stream, const MaxHeap& heap);

        void heapifyAll();
        void printTree();
        size_t height();

    private:
        std::vector<char> m_heapArray;

        const size_t m_root = 0;
        char valueOf(size_t index);
        size_t leftOf(size_t index);
        size_t rightOf(size_t index);
        size_t parentOf(size_t index);
        
        void heapify(size_t index);

        std::vector<char> stringToVector(std::string str);
        void printTreeLine(size_t line, size_t index);
        void printSpaces(size_t spaces);
        bool makeMax(size_t index, size_t& swappedIndex);
        void swap(size_t index1, size_t index2);
    };
};

#endif  // __MAXHEAP_H_INCLUDE__
