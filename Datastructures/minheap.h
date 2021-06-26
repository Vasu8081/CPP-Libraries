template <typename T>
struct node{
    T data;
    struct node *leftChild;
    struct node *rightChild;
    struct node *parent;
};

typedef struct node<int> NodeInt;
typedef struct node<float> NodeFloat;
typedef struct node<char> NodeChar;
typedef struct node<long> NodeLongInt;
typedef struct node<short> NodeShortInt;
typedef struct node<double> NodeDouble;

void* nextLeaf;

template <typename T>
T findNextLeafNode(T node){
    auto temp = node;
    while(temp->parent != NULL){
        if(temp->parent->leftChild == temp){
            temp = temp->parent->rightChild;
            while(temp->leftChild){
                temp = temp->leftChild;
            }
            return temp;
        }
        else{
            temp = temp->parent;
        }
    }
    while(temp->leftChild!=NULL){
        temp = temp->leftChild;
    }
    return temp;
}

template <typename T>
T findPrevLeafNode(T node){
    auto temp = node;
    while(temp->parent != NULL){
        if(temp->parent->rightChild == temp){
            temp = temp->parent->leftChild;
            while(temp->rightChild->rightChild){
                temp = temp->rightChild;
            }
            return temp;
        }
        else{
            temp = temp->parent;
        }
    }
    while(temp->rightChild->rightChild!=NULL){
        temp = temp->rightChild;
    }
    return temp;
}

template <typename P, typename T, typename K>
P create_min_heap(P root, T data, K type){
    root = (P)malloc(sizeof(K));
    root -> data = data;
    root -> leftChild = NULL;
    root -> rightChild = NULL;
    root -> parent = NULL;
    nextLeaf = root;
    return root;
}

template <typename P>
void heapify_child(P node){
    while(node->parent!=NULL && node->parent->data>node->data){
        auto data = node->parent->data;
        node->parent->data = node->data;
        node->data = data;
        node = node->parent;
    }
}

template <typename P, typename T, typename K>
void insert_min_heap(P root, K data, T type){
    P nextLeafNode = (P)nextLeaf;
    P newNode = (P)malloc(sizeof(T));
    newNode -> leftChild = NULL;
    newNode -> rightChild = NULL;
    newNode -> data = data;
    newNode -> parent = NULL;
    if(nextLeafNode->leftChild == NULL){
        nextLeafNode->leftChild = newNode;
        newNode->parent = nextLeafNode;
    }
    else if(nextLeafNode->rightChild == NULL){
        nextLeafNode->rightChild = newNode;
        newNode->parent = nextLeafNode;
    }
    else{
        nextLeafNode = findNextLeafNode(nextLeafNode);
        nextLeaf = nextLeafNode;
        nextLeafNode->leftChild = newNode;
        newNode->parent = nextLeafNode;
    }
    heapify_child(newNode);
}

template <typename P>
void heapify_parent(P node){
    if(node->leftChild!=NULL && node->rightChild!=NULL){
        if(node->leftChild->data <= node->rightChild->data && node->leftChild->data < node->data){
            auto temp = node->data;
            node->data = node->leftChild->data;
            node->leftChild->data = temp;
            heapify_parent(node->leftChild);
        }
        else if(node->rightChild->data <= node->leftChild->data && node->rightChild->data < node->data){
            auto temp = node->data;
            node->data = node->rightChild->data;
            node->rightChild->data = temp;
            heapify_parent(node->rightChild);
        }
    }
    else if(node->leftChild!=NULL){
        if(node->leftChild->data < node->data){
            auto temp = node->data;
            node->data = node->leftChild->data;
            node->leftChild->data = temp;
            heapify_parent(node->leftChild);
        }
    }
    else if(node->rightChild!=NULL){
        if(node->rightChild->data < node->data){
            auto temp = node->data;
            node->data = node->rightChild->data;
            node->rightChild->data = temp;
            heapify_parent(node->rightChild);
        }
    }
}

template <typename P, typename K>
K pop_min(P root, K data){
    P nextLeafNode = (P)nextLeaf;
    auto temp = root->data;
    if(nextLeafNode->rightChild!=NULL){
        root->data = nextLeafNode->rightChild->data;
        auto tempN = nextLeafNode->rightChild;
        nextLeafNode->rightChild = NULL;
        free(tempN);
        heapify_parent(root);
    }
    else if(nextLeafNode->leftChild!=NULL){
        root->data = nextLeafNode->leftChild->data;
        auto tempN = nextLeafNode->leftChild;
        nextLeafNode->leftChild = NULL;
        free(tempN);
        heapify_parent(root);
    }
    else{
        nextLeafNode = findPrevLeafNode(nextLeafNode);
        nextLeaf = nextLeafNode;
        pop_min(root,data);
    }
    return temp;
}

template <typename P, typename K>
K get_max(P node, K data){
    if(node->leftChild == NULL && node->rightChild==NULL){
        return node->data;
    }
    K minLeft=std::numeric_limits<K>::min();
    K minRight = minLeft;
    if(node->leftChild)
    minLeft = get_max(node->leftChild, data);
    if(node->rightChild)
    minRight = get_max(node->rightChild, data);
    if(minLeft>minRight){
        return minLeft;
    }
    else{
        return minRight;
    }
}