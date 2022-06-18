// GUICringOperationsDummySequenceClass.h
// karl eirik bang fossberg
//
// Not sure about the format of the sequence, but implementing this as a
// temporary class with a GetName function.

#include <string>

class GUICringOperationsDummySequenceClass
{
public:
    GUICringOperationsDummySequenceClass(std::string name)
        : m_name(name){};
    ~GUICringOperationsDummySequenceClass(){};

    std::string GetName() const { return m_name; };

private:
    std::string m_name;
};
