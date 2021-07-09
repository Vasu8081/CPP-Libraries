#include<iterator>
#include<vector>


/**
 * @brief A binary search tree which offers operations like insertions, deletions and all.
 * 
 * @tparam T Parameter is datatype of node. It can be of any type which can be compared by relational operators like <, > , ==.
 */
template <typename T>
class binary_search_tree{
    typedef struct bstnode{
        T data;
        int depth_of_node;
        struct bstnode *leftChild;
        struct bstnode *rightChild;
    }Node;
/**
 * @brief This is pointer to root node of binary tree
 * 
 */
protected:
    Node* root;

/**
 * @brief This is the height of the tree.
 * 
 */
public:
    int height_of_tree;

/**
 * @brief It takes a list and copies inorder traversal of elements of tree to that list
 * 
 * @param node It is root node of the tree
 * 
 * @param list where we need to save the inorder traversal of elements
 */
public:
    virtual void inorder_traversal(Node* node, std::vector<T> &list) = 0;

/**
 * @brief It takes a list and copies preorder traversal of elements of tree to that list
 * 
 * @param node It is root node of the tree
 * 
 * @param list where we need to save the preorder traversal of elements
 */
public:
    virtual void preorder_traversal(Node* node, std::vector<T> &list) = 0;

/**
 * @brief It takes a list and copies postorder traversal of elements of tree to that list
 * 
 * @param node It is root node of the tree
 * 
 * @param list where we need to save the postorder traversal of elements
 */
public:
    virtual void postorder_traversal(Node* node, std::vector<T> &list) = 0;

/**
 * @brief It returns level order traversal of elements of tree
 * 
 * @param node It is root node of the tree
 * 
 * @param it iterator where we need to save elements of level order traversal
 */
public:
    template <typename Iterator>
    void levelorder_traversal(Node* node, Iterator it);

/**
 * @brief Returns inorder successor of given node
 * 
 * @param node node for which we need to find inorder successor
 */
public:
    virtual Node* inorder_successor(Node* node) = 0;

/**
 * @brief Returns inorder predecessor of given node
 * 
 * @param node node for which we need to find inorder predecessor
 */
public:
    virtual Node* inorder_predesessor(Node* node) = 0;

/**
 * @brief deletes the given data from the tree
 * 
 * @param data data that needed to be deleted
 */
public:
    virtual void deleten(T data) = 0;

/**
 * @brief deletes all the elements from given list
 * 
 * @param list list of elements that needed to be deleted
 */
public:
    virtual void deleten(std::vector<T> list) = 0;

/**
 * @brief deletes all the elements given in between those iterators.
 * 
 * @param begin beginning iterator
 * 
 * @param end ending iterator
 */
public:
    template <typename Iterator>
    void deleten(Iterator begin, Iterator end);

/**
 * @brief creates a root node and inserts the data given into it.
 * 
 * @param data data that needed to be inserted in root node
 */
public:
    virtual  void create(T data) = 0;

/**
 * @brief inserts given element into the tree
 * 
 * @param data data that needed to be inserted in the tree
 */
public:
    virtual void insert(T data) = 0;

/**
 * @brief inserts a group of elements into the tree.
 * 
 * @param list list from where data needs to be inserted.
 */
public:
    virtual void insert(std::vector<T> list) = 0;

/**
 * @brief returns a pointer to the node where data is present
 * 
 * @param data data that needs to be searched
 */
public:
    virtual Node* search(T data) = 0;

};