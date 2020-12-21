#include <iostream>

#define DEF_TAB_SIZE 10
class CTab {
public:

    CTab();
    CTab(const CTab& o);
    CTab(CTab&& cOther);

    CTab& operator=(CTab &&cOther);
    CTab& operator=(const CTab &cOther);
    ~CTab();

    bool bSetSize(int iNewSize);
    int iGetSize() { return(i_size); }
    void v_copy(const CTab &cOther);
    int *pi_tab;
    int i_size;

};



