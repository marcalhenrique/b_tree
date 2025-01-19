#include "h/InputGenerator.h"
#include "h/BlockCommander.h"
#include "h/PolyPhase.h"
#include "h/b_tree.h"

//TODO: Implementar a funcao de ordenação.

int main(){
    const std::string filename = "input_data.txt";
    

    // gerar arquivo de entrada
    size_t blockSize = 997;
    generateInputFile(filename, 3000, 0, 3000);

    BlockCommander blockCommander;
    std::vector<std::vector<int>> sortedBlocks = blockCommander.sortBlocks(filename, blockSize);

    PolyPhase polyPhase;
    std::vector<int> mergedBlock = polyPhase.polyphaseMerge(sortedBlocks);

    std::ofstream outFile("output_data.txt");
    for (int value : mergedBlock){
        outFile << value << std::endl;
    }
    outFile.close();

    BTree<int, 3> btree;
    
    for (int value : mergedBlock ) {
        btree.insert(value);
    }

    btree.serialize("btree_data.txt");
    
    BTree<int, 3> newTree;
    newTree.deserialize("btree_data.txt");

    std::cout << "Estrutura da árvore após a desserialização:" << std::endl;
    //newTree.print();
    //std::cout << std::endl;

    



    return 0;
}