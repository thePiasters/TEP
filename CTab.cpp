#include "CTab.h"


CTab::CTab() {
    pi_tab = new int[DEF_TAB_SIZE];
    i_size = DEF_TAB_SIZE;
}

CTab::CTab(const CTab &o) { std::cout << "move failed!\n"; }

CTab::CTab(CTab &&cOther) {
    std::cout << "\n-----calllin move constructor-----\n";
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    std::cout << "MOVE ";
}

CTab& CTab::operator=(const CTab &cOther) {
    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    std::cout << "op= ";
    return (*this);
}

CTab& CTab::operator=(CTab &&cOther) {

    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    std::cout << "move assigned\n";
    return *this;
}

CTab::~CTab() {
    if (pi_tab != NULL) {
        delete pi_tab;
        std::cout << "Destr \n";
    };
}

void CTab::v_copy(const CTab &cOther) {
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int ii = 0; ii < cOther.i_size; ii++)
        pi_tab[ii] = cOther.pi_tab[ii];
}
bool CTab::bSetSize(int iTableLen) {

    if (iTableLen < 0) {
        return false;
    }
    int *table = new int[iTableLen];
    for (int i = 0; i < iTableLen; i++) {
        if (i < i_size) {
            table[i] = pi_tab[i];
        }
    }
    i_size = iTableLen;
    delete pi_tab;
    pi_tab = table;
    return true;

}
