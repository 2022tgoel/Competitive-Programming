#include <bits/stdc++.h>
#include <stdlib.h> 
using namespace std; 


template <typename T, typename Comp = less<T>>
struct SplayTree {
private: 
    struct Node {
        Node *left, *right, *parent;
        T key;
        Node(T k){
            left, right, parent = nullptr;
            key = k;
        }
    };

    enum dir {L, R}; // left and right 
    Comp comp;
    Node *root = nullptr;

    dir which_child(Node *node){ 
        Node *x = node->parent;
        if (x->left == node) return L;
        else return R;
    }
    
    void upd(Node *p, Node *c, dir d){
        if (d==L){
            p->left = c;
            if (c) p->left->parent = p;
        }
        else{
            p->right = c; 
            if (c) p->right->parent = p;
        }
    }

    void single_rotate(Node *x){
        Node *y = x->parent;
        Node *a = x->parent->parent;
        dir d;
        if (a) d = which_child(y);
        if (which_child(x)==L){
            upd(y, x->right, L);
            upd(x, y, R);
        }
        else{
            upd(y, x->left, R);
            upd(x, y, L);
        }
        // cout << x->left->key << endl;
        if (a) upd(a, x, d);
        else x->parent = nullptr;
    }

    void zig_zig(Node *x){
        Node *y = x->parent;
        Node *z = y->parent;
        Node *a = z->parent;
        dir d;
        if (a) d = which_child(z);
        if (which_child(x)==L){
            upd(z, y->right, L);
            upd(y, z, R);
            upd(y, x->right, L);
            upd(x, y, R);
        }
        else {
            upd(z, y->left, R);
            upd(y, z, L);
            upd(y, x->left, R);
            upd(x, y, L);
        }
        if (a) upd(a, x, d);
        else x->parent = nullptr;
    }

    void double_rotate(Node *x){
        Node *y = x->parent;
        Node *z = y->parent;
        if (which_child(x)!=which_child(y)){
            // zig-zag or zag-zig rotation, which is equivalent to two single rotations
            single_rotate(x); single_rotate(x);
        }
        else zig_zig(x);
    }

    void splay(Node *x){
        while(x->parent) {
            Node *y = x->parent;
            if (!y->parent){
                single_rotate(x); // too close to root to do double rotations
            }
            else double_rotate(x);
        }
        root = x;
    }
public:
    void insert(T key){
        Node *node = new Node(key);
        if (root == nullptr) {
            root = node; return;
        }
        Node *x = root;
        Node *p = nullptr;
        while (x){
            p = x;
            x = (comp(key, x->key) ? x->left : x->right);
        }
        // cout << "--here2--" << endl;
        upd(p, node, (comp(key, p->key) ? L : R));
        splay(node);
    }

    Node* find(T key){
        Node *x = root;
        while(x) {
            if (x->key == key) return x;
            x =(comp(key, x->key) ? x->left : x->right);
        }
        return nullptr;
    }

    // Node* erase(T key){
    //     Node *x = find(key);
    //     if (x){
    //         splay(x);

    //     }
    // }

    int size(){
        queue<Node*> q;
        q.push(root);
        int s = 0;
        while (!q.empty()){
            Node *x= q.front(); q.pop(); s++;
            if (x->left) {
                q.push(x->left);
            }
            if (x->right) {
                q.push(x->right);
            }
        }
        return s;
    }

    void print(){
        //BFS-style
        queue<Node*> q;
        q.push(root);
        cout << "--printing--" << endl;
        while (!q.empty()){
            Node *x= q.front(); q.pop();
            cout << "node val: " << x->key;
            if (x->left) {
                cout << " left: " << x->left->key;
                q.push(x->left);
            }
            if (x->right) {
                cout << " right: " << x->right->key;
                q.push(x->right);
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }

};

int main(){
    // solution to distinct numbers: https://cses.fi/problemset/task/1621
    SplayTree<int> tree; 
    // tree.insert(1);
    // tree.insert(10);
    // tree.insert(15);
    // tree.insert(4);
    // tree.insert(6);
    // tree.print();
    // for (int i = 0; i < 15; i++) {
    //     tree.insert(rand()%100);
    // }
    // tree.print();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (!tree.find(x)) tree.insert(x);
    }
    cout << tree.size() << endl;
}