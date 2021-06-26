template <typename T>
struct node{
    T data;
    struct node *leftChild;
    struct node *rightChild; 
};

typedef struct node<int> NodeInt;
typedef struct node<float> NodeFloat;
typedef struct node<char> NodeChar;
typedef struct node<long> NodeLongInt;
typedef struct node<short> NodeShortInt;
typedef struct node<double> NodeDouble;

template <typename P, typename T>
P createBST(P root, T data){
    auto nod = &root;
    root = (P)malloc(sizeof(nod));
    root -> data = data;
    root -> leftChild = NULL;
    root -> rightChild = NULL;
    return root;
}

template <typename P, typename K>
void insertBST(P root, K data){
    auto nod = &root;
    P temp = root;
    P newNode = (P)malloc(sizeof(nod));
    newNode -> leftChild = NULL;
    newNode -> rightChild = NULL;
    newNode -> data = data;
    while(1){
        if(temp->data>=data){
            if(temp->leftChild==NULL){
                temp->leftChild = newNode;
                break;
            }
            temp = temp->leftChild;
        }
        else{
            if(temp->rightChild==NULL){
                temp->rightChild = newNode;
                break;
            }
            temp = temp->rightChild;
        }
    }
}

template <typename P, typename K>
void insert_allBST(P root, K list){
    for(auto it=list->begin();it!=list->end();it++){
        insertBST(root,*it);
    }
}

template <typename P, typename K, typename T>
P search_node(P root, K data, T prev){
    auto temp = root;
    *prev = root;
    while(temp){
        if(temp->data == data){
            return temp;
        }
        else if(temp->data > data){
            *prev = temp;
            temp = temp->leftChild;
        }
        else{
            *prev = temp;
            temp = temp -> rightChild;
        }
    }
    return NULL;
}

template <typename P, typename K, typename O>
O search_all_node(P root, K data, O list){
    auto temp = root;
    while(temp){
        if(temp->data == data){
            list.push_back(temp);
            temp = temp->leftChild;
        }
        else if(temp->data > data){
            temp = temp->leftChild;
        }
        else{
            temp = temp -> rightChild;
        }
    }
    return list;
} 

template <typename P, typename K>
P delete_node_met(P temp, K data){
    if(temp->rightChild==NULL && temp->leftChild==NULL){
        free(temp);
        return NULL;
    }
    if(temp->rightChild==NULL){
        auto t = temp->leftChild;
        free(temp);
        return t;
    }
    if(temp->leftChild==NULL){
        auto t = temp->rightChild;
        free(temp);
        return t;
    }
    auto pre_succ = temp;
    auto succ = inorder_successor(temp, &pre_succ);
    temp->data = succ->data;
    if(pre_succ->leftChild == succ){
        pre_succ->leftChild = delete_node_met(succ, succ->data);
    }
    else if(pre_succ->rightChild == succ){
        pre_succ->rightChild = delete_node_met(succ, succ->data);
    }
    return temp;
}

template <typename P, typename K>
P delete_node(P root, K data){
    auto prev = root;
    auto temp = search_node(root,data,&prev);
    if(temp != NULL){
        if(prev->rightChild == temp){
            prev->rightChild = delete_node_met(temp,data);
        }
        else if(prev->leftChild == temp){
            prev->leftChild = delete_node_met(temp,data);
        }
        else if(prev == temp){
            root = delete_node_met(temp,data);
        }
    }
    return root;
}

template <typename P, typename K>
P delete_allBST(P root, K list){
    for(auto it=list->begin();it!=list->end();it++){
        root = delete_node(root,*it);
    }
    return root;
}

template <typename K, typename T>
K inorder_successor(K root, T prev){
    auto temp = root->rightChild;
    while(temp->leftChild!=NULL){
        *prev = temp;
        temp = temp->leftChild;
    }
    return temp;
}

template <typename K, typename T>
K inorder_predesessor(K root, T prev){
    auto temp = root->leftChild;
    while(temp->rightChild!=NULL){
        *prev = temp;
        temp = temp->rightChild;
    }
    return temp;
}

template <typename P, typename S>
S inorder_traversal(P root, S list){
    if(root!=NULL){
        list = inorder_traversal(root->leftChild, list);
        list->push_back(root->data);
        list = inorder_traversal(root->rightChild, list);
    }
    return list;
}

template <typename P, typename S>
S preorder_traversal(P root, S list){
    if(root!=NULL){
        list.push_back(root->data);
        list = preorder_traversal(root->leftChild, list);
        list = preorder_traversal(root->rightChild, list);
    }
    return list;
}

template <typename P, typename S>
S postorder_traversal(P root, S list){
    if(root!=NULL){
        list = postorder_traversal(root->leftChild, list);
        list = postorder_traversal(root->rightChild, list);
        list.push_back(root->data);
    }
    return list;
}