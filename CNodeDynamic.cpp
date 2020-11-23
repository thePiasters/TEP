#include "CNodeDynamic.h"
using namespace std;

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *c_node_dynamic = new CNodeDynamic();
    c_node_dynamic->pc_parent_node = this;
    v_children.push_back(c_node_dynamic);
}
void CNodeDynamic::vClearChildren(){
    v_children.clear();
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    return v_children[iChildOffset];
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}
CNodeDynamic::~CNodeDynamic(){
    for (int i = 0; i < v_children.size(); i++) {
        delete v_children[i];
    }

}
bool CNodeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode){

    if(pcNewChildNode == NULL /*|| pcParentNode == NULL*/){
        return false;
    }

    //usun z wektrora rodzica
    if (pcNewChildNode->pc_parent_node != NULL) {
        std::vector<CNodeDynamic*>& myvector = pcNewChildNode->pc_parent_node->v_children;

        myvector.erase(remove(myvector.begin(), myvector.end(), pcNewChildNode), myvector.end());
    }
    pcNewChildNode->pc_parent_node = pcParentNode;
    if(pcParentNode != NULL) {
        pcParentNode->v_children.push_back(pcNewChildNode);
    }

    return true;

}

void CNodeDynamic::vRemovePcParentNode() {
    pc_parent_node = NULL;
}
