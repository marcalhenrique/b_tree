#ifndef POLYPHASE_H
#define POLYPHASE_H

#include <vector>
#include <queue>
#include <cstddef>

class PolyPhase {
    public:
        std::vector<int> polyphaseMerge(const std::vector<std::vector<int>>& blocks);
    
    private:
        struct HeapNode{
            int value;
            size_t blockIndex;
            size_t index;
        };

        struct Compare{
            bool operator()(const HeapNode& a, const HeapNode& b) {
                return a.value > b.value;
            }
        };
};

#endif // POLYPHASE_H