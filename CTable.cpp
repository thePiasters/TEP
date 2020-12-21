#include "CTable.h"


CTable::CTable() {
    std::cout << "bezp: " << s_name << std::endl;
    s_name = DEFAULT_NAME;
    i_table_len = DEFAULT_TABLE_LENGHT;
    pi_table = new int[i_table_len];

}

CTable::CTable(std::string sName, int iTableLen) {
    i_table_len = iTableLen;
    pi_table = new int[i_table_len];
    s_name = sName;
    std::cout << "parametr: " << s_name << std::endl;
}

CTable::CTable(CTable &pcOther) {

    std::cout << "---------------Konstruktor kopiujacy--------------------------\n";
    std::cout << "kopiuj: " << s_name << std::endl;
    s_name = pcOther.s_name + "_copy";
    i_table_len = pcOther.i_table_len;

    vAllocPiTable(this, pcOther);

    /*
    pi_table = new int[i_table_len];
    for (int i = 0; i < i_table_len; i++) {
        pi_table[i] = pcOther.pi_table[i];
    }
    */
    std::cout << "--------------------------------------------------------------\n";
}
CTable::CTable(CTable &&pcOther){
    std::cout << "\n-----calllin move constructor-----\n";
    s_name = pcOther.s_name;
    i_table_len = pcOther.i_table_len;
    pi_table = pcOther.pi_table;

    pcOther.pi_table = NULL;

}

CTable::~CTable() {
    if(pi_table!=NULL) {
        delete pi_table;
        std::cout << "Usuwam: " << s_name << std::endl;
    }
}

void CTable::vAllocPiTable(CTable *ctable1, CTable &ctable2) {

    ctable1->pi_table = new int[ctable2.i_table_len];
    for (int i = 0; i < i_table_len; i++) {
        ctable1->pi_table[i] = ctable2.pi_table[i];
    }
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

std::string CTable::sGetName(){
    return s_name;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen < 0) {
        return false;
    }
    int *table = new int[iTableLen];
    for (int i = 0; i < iTableLen; i++) {
        if (i < i_table_len) {
            table[i] = pi_table[i];
        }
    }
    i_table_len = iTableLen;
    delete pi_table;
    pi_table = table;
    return true;

}

void CTable::fill() {
    for (int i = 0; i < i_table_len; i++) {
        pi_table[i] = i + 1;
    }
}

void CTable::fillAndPrintTable(int v) {

    for (int i = 0; i < i_table_len; i++) {
        pi_table[i] = v;
    }
    for (int i = 0; i < i_table_len; i++) {
        std::cout << pi_table[i] << " ";
    }
    std::cout << std::endl;
}

void CTable::vPrintTable() {
    for (int i = 0; i < i_table_len; i++) {
        std::cout << pi_table[i] << " ";
    }
    std::cout << std::endl;
}

CTable *CTable::pcClone() {
    std::cout << "---------------Pc clone--------------------------\n";
    CTable *ctable = new CTable();
    ctable->vSetName(s_name + "_clone");
    ctable->bSetNewSize(i_table_len);
    //ctable->pi_table = new int[i_table_len];
    //for (int i = 0; i < i_table_len; i++) {
    //ctable->pi_table[i] = pi_table[i];}


    //CTable *ctable = new CTable(*this);


    vAllocPiTable(ctable, *this);
    std::cout << "-----------------------------------------------\n";

    return ctable;
    //alloc pi table
}



void CTable::vSetValueAt(int iOffset, int iNewVal) {
    if (iOffset >= 0) {
        pi_table[iOffset] = iNewVal;
    }

}

CTable CTable::operator+(CTable& cTable) {

    std::cout<<"===+ op ===\n";
    int *table = new int[cTable.i_table_len + i_table_len];
    for (int i = 0; i < i_table_len; i++) {
        table[i] = pi_table[i];
//        std::cout << pi_table[i];
    }
    for (int j = 0; j < cTable.i_table_len; j++) {
        table[i_table_len + j] = cTable.pi_table[j];
        std::cout << cTable.pi_table[j];
    }

    delete pi_table;
    pi_table = table;
    i_table_len = i_table_len + cTable.i_table_len;
    return std::move(*this);
  //  return *this; <- kostr. koppiujący
}

CTable CTable::operator=(CTable &cTable) {
    delete pi_table;
    s_name = cTable.s_name;
    i_table_len = cTable.i_table_len;
    vAllocPiTable(this, cTable);
    return std::move(*this);
}

CTable& CTable::operator>>(int k) {

    int *table = copyPiTable();

    for (int i = 0; i < i_table_len; i++) {
        pi_table[i] = table[i - k];
    }
    for (int j = 0; j < k; j++) {
        pi_table[j] = table[i_table_len + j - k];
    }
    delete table;
    return *this;

}

int*  CTable::copyPiTable() {
    int *table = new int[i_table_len];

    for (int c = 0; c < i_table_len; c++) {
        table[c] = pi_table[c];
    }
    return table;

}

CTable& CTable::operator<<(int k) {
//    int *table = new int[i_table_len];
//
//    for (int c = 0; c < i_table_len; c++) {
//        table[c] = pi_table[c];
//    }
    int *table = copyPiTable();

    for (int i = 0; i < i_table_len; i++) {
        pi_table[i] = table[i + k];
    }
    int index = 0;
    for (int j = i_table_len - k; j < i_table_len; j++) {
        pi_table[j] = table[index];
        index++;
    }
    delete table;
    return *this;
}
