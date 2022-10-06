
// bfs -----------------------------------------------

class Solution
{
public:
    unordered_map<Node *, Node *> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy

    Node *cloneGraph(Node *node)
    {
        if (node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }

        Node *first = new Node(node->val, {}); // make a copy of first node
        mp[node] = first;

        queue<Node *> q; // For bfs, we create queue
        q.push(node);    // push into queue

        while (q.empty() == false) // until q. empty == false
        {
            Node *curr = q.front(); // extract front node
            q.pop();                // pop that from queue

            for (auto adj : curr->neighbors) // now travel in adjcant
            {
                if (mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj->val, {}); // then create copy
                    q.push(adj);                      // push nto the queue
                }

                mp[curr]->neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }

        return mp[node];
    }
};

// dfs--------------------------------------------

class Solution
{
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &mp)
    {
        Node *clone = new Node(node->val);
        mp[node] = clone;
        vector<Node *> nbrs;

        for (auto nbr : node->neighbors)
        {
            if (mp.find(nbr) != mp.end())
            {
                nbrs.push_back(mp[nbr]);
            }
            else
            {
                nbrs.push_back(dfs(nbr, mp));
            }
        }
        clone->neighbors = nbrs;
        return clone;
    }

    Node *cloneGraph(Node *node)
    {

        if (node == NULL)
            return node;

        if (node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node *, Node *> mp;
        return dfs(node, mp);
    }
};