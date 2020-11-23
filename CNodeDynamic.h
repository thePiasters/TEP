
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CNodeDynamic {
public:
    CNodeDynamic() {i_val = 0; pc_parent_node = NULL;};
    ~CNodeDynamic();
    void vSetValue(int iNewVal) {i_val = iNewVal;};
    int iGetChildrenNumber() {return(v_children.size());};
    void vAddNewChild();
    CNodeDynamic *pcGetChild(int iChildOffset);
    void vPrint() {cout << " " << i_val;};
    void vPrintAllBelow();
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
    void vClearChildren();
    void vRemovePcParentNode();


private:
    CNodeDynamic *pc_parent_node;
    vector<CNodeDynamic *> v_children;
    int i_val;

};


