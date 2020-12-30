#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7, p = 1e6 + 1;

struct Node
{
    int l, r, value;
    Node *pLeft, *pRight;
    Node(){}
    Node(int a, int b, int c): 
        l(a), r(b), value(c), pLeft(NULL), pRight(NULL){}

    void setValue(int pos, int val, Node *p)
    {
        if (p->l > pos || p->r < pos) return;
        if (p->l == p->r) {
            p->value = val;
            return;
        }
        setValue(pos, val, p->pLeft);
        setValue(pos, val, p->pRight);
        p->value = max(p->pLeft->value, p->pRight->value);
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
        Node *p = new Node(l, r, max(left->value ,right->value));
        p->pLeft = left;
        p->pRight = right;
        return p;
    }
    int climb_on_IT(int val, int l, bool ok, Node *p)
    {
        //cout << p->l << " " << p->r << " " << p->value << " " << ok << endl;
        if (!p || val > p->value || p->r < l) return 1e9;
        if (p->l == p->r) return p->l-1;
        if (ok) {
            if (p->pLeft->value >= val) 
                return climb_on_IT(val, l, 1, p->pLeft);
            else return climb_on_IT(val, l, 1, p->pRight);
        } else {
            int mid = (p->l + p->r) >> 1;
            return min(climb_on_IT(val, l, 0, p->pLeft), climb_on_IT(val, l, ok || (l <= mid + 1), p->pRight));
        }
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
        int type, u, v;
        cin >> type;
        if (--type) {
            cin >> u >> v;
            if (root->value < u) 
                cout << -1 << "\n";
            else {
                int ans = root->climb_on_IT(u, v + 1, 0, root);
                if (ans == 1e9) ans = -1;
                cout << ans << "\n";
            }
        }
        else {
            cin >> u >> v;
            root->setValue(u + 1, v, root);
        }
    }
    return 0;
}

