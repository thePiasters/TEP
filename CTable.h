#pragma once
#include <string>
#include <iostream>

#define DEFAULT_NAME "ctable"
#define DEFAULT_TABLE_LENGHT 5
#define TABLE_ELEMENT 1

class CTable
{

public:
    std::string s_name;
    int i_table_len;
    int *pi_table;


    CTable();
    CTable(std::string sName, int iTableLen);
    CTable(CTable &pcOther);
    CTable(CTable &&pcOther);
    ~CTable();

    void vAllocPiTable(CTable* ctable1, CTable& ctable2 );
    void fillAndPrintTable(int v);
    void fill();
    void vPrintTable();
    void vSetName(std::string sName);
    std::string sGetName();
    bool bSetNewSize(int iTableLen);
    CTable *pcClone();
    void vSetValueAt(int iOffset, int iNewVal);


    CTable operator+(CTable& cTable);


    CTable operator=(CTable& cTable);
    CTable& operator<<(int k);
    CTable& operator>>(int k);
    int* copyPiTable();
};

