#include "TestXMLInfo.h"


#include <configurator/LXMLInfo.h>

using namespace CONFIGURATOR;

void TestXMLInfo::SetUpTestCase()
{
    PUSH();
    SET_LOGTARGET("0000 --target-file");
    //FORCE_DEBUG("SETUP");
}

void TestXMLInfo::TearDownTestCase()
{
    //FORCE_DEBUG("TEARDOWN");
    POP();
}



TEST_F(TestXMLInfo, constructor)
{
    EXPECT_THROW(LXMLInfo("gobberish1", "gibberish2"), GXmlException); // No file extension
    EXPECT_THROW(LXMLInfo("somefile.xsd", "somefile.xml"), GXmlException);// XML and XSD file in wrong order

    EXPECT_NO_THROW(LXMLInfo("somefile.xml", "somefile.xsd"));// Correct
    EXPECT_NO_THROW(LXMLInfo("somefile.XML", "somefile.XSD"));// Correct

    auto info = LXMLInfo("anotherfile.XML", "anotherfile.XSD");
    EXPECT_EQ(info.fXMLFileName, "anotherfile.XML");
    EXPECT_EQ(info.fXSDFileName, "anotherfile.XSD");
}


