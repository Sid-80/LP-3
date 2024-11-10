#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    char character;
    bool isInternalNode;
    Node()
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = -1;
        this->character = 'x';
        this->isInternalNode = true;
    }
    Node(int data, char character)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
        this->character = character;
        this->isInternalNode = false;
    }
};

void printCodes(Node *node, string code)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        cout << "Character : " << node->character << endl;
        cout << "Code : " << code << endl;
        cout << endl;
        return;
    }

    if (node->left)
    {
        printCodes(node->left, code + "0");
    }

    if (node->right)
    {
        printCodes(node->right, code + "1");
    }

    return;
}

int main(int argc, char const *argv[])
{
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

    int n;
    cout << "Enter total characters : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char x;
        cout << "Enter character : ";
        cin >> x;
        int freq;
        cout << "Enter frequency : ";
        cin >> freq;

        Node *n1 = new Node(freq, x);

        pq.push({freq, n1});
    }

    // Constructing huffman tree
    while (!pq.empty())
    {

        if (pq.size() == 1)
        {
            cout << pq.top().first << endl;
            break;
        }

        pair<int, Node *> x1 = pq.top();
        pq.pop();

        pair<int, Node *> x2 = pq.top();
        pq.pop();

        Node *n1 = new Node();
        n1->data = x1.first + x2.first;
        n1->left = x1.second;
        n1->right = x2.second;

        pq.push({n1->data, n1});
    }

    Node *root = pq.top().second;
    pq.pop();

    // Printing codes
    printCodes(root, "");

    return 0;
}