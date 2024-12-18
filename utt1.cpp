#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct GraphNode
{
    int val;
    vector<GraphNode *> neighbors;
    GraphNode(int x) : val(x) {}
};

void treeBFS(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

void graphBFS(GraphNode *start)
{
    if (!start)
        return;

    queue<GraphNode *> q;
    unordered_map<GraphNode *, bool> visited;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        GraphNode *node = q.front();
        q.pop();
        cout << node->val << " ";

        for (GraphNode *neighbor : node->neighbors)
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    // Tree example
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Tree BFS traversal: ";
    treeBFS(root);
    cout << endl;

    // Graph example
    GraphNode *node1 = new GraphNode(1);
    GraphNode *node2 = new GraphNode(2);
    GraphNode *node3 = new GraphNode(3);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node1);
    node3->neighbors.push_back(node2);

    cout << "Graph BFS traversal: ";
    graphBFS(node1);
    cout << endl;

    return 0;
}
