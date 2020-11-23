#include "CNodeDynamic.h"


class CTreeDynamic {
public:
    CTreeDynamic();
    CTreeDynamic(CNodeDynamic *pc_root);
    ~CTreeDynamic();
    CNodeDynamic *pcGetRoot();
    void vPrintTree();
    void vSetRoot(CNodeDynamic *root);
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);


private:
    CNodeDynamic *pc_root;
};

