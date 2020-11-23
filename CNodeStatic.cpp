#include "CNodeStatic.h"
using namespace std;

void CNodeStatic::vAddNewChild(){
        CNodeStatic c_node_static;
        c_node_static.pc_parent_node = this;
        v_children.push_back(c_node_static);
}
CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset){
    return &v_children[iChildOffset];
}
void CNodeStatic::vPrintUp(){
    vPrint();
    CNodeStatic c_node_static = *this;
    while(c_node_static.pc_parent_node != NULL) {
        c_node_static = *c_node_static.pc_parent_node;
        c_node_static.vPrint();
    }

}
void CNodeStatic::vPrintAllBelow() {
    vPrint();

    for(int i=0; i<v_children.size(); i++) {
        v_children[i].vPrintAllBelow();
    }

}
