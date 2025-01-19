#include "../h/PolyPhase.h"

std::vector<int> PolyPhase::polyphaseMerge(const std::vector<std::vector<int>>& blocks){
    
    std::priority_queue<HeapNode, std::vector<HeapNode>, Compare> minHeap;
    std::vector<int> mergedBlock;

    for (size_t i = 0; i < blocks.size(); i++){
        if (!blocks[i].empty()){
            minHeap.push({blocks[i][0], i, 0});
        }
    } 

    while (!minHeap.empty()){
        HeapNode top = minHeap.top();
        minHeap.pop();
        mergedBlock.push_back(top.value);

        if (top.index +1 < blocks[top.blockIndex].size()){
            minHeap.push({blocks[top.blockIndex][top.index + 1], top.blockIndex, top.index + 1});
        }

    }

    return mergedBlock;
}
