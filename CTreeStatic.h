//
// Created by LordMordulec on 11/23/2020.
//

#ifndef LISTA3_CTREESTATIC_H
#define LISTA3_CTREESTATIC_H


#include "CNodeStatic.h"

class CTreeStatic
{
public:
    CTreeStatic(){};
    ~CTreeStatic(){};
    CNodeStatic *pcGetRoot() {return(&c_root);}
    void vPrintTree(){c_root.vPrintAllBelow();};
    void CTreeStatic::vSetRoot(CNodeStatic& root){
        c_root = root;
    }
private:
    CNodeStatic c_root;
};
//class CTreeStatic;


#endif //LISTA3_CTREESTATIC_H
