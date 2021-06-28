#include<iterator>
#include<vector>
template <typename T>
class binary_search_tree{
private:
    typedef struct bstnode{
        T data;
        struct bstnode *leftChild;
        struct bstnode *rightChild; 
    }Node;

private:
    Node* prev;

private:
    Node* pre_succ;

public:
    Node* root;

public:
    void inorder_traversal(Node* node, std::vector<T> &list){
        if(node!=NULL){
            inorder_traversal(node->leftChild, list);
            list.push_back(node->data);
            inorder_traversal(node->rightChild, list);
        }
    }

public:
    void preorder_traversal(Node* node, std::vector<T> &list){
        if(node!=NULL){
            list.push_back(node->data);
            preorder_traversal(node->leftChild, list);
            preorder_traversal(node->rightChild, list);
        }
    }

public:
    void postorder_traversal(Node* node, std::vector<T> &list){
        if(node!=NULL){
            postorder_traversal(node->leftChild, list);
            postorder_traversal(node->rightChild, list);
            list.push_back(node->data);
        }
    }

public:
    Node* inorder_successor(Node* node){
        Node* temp = node->rightChild;
        while(temp->leftChild!=NULL){
            pre_succ = temp;
            temp = temp->leftChild;
        }
        return temp;
    }

public:
    Node* inorder_predesessor(Node* node){
        Node* temp = node->leftChild;
        while(temp->rightChild!=NULL){
            pre_succ = temp;
            temp = temp->rightChild;
        }
        return temp;
    }

private:
    Node* delete_node_met(Node* temp, T data){
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
        pre_succ = temp;
        auto succ = inorder_successor(temp);
        temp->data = succ->data;
        if(pre_succ->leftChild == succ){
            pre_succ->leftChild = delete_node_met(succ, succ->data);
        }
        else if(pre_succ->rightChild == succ){
            pre_succ->rightChild = delete_node_met(succ, succ->data);
        }
        return temp;
    }

public:
    void deleten(T data){
        prev = root;
        auto temp = search(data);
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
    }

public:
    void delete_multiple(std::vector<T> list){
        for(auto it=list.begin();it!=list.end();it++){
            deleten(*it);
        }
    }

public:
    template <typename Iterator>
    void delete_multiple(Iterator begin, Iterator end){
        for(auto it=begin;it!=end;it++){
            deleten(*it);
        }
    }

public:
    void create(T data){
        root = (Node*)malloc(sizeof(Node));
        root -> data = data;
        root -> leftChild = NULL;
        root -> rightChild = NULL;
    }

public:
    void insert(T data){
        Node* temp = root;
        Node* newNode = (Node*)malloc(sizeof(Node));
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

public:
    void insert_multiple(std::vector<T> list){
        for(auto it=list.begin();it!=list.end();it++){
            insert(*it);
        }
    }

public:
    Node* search(T data){
        auto temp = root;
        prev = root;
        while(temp){
            if(temp->data == data){
                return temp;
            }
            else if(temp->data > data){
                prev = temp;
                temp = temp->leftChild;
            }
            else{
                prev = temp;
                temp = temp -> rightChild;
            }
        }
        return NULL;
    }

public:
    bool compare_trees(binary_search_tree<T> t2){
        auto t2_node = t2.root;
        auto t1_node = root;
        return comp_nodes(t1_node, t2_node);
    }

private:
    bool comp_nodes(Node* t1, Node* t2){
        if(t1 && t2){
            if(t1->data != t2->data){
                return false;
            }
            else{
                bool eq1, eq2;
                eq1 = comp_nodes(t1->leftChild, t2->leftChild);
                eq2 = comp_nodes(t1->rightChild, t2->rightChild);
                return eq1 && eq2;
            }
        }
        else if(t1){
            return false;
        }
        else if(t2){
            return false;
        }
        else{
            return true;
        }
    }

};

