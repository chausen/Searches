/*
    I did NOT write this code.
    I have downloaded the code from the Internet, and slightly modified it for today's class.

    This code did NOT attempt to show good design practices, error-handling etc.
    It shows the very basic code to create a BST!

    The idea is to show you the following:
        - how to create a node in a tree in general
        - how to insert a node (in BST)
        - how to search for a key (in BST)
        - tree traversal (in-order, pre-order, post-order)

    Now, you can add:
        - ... a LOT of functionalities here!

        - create a BST class (very easy!)
        - try ALL the tree traversals.
        - delete of a node
        - write a template for BST!
*/

// C++ program to demonstrate insert operation in binary search tree
#include <iostream>

using namespace std;

class Node
{
    // In a better design, move key, left and right as private.
    // write public methods to access those!
    public:
        int key;
        class Node *left, *right;
        Node(int k)
        {
            key = k;
            left = right = NULL;
        }
};

// C++ function to search a given key in a given BST
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return new Node(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to do in-order traversal of BST
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    class Node *root = NULL;

    if (root == NULL)   root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print in-order traversal of the BST
    inorder(root);
    cout << endl;

    // demonstrate the search operation in BST
    if (search(root, 10) == NULL)   cout << "No" << endl;
    else                            cout << "Yes" << endl;

    if (search(root, 800) == NULL)  cout << "No" << endl;
    else                            cout << "Yes" << endl;

    return 0;
}
