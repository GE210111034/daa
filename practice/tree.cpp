#include <bits/stdc++.h>

using namespace std;
typedef set<int> Tree;
typedef set<int>::reverse_iterator RTree;

int leafNodeCount(Tree t, int node){
    if(t.find(node) == t.end() || t.find(node * 2) == t.end() && t.find(node * 2 + 1) == t.end()) {
        return 1;
    }
    int leftCount = leafNodeCount(t, node * 2);
    int rightCount = leafNodeCount(t, node * 2 + 1);
    return leftCount + rightCount;
}

int main() {
    set<int> bst;

    // Inserting elements
    bst.insert(5);
    bst.insert(1);
    bst.insert(4);
    bst.insert(2);
    bst.insert(3);
    bst.insert(7);
    bst.insert(6);

    // for(RTree rt = bst.rbegin(); rt != bst.rend(); ++rt) cout << *rt << endl;
    // for(auto t : bst) cout << t << endl;

    cout << leafNodeCount(bst, 1);



    cout << endl;


    return 0;
}
