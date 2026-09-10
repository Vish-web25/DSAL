#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Function to create a binary tree
Node *root = NULL;
class Tree
{
    public:
    void insert(Node *&temp,int value)
    {



        if (value == -1)
        {
            temp = NULL;
            return;
        }

         if(temp==NULL)
             {
             temp = new Node;
             temp->data = value;
             temp->left = NULL;
             temp->right = NULL;
             return;
            }

         else if(temp->left==NULL)
              insert(temp->left,value);
          else
              insert(temp->right,value);



    }


void createTree(int value)
{
        insert(root,value);
}


// Inorder Traversal
void inorder(Node *temp)
{
     if (temp == NULL)
                return;
    else
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

// Preorder Traversal
void preorder(Node *temp)
{
     if (temp == NULL)
                return;
    else
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

// Postorder Traversal
void postorder(Node *temp)
{
     if (temp == NULL)
                return;
    else
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}
};
int main()
{
   Tree t;
    int choice,value;

    do
    {
        cout << "\n===== Binary Tree Menu =====";
        cout << "\n1. Create Binary Tree";
        cout << "\n2. Insert Node";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value (-1 for NULL): ";
            cin >> value;
            cout << "\nCreate Binary Tree\n";
            t.createTree(value);
            break;
      case 2:
          cout << "Enter value (-1 for NULL): ";
          cin >> value;
          t.insert(root,value);

            break;

        case 3:
 if(root == NULL)
        cout << "Tree is empty!";
    else
    {


                cout << "Inorder Traversal: ";
                t.inorder(root);
                cout << endl;
    }
            break;

        case 4:
             if(root == NULL)
        cout << "Tree is empty!";
    else
    {
                cout << "Preorder Traversal: ";
                t.preorder(root);
                cout << endl;
    }
            break;

        case 5:
 if(root == NULL)
        cout << "Tree is empty!";
    else
    {
                cout << "Postorder Traversal: ";
                t.postorder(root);
                cout << endl;
    }
            break;

        case 6:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
