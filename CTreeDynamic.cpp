#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {}

CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}
void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}

void CTreeDynamic::vSetRoot(CNodeDynamic *root) {
    pc_root = root;
}

CNodeDynamic *CTreeDynamic::pcGetRoot() {
    return pc_root;
}
bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode){
    return pc_root->bMoveSubtree(pcParentNode,pcNewChildNode);
}

