template <typename T>
class max_heap{

public:
    max_heap(){
        root = NULL;
        nextLeaf = NULL;
    }

private:
    typedef struct min_heap_node{
        T data;
        struct min_heap_node *leftChild;
        struct min_heap_node *rightChild;
        struct min_heap_node *parent;
    }Node;

public:
    Node* root;

private:
    Node* nextLeaf;
    
private:
    Node* findNextLeafNode(Node* node){
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

private:
    Node* findPrevLeafNode(Node* node){
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
        if(temp->rightChild)
        while(temp->rightChild->rightChild!=NULL){
            temp = temp->rightChild;
        }
        return temp;
    }

public:
    void create(T data){
        root = (Node*)malloc(sizeof(Node));
        root -> data = data;
        root -> leftChild = NULL;
        root -> rightChild = NULL;
        root -> parent = NULL;
        nextLeaf = root;
    }

private:
    void heapify_child(Node* node){
        while(node->parent!=NULL && node->parent->data>node->data){
            auto data = node->parent->data;
            node->parent->data = node->data;
            node->data = data;
            node = node->parent;
        }
    }

public:
    void insert(T data){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode -> leftChild = NULL;
        newNode -> rightChild = NULL;
        newNode -> data = data;
        newNode -> parent = NULL;
        if(nextLeaf->leftChild == NULL){
            nextLeaf->leftChild = newNode;
            newNode->parent = nextLeaf;
        }
        else if(nextLeaf->rightChild == NULL){
            nextLeaf->rightChild = newNode;
            newNode->parent = nextLeaf;
        }
        else{
            nextLeaf = findNextLeafNode(nextLeaf);
            nextLeaf->leftChild = newNode;
            newNode->parent = nextLeaf;
        }
        heapify_child(newNode);
    }

private:
    void heapify_parent(Node* node){
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

public:
    T pop_min(){
        if(root==NULL){
            throw std::underflow_error("Given Tree is Empty");
        }
        auto temp = root->data;
        if(root->leftChild==NULL && root->rightChild == NULL){
            free(root);
            root = NULL;
            return temp;
        }
        if(nextLeaf->rightChild!=NULL){
            root->data = nextLeaf->rightChild->data;
            auto tempN = nextLeaf->rightChild;
            nextLeaf->rightChild = NULL;
            free(tempN);
            heapify_parent(root);
        }
        else if(nextLeaf->leftChild!=NULL){
            root->data = nextLeaf->leftChild->data;
            auto tempN = nextLeaf->leftChild;
            nextLeaf->leftChild = NULL;
            free(tempN);
            heapify_parent(root);
        }
        else{
            nextLeaf = findPrevLeafNode(nextLeaf);
            pop_min();
        }
        return temp;
    }

public:
    T get_max(){
        return get_max_impl(root);
    }

private:
    T get_max_impl(Node* node){
        if(root==NULL){
            throw std::underflow_error("Given Tree is Empty");
        }
        if(node->leftChild == NULL && node->rightChild==NULL){
            return node->data;
        }
        T maxLeft=std::numeric_limits<T>::min();
        T maxRight = maxLeft;
        if(node->leftChild)
            maxLeft = get_max_impl(node->leftChild);
        if(node->rightChild)
            maxRight = get_max_impl(node->rightChild);
        if(maxLeft>maxRight){
            return maxLeft;
        }
        else{
            return maxRight;
        }
    }

private:
    Node* traverse_tree(Node* node, T data){
        static Node* temp = NULL;
        if(node!=NULL){
            traverse_tree(node->leftChild, data);
            if(data == node->data){
                temp = node;
            }
            traverse_tree(node->rightChild, data);
        }
        return temp;
    }

public:
    Node* searchnode(T data){
        if(root==NULL){
            throw std::underflow_error("Given Tree is Empty");
        }
        auto temp = root;
        temp = traverse_tree(temp,data);
        if(temp){
            return temp;
        }
        else{
            throw std::underflow_error("Given Number is not present in the tree");
        }
    }
};