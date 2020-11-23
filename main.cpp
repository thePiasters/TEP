#include <iostream>

#include "CTreeStatic.h"
#include "CTreeDynamic.h"

void vTestStaticTree() {
    CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_root.vPrintAllBelow();
    cout<<endl;
    c_root.pcGetChild(1)->pcGetChild(1)->vPrintUp();

}

void vTestDynamicTree(){
    CNodeDynamic *c_root = new CNodeDynamic();


    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root->vPrintAllBelow();
    cout<<endl;


    CNodeDynamic *c_root_1 = new CNodeDynamic();
    c_root_1->vAddNewChild();
    c_root_1->vAddNewChild();
    c_root_1->vAddNewChild();

    c_root_1->pcGetChild(0)->vSetValue(1);
    c_root_1->pcGetChild(1)->vSetValue(2);
    c_root_1->pcGetChild(2)->vSetValue(3);

    c_root_1->pcGetChild(2)->vAddNewChild();
    c_root_1->pcGetChild(2)->pcGetChild(0)->vSetValue(4);
    c_root_1->vPrintAllBelow();
    cout<<endl;

    CNodeDynamic *c_root_2 = new CNodeDynamic();
    c_root_2->vAddNewChild();
    c_root_2->vAddNewChild();
    c_root_2->vSetValue(50);
    c_root_2->pcGetChild(0)->vSetValue(54);
    c_root_2->pcGetChild(1)->vSetValue(55);

    c_root_2->pcGetChild(0)->vAddNewChild();
    c_root_2->pcGetChild(0)->vAddNewChild();
    c_root_2->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_root_2->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    c_root_2->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_root_2->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
    c_root_2->vPrintAllBelow();

    cout<<endl;
    cout<<"Move subtree \n";

    CTreeDynamic* c_tree_1 = new CTreeDynamic();
    c_tree_1->vSetRoot(c_root_1);

    CTreeDynamic* c_tree_2 = new CTreeDynamic();
    c_tree_2->vSetRoot(c_root_2);

    c_tree_1->bMoveSubtree(c_root_1->pcGetChild(2), c_root_2->pcGetChild(0));
    c_tree_1->vPrintTree();
    cout<<endl;
    c_tree_2->vPrintTree();


    delete c_root;
    delete c_tree_1;
    delete c_tree_2;
}


void vAdd(vector<CTreeDynamic*>& v_trees,CNodeDynamic *node){
    CTreeDynamic * cTreeDynamic = new CTreeDynamic();
    cTreeDynamic->vSetRoot(node);
    v_trees.push_back(cTreeDynamic);
}
void vAddAllBelow(vector<CTreeDynamic*>& v_trees,CNodeDynamic *node){
    vAdd(v_trees, node);
    for(int i =0; i<node->iGetChildrenNumber(); i++){
        vAddAllBelow(v_trees,node->pcGetChild(i));
        node->vRemovePcParentNode();
    }
    node->vClearChildren();
}


int main() {
    vTestStaticTree();
    vTestDynamicTree();

    CNodeDynamic *c_root = new CNodeDynamic();


    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    vector<CTreeDynamic*> v_trees;
    vAddAllBelow(v_trees, c_root);

    for(int i = 0; i< v_trees.size(); i++){
        v_trees[i]->vPrintTree();
        cout<<"\n";
    }


    return 0;
}
