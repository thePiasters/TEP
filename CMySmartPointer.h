#include "CRefCounter.h"

template<typename T>
class CMySmartPointer {
public:

    CMySmartPointer(T *pcPointer, std::string name = "") {
        s_name = name;
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }

    CMySmartPointer(T *pcPointer, CRefCounter *counter, std::string name) {
        s_name = name;
        pc_pointer = pcPointer;
        pc_counter = counter;
        pc_counter->iAdd();
    }

    CMySmartPointer(const CMySmartPointer &pcOther) {
        std::cout << "  CALLING COPY \n";
        v_copy(pcOther);
    }

    CMySmartPointer(CMySmartPointer &&pcOther) {
        std::cout << "  CALLING MOVE \n";
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        s_name = pcOther.s_name;
        pcOther.pc_pointer = NULL;
    }

    ~CMySmartPointer() {
        std::cout << "  DESTRUCTOR CALL " << s_name << " WITH COUNTER = " << pc_counter->iGet() << std::endl;
        if (pc_counter->iDec() == 0) {
            std::cout << "   DELLETING...  " << s_name << "\n";
            delete pc_pointer;
            delete pc_counter;
        }
    }

    T &operator*() { return (*pc_pointer); }

    T *operator->() { return (pc_pointer); }


    CMySmartPointer &operator=(const CMySmartPointer &pcOther) {
        std::cout << "   Operator = COUNTER VALUE: " << pc_counter->iGet() << std::endl;
        v_delete();
        v_copy(pcOther);
        return *this;
    }

    void v_copy(const CMySmartPointer &pcOther) {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }

    void v_delete() {
        if (pc_counter->iDec() == 0) {
            std::cout << "   DELLETING... \n";
            delete pc_pointer;
            delete pc_counter;
        }
    }

    CRefCounter *pc_counter;
    T *pc_pointer;
    std::string s_name;
};
