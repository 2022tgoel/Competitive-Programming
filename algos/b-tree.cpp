#include <bits/stdc++.h>

using namespace std;
const int MAXT = 6; // 6 children 
template <typename T, typename Comp = less<T>>
struct BTree {
private: 
    struct Node {
        int n;
        bool leaf;
        T keys[MAXT+5]; //n -1 keys 
        // range 0: [x, keys[0]), range i: [keys[i-1], keys[i]) range n-1: [keys[n-2], y)  (where [x, y) is previous range)
        // for a leaf node, the keys are the actual values 
        Node* ptrs[MAXT+5];
        Node(){
            n = 1;
            leaf = true;
        }
    };
    Node* root;
    Comp comp;
    int size;

    void split_child(Node* x, int ind){
        Node* y = x->ptrs[ind]; // full child 
        assert(x->n < MAXT);
        assert(y->n == MAXT);

        int mid = (MAXT-1)/2;
        // create new node z
        Node* z = new Node();
        z->leaf = y->leaf;
        for (int i = 0; i < mid; i++){
            z->keys[i] = y->keys[mid+1+i];
            if (!z->leaf) z->ptrs[i] = y->ptrs[mid+1+i];
        }
        if (!z->leaf) z->ptrs[mid] = y->ptrs[y->n-1];
        z->n = mid+1;
        y->n = mid+1;

        for (int i = x->n-1; i >=ind; i--){
            x->keys[i+1] = x->keys[i];
            x->ptrs[i+1] = x->ptrs[i];
        }
        
        x->keys[ind] = y->keys[mid];
        x->ptrs[ind+1] = z;
        (x->n)++;
    }

    Node* split_root(){
        Node* s = new Node();
        s->leaf = false;
        s->ptrs[0] = root;
        s->n = 1;
        split_child(s, 0);
        return s;
    }

    void insert_nonfull(Node* x, T value){
        int ind  =0;
        for (;ind<(x->n-1); ind++){
            if (comp(value, x->keys[ind])) break;
        }
        if (x->leaf){
            for (int i = x->n-2; i >=ind; i--){
                x->keys[i+1] = x->keys[i];
            }
            x->keys[ind] = value;
            x->n++;
        }
        else {
            Node* y = x->ptrs[ind];
            if (y->n == MAXT) {
                split_child(x, ind);
                if (!(comp(value, x->keys[ind]))) ind++;
            }
            insert_nonfull(x->ptrs[ind], value);
        }
    }

    bool find (Node* x, T value){ // whether that value exists in the tree 
        int i  =0;
        for (;i<(x->n-1); i++){
            if (comp(value, x->keys[i])) break;
        }
        if (i > 0 && value == x->keys[i-1]) return true;
        if (x->leaf) return false;
        else return find(x->ptrs[i], value);
    }

public:
    BTree(){
        root = new Node();
        size = 0;
    }
    bool find (T value){
        return find(root, value);
    }

    void insert (T key) { // idea: can't ever descend into a full node, because what if you want to insert there
        if (root->n == MAXT){
            root = split_root();
        }
        insert_nonfull(root, key);
        size++;
    }
    
    void print_node(Node* x){
        cout << "node: " << x->leaf << " " << x->n << " keys: ";
        for (int i = 0; i < (x->n-1); i++) cout << x->keys[i] << ' ';
        cout << endl;
    }

    void print_tree(){
        queue<Node*> q; 
        q.push(root);
        while (q.size()){
            cout << "here" << endl;
            Node* cur = q.front(); q.pop();
            print_node(cur);
            if (!cur->leaf){
                for (int i = 0; i <=(cur->n-1); i++) q.push(cur->ptrs[i]);
            }
        }
        cout << "exiting" << endl;
    }
    int len(){
        return size;
    }

};


int main(){
    // solution to distinct numbers: https://cses.fi/problemset/task/1621
    BTree<int> tree; 
    // tree.insert(1);
    // tree.insert(10);
    // tree.insert(15);
    // tree.insert(4);
    // cout << tree.find(6) << endl;
    // cout << tree.find(10) << endl;
    // tree.insert(6);
    // tree.insert(7);
    // tree.print_tree();
    // cout << "here" << endl;
    // cout << tree.find(6) << endl;
    // cout << tree.find(13) << endl;
    // tree.insert(8);
    // tree.insert(9);
    // cout << tree.find(6) << endl;
    // cout << tree.find(13) << endl;
    // for (int i = 0; i < 1000; i++) {
    //     tree.insert(rand()%100);
    // }
    // tree.print();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (!tree.find(x)) tree.insert(x);
    }
    cout << tree.len() << endl;
}