#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class CNodeStatic {
public:
    CNodeStatic() {i_val = 0; pc_parent_node = NULL;};
    ~CNodeStatic(){};
    void vSetValue(int iNewVal) {i_val = iNewVal;};
    int iGetChildrenNumber() {return(v_children.size());};
    void vAddNewChild();
    CNodeStatic *pcGetChild(int iChildOffset);
    void vPrint() {cout << " " << i_val;};
    void vPrintUp();
    void vPrintAllBelow();

private:
    vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;

};
