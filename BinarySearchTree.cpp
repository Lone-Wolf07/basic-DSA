#include <iostream>
using namespace std;
class Node {
    int data;
    Node* left;
    Node* right;

    Node* Insert (Node* curNode, int v)
    {
        if (curNode == NULL) 
        {
            Node* newNode = new Node ();
            newNode->data = v;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        else if (v < curNode->data)
        curNode->left = Insert(curNode->left, v);

        else if (v > curNode->data)
        curNode->right = Insert(curNode->right, v);
        return curNode;
}

    Node* Search (Node* curNode, int searchValue)
    {
        if (curNode == NULL or curNode->data == searchValue) return curNode;

        if (curNode->data < searchValue)
        return Search(curNode->right, searchValue);
        return Search (curNode->left, searchValue);
}

    int maxValue (Node* curNode)
    {
        if (curNode == NULL) return -1;

        if (curNode->right == NULL) return curNode->data;

        return maxValue(curNode->right);
}

    int minValue (Node* curNode)
    {
        if (curNode == NULL) return -1;
        if (curNode->left == NULL) return curNode->data;
        return minValue(curNode->left);
    }

   


 Node* findMin(Node* curNode) 
    {
        while (curNode->left != NULL) curNode = curNode->left;
        return curNode;
}

    Node* deleteNode(Node* curNode, int v) 
    {
        if (curNode == NULL) return curNode;

        if (v < curNode->data) curNode->left 
= deleteNode(curNode->left, v);
        else if (v > curNode->data) curNode->right = deleteNode(curNode->right, v);

        else 
        {
            if (curNode->left == NULL) 
            {
                Node* temp = curNode->right;
                delete curNode;
                return temp;
            } 
            
            else if (curNode->right == NULL) 
            {
                Node* temp = curNode->left;
                delete curNode;
                return temp;
            }

            Node* temp = findMin(curNode->right);
            curNode->data = temp->data;
            curNode->right = deleteNode(curNode->right, temp->data);
        }
        return curNode;
    }

    public:
    
    Node* root = NULL; 
    
    bool Insert(int v) 
    {
        root = Insert(root, v);
        return Search(v);
}




    bool Search(int searchValue) 
    {
        Node* searchNode = Search(root, searchValue);
        if (searchNode == NULL) return false;

        return searchNode->data == searchValue;
}

    void Delete(int v)
    {
        root = deleteNode(root, v);
        
}

    int maxValue() 
    {
        return maxValue(root);
    }
    
    int minValue() 
    {
        return minValue(root);
    }

    void inOrder(Node* node) 
    {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
    void preOrder(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void postOrder(Node* node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
    void displayInOrder() {
        inOrder(root);
        cout << endl;
    }
    void displayPreOrder() {
        preOrder(root);
        cout << endl;
    }
    void displayPostOrder() {
        postOrder(root);
        cout << endl;
    }
};

void menu() {
    Node bst;
int choice, value;

    while (true) {
        cout<<endl;
        cout << "Binary Search Tree Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display In-order\n";
        cout << "5. Display Pre-order\n";
        cout << "6. Display Post-order\n";
        cout << "7. Find Minimum\n";
        cout << "8. Find Maximum\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.Insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.Delete(value);
                break;
            case 3:
                cout << "Enter value to search for: ";
                cin >> value;
                if (bst.Search(value)) cout << "Value found\n";
                else cout << "Value not found\n";
                break;
            case 4:
                bst.displayInOrder();
                break;
            case 5:
                bst.displayPreOrder();
                break;
            case 6:
                bst.displayPostOrder();
                break;
            case 7:
                cout << "Minimum value: " << bst.minValue() << endl;
                break;
            case 8:
                cout << "Maximum value: " << bst.maxValue() << endl;
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


int main() {
    menu();
    return 0;
}
