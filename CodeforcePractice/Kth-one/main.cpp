#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7, p = 1e6 + 1;

struct Node
{
    int l, r, sum;
    Node *pLeft, *pRight;
    Node(){}
    Node(int a, int b, int c): 
        l(a), r(b), sum(c), pLeft(NULL), pRight(NULL){}

    void setValue(int pos, Node *p)
    {
        //cout << p->l << " " << p->r << endl;
        if (p->l > pos || p->r < pos) return;
        if (p->l == p->r) {
            if (p->sum) 
                p->sum = 0;
            else 
                p->sum = 1;
            return;
        }
        setValue(pos, p->pLeft);
        setValue(pos, p->pRight);
        p->sum = p->pLeft->sum + p->pRight->sum;
    }
    Node* build(vector<int> &a, int l, int r)
    {
        if (l == r) {
            Node *p = new Node(l, r, a[l]);
            return p;
        }
        int mid = (l + r) >> 1;
        Node *left = build(a, l, mid);
        Node *right = build(a, mid+1, r);
        Node *p = new Node(l, r, left->sum + right->sum);
        p->pLeft = left;
        p->pRight = right;
        return p;
    }
    int clim_on_IT(int k, Node *p)
    {
        if (p->l == p->r) return p->l - 1;
        if (p->pLeft->sum >= k) 
            return clim_on_IT(k, p->pLeft);
        else 
            return clim_on_IT(k - p->pLeft->sum, p->pRight);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i=1; i<=n; ++i) cin >> a[i];
    Node *root = new Node;
    root = root->build(a, 1, n);
    while (m--){
        int u, v;
        cin >> u >> v;
        if (--u) 
            cout << root->clim_on_IT(v + 1, root) << "\n";
        else 
            root->setValue(v + 1, root);
    }
    return 0;
}

