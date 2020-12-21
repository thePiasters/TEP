#include <iostream>
#include "CMySmartPointer.h"
#include "CTab.h"
#include "CTable.h"
#include "Derived1.h"


void v_test_smart_pointer_op_overload() {
    int *xd = new int;
    *xd = 7;
    int *test = new int;
    *test = 12;
    CMySmartPointer<int> c_test(test);
    CMySmartPointer<int> c_copy = c_test;
}


void v_test_ctab_mv_operator() {
    CTab a1, a2;
    a2.bSetSize(12);

    std::cout << "\n Moving from CTab a1 to a2...\n";
    a2 = std::move(a1); // move-assignment from xvalue
    std::cout << a2.iGetSize() << std::endl;
    if (a1.pi_tab == NULL) {
        std::cout << "A1 pi tab is NULL\n";
    }
}

void v_test_smart_pointer_with_ctab(){
    CTab  *cTab = new CTab();
    CTab *cTab2 = new CTab();
    cTab->bSetSize(12);
    std::cout<<"CREATE C_TEST ... \n\n";
    CMySmartPointer<CTab> c_test(cTab);
    CMySmartPointer<CTab> c_test_1(cTab2);
    std::cout<<"USAGE of op= ... \n\n";
    c_test = c_test_1;
    std::cout<<"CREATE C_COPY WITH CONST ... \n\n";
    CMySmartPointer<CTab> c_copy_2(c_test);
    std::cout<<c_copy_2->iGetSize()<<std::endl;
}

void v_test_catble_operator_with_ms(){
        CTable cTable1, cTable2;
        cTable1.vSetName("TABLE 1");
        cTable2.vSetName("TABLE 2");
        std::cout<<cTable1.sGetName()<<"\n";
        cTable1 + cTable2;
}

//used for downcast BASE CLASS -> DERIVED CLASS
template<class B, class D>
static CMySmartPointer<D>& my_dynamic_cast(const CMySmartPointer<B>& srcPtr){
    D* derived = dynamic_cast<D*>(srcPtr.pc_pointer);
    CMySmartPointer<D> c_smart(derived, srcPtr.pc_counter,"DERIVED POINTER");
    return c_smart;

}

void v_test_dynamic_cast(){
    Base *bp = new Derived1();
    CMySmartPointer<Base> c_test(bp,"BASE POINTER");
    my_dynamic_cast<Base,Derived1>(c_test);
}

int main() {

//    v_test_smart_pointer_op_overload();
//    v_test_ctab_mv_operator();
//    v_test_smart_pointer_with_ctab();
//    v_test_catble_operator_with_ms();
    v_test_dynamic_cast();

//    CTable cTable1, cTable2;
//    cTable2 = cTable1;


    return 0;
}
