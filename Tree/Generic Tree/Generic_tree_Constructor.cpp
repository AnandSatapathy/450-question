#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    vector<Node *> children;
};
// Creating the New Node structure
Node *newNode(int value)
{
    Node *node = new Node;
    node->data = value;
    return node;
}
// constructing the binary tree structure
Node *constructor(vector<int> arr, int n)
{
    Node *root = newNode(arr[0]);
    stack<Node *> st;
    st.push(root);
    int id = 1;
    while (id < n)
    {
        int val = arr[id];
        if (val == NULL)
        {
            st.pop();
        }
        else
        {
            Node *root = newNode(val);
            Node *par = st.top();
            par *children.push_back(root);
            st.push(root);
        }
        id++;
    }
}

//  display function
void display(Node *node)
{
    string str = to_string(node->data) + "->";
    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << endl;
    for (Node *child : node->children)
    {
        display(child);
    }
}

int main()
{
    vector<int> arr;
    arr.assign({10, 20, 30, -1, 50, -1, -1, 30, 70});
    int n = arr.size();

    Node *root = constructor(arr, n);
    display(root);
}