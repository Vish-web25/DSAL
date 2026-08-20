#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    // Recursive Insert
    void insert(Node *&temp, int value)
    {
        if (temp == NULL)
        {
            temp = new Node;
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            return;
        }
        if (value < temp->data)
            insert(temp->left, value);
        else
            insert(temp->right, value);
    }
    // Recursive Inorder Traversal
    // Left -> Root -> Right
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    // Recursive Preorder Traversal
    // Root -> Left -> Right
    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
    // Recursive Postorder Traversal
    // Left -> Right -> Root
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
};
int main()
{
    BST tree;
    int choice, value;
    do
    {
        cout << "\n===== Binary Search Tree Menu =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(tree.root, value);
            break;
        case 2:
            cout << "Inorder traversal: ";
            tree.inorder(tree.root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder traversal: ";
            tree.preorder(tree.root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder traversal: ";
            tree.postorder(tree.root);
            cout << endl;
            break;
        case 5:
            cout << "Program Exited.";
            break;
        default:
            cout << "Thanks!";
        }
    } while (choice != 5);
    return 0;
}
