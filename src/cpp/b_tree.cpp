#include "../h/b_tree.h"

template class BTree<int, 3>;

template <typename T, const unsigned int MIN_DEGREE>
void BTree<T, MIN_DEGREE>::insert(T key) {
    if (!root) {
        // Caso a árvore esteja vazia, cria um novo nó raiz
        root = new BTreeNode<T, MIN_DEGREE>(true);
        root->keys[0] = key; // Insere a chave na raiz
        root->numKeys = 1;   // Atualiza o número de chaves no nó
    } else {
        if (root->numKeys == 2 * MIN_DEGREE - 1) {
            // Se a raiz estiver cheia, cria uma nova raiz
            BTreeNode<T, MIN_DEGREE>* newRoot = new BTreeNode<T, MIN_DEGREE>(false);

            // A antiga raiz se torna o primeiro filho da nova raiz
            newRoot->children[0] = root;

            // Divide a raiz cheia
            splitChild(newRoot, 0);

            // Atualiza a raiz para a nova raiz
            root = newRoot;
        }

        // Insere a chave no local apropriado
        insertNonFull(root, key);
    }
}


template <typename T, const unsigned int MIN_DEGREE>
void BTree<T, MIN_DEGREE>::insertNonFull(BTreeNode<T, MIN_DEGREE>* node, T key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // move as chaves maiores pra direita
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            --i;
        }
        // insere na posicao correta
        node->keys[i + 1] = key;
        ++node->numKeys;
    } else {
        // encontra o filho certo pra inserc
        while (i >= 0 && key < node->keys[i]) {
            --i;
        }
        ++i;

        // verifica se o filho ta cheio
        if (node->children[i]->numKeys == 2 * MIN_DEGREE - 1) {
            splitChild(node, i);

            // decide em qual filho inserir
            if (key > node->keys[i]) {
                ++i;
            }
        }

        // insert recursivo no filho
        insertNonFull(node->children[i], key);
    }
}


template <typename T, const unsigned int MIN_DEGREE>
void BTree<T, MIN_DEGREE>::splitChild(BTreeNode<T, MIN_DEGREE>* parent, int index) {
    BTreeNode<T, MIN_DEGREE>* fullNode = parent->children[index];
    BTreeNode<T, MIN_DEGREE>* newNode = new BTreeNode<T, MIN_DEGREE>(fullNode->isLeaf);

    newNode->numKeys = MIN_DEGREE - 1; // Nova folha terá MIN_DEGREE - 1 chaves

    // Copia as chaves da metade superior de fullNode para newNode
    for (unsigned int  i = 0; i < MIN_DEGREE - 1; i++) {
        newNode->keys[i] = fullNode->keys[i + MIN_DEGREE];
    }

    // Se não for folha, copia os filhos
    if (!fullNode->isLeaf) {
        for (unsigned int i = 0; i < MIN_DEGREE; i++) {
            newNode->children[i] = fullNode->children[i + MIN_DEGREE];
        }
    }

    // Atualiza o número de chaves no nó cheio
    fullNode->numKeys = MIN_DEGREE - 1;

    // Ajusta os filhos do nó pai
    for (int i = parent->numKeys; i >= index + 1; --i) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newNode;

    // Ajusta as chaves do nó pai
    for (int i = parent->numKeys - 1; i >= index; --i) {
        parent->keys[i + 1] = parent->keys[i]; // Corrigido: uso de 'i' no lugar de 'j'
    }
    parent->keys[index] = fullNode->keys[MIN_DEGREE - 1];
    ++parent->numKeys;
}

template <typename T, const unsigned int MIN_DEGREE>
bool BTreeNode<T, MIN_DEGREE>::search(T key){
    unsigned int i = 0;
    while (i < numKeys && key > keys[i]) {
        i++;
    }

    if (i < numKeys && keys[i] == key){
        return true;
    }

    if (isLeaf) {
        return false;
    }

    return children[i]->search(key);
}

template <typename T, const unsigned int MIN_DEGREE>
bool BTree<T, MIN_DEGREE>::search(T key){
    if (!root) {
        return false;
    }
    return root->search(key);
}




template <typename T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::print(){
    for (unsigned int i = 0; i < numKeys; i++) {
        if (!isLeaf){
            children[i]->print();
        }
        std::cout << keys[i] << " ";
    }
    if (!isLeaf) {
        children[numKeys]->print();
    }
}

template <typename T, const unsigned int MIN_DEGREE>
void BTree<T, MIN_DEGREE>::print(){
    if (root){
        root->print();
    } else{
        std::cout << "A arvore ta vazia" << std::endl;

    }
        
}



