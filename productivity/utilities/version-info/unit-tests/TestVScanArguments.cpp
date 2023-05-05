

#include "TestVScanArguments.h"

#include <utilities/version-info/VScanArguments.h>
#include <utilities/version-info/VScanArguments.cpp>
#include <utilities/version-info/external_includes.h>



void 
TestVScanArguments::SetUpTestCase()
{
	LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
	PUSH();
	SET_LOGTARGET("0000 --target-file");
	FORCE_DEBUG("SETUP");
}


void TestVScanArguments::TearDownTestCase()
{
	FORCE_DEBUG("TEARDOWN");
	POP();
}



TEST_F(TestVScanArguments, empty)
{
	auto s = VScanArguments();
	s.EnableForceOptional();

	try
	{
		VParameters scanned = s.Scan("");
		EXPECT_EQ(scanned.fCompany, "");
		EXPECT_EQ(scanned.fCompileflags_file, "");
		EXPECT_EQ(scanned.fCompileinfo, "");
		EXPECT_EQ(scanned.fConfiguration, "");
		EXPECT_EQ(scanned.fCopyright, "");
		EXPECT_EQ(scanned.fDescription, "");
		EXPECT_EQ(scanned.fAppName, "");
		EXPECT_EQ(scanned.fPlatform, "");
		EXPECT_EQ(scanned.fProductname, "");
		EXPECT_EQ(scanned.fRCFilename, "");
	}
	catch (GException& e)
	{
		CERR << e.what() << ENDL;
	}
	catch (std::exception& e)
	{
		CERR << e.what() << ENDL;
	}
	catch (...)
	{
		CERR << "Unknown exception" << ENDL;
	}
}



TEST_F(TestVScanArguments, scan)
{
	auto s = VScanArguments();
	s.EnableForceOptional();

	EXPECT_EQ(s.Scan( "-rcname myrcfile.rc").fRCFilename, "myrcfile.rc");
	EXPECT_EQ(s.Scan("-appname  mydll.dll").fAppName, "mydll.dll");
	EXPECT_EQ(s.Scan("-product myproduct").fProductname, "myproduct");

	EXPECT_EQ(s.Scan("-desc  mydescription").fDescription, "mydescription");
//	EXPECT_EQ(s.Scan("-copyright COPY").fCopyright, "COPY");
	EXPECT_EQ(s.Scan("-flagfile flagfile.txt").fCompileflags_file, "flagfile.txt");
	EXPECT_EQ(s.Scan("-exename foo.exe").fAppName, "foo.exe");
}


TEST_F(TestVScanArguments, missing_mandatory)
{
	auto s = VScanArguments();
	/// Legal parameters, but one oer more mandatry arguments missing
	EXPECT_ANY_THROW(s.Scan("-rcname myrcfile.rc"));
	EXPECT_ANY_THROW(s.Scan("-product myproduyt"));
	EXPECT_ANY_THROW(s.Scan("-desc  mydescription"));
//	EXPECT_ANY_THROW(s.Scan("-copyright COPY"));
	EXPECT_ANY_THROW(s.Scan("-flagfile flagfile.txt"));
	EXPECT_ANY_THROW(s.Scan("-appname foo.exe"));
}



TEST_F(TestVScanArguments, no_nargs)
{
	auto s = VScanArguments();
	EXPECT_ANY_THROW(s.Scan("")); /// all mandatory arguments missing
	s.EnableForceOptional();
	EXPECT_NO_THROW(s.Scan(""));
}



TEST_F(TestVScanArguments, inorrect_nargs)
{
	auto s = VScanArguments();
	s.EnableForceOptional();
	EXPECT_ANY_THROW(s.Scan("-rcname myrcfile.rc  myrcfile2.rc"));
	EXPECT_ANY_THROW(s.Scan("-rcname"));
	EXPECT_ANY_THROW(s.Scan("-appname  mydll.dll   mydll2.dll"));
	EXPECT_ANY_THROW(s.Scan("-appname "));
	EXPECT_ANY_THROW(s.Scan("-product  product1 product2"));
	EXPECT_ANY_THROW(s.Scan("-product"));
	EXPECT_ANY_THROW(s.Scan("-desc  mydescription1 loremipsum"));
	EXPECT_ANY_THROW(s.Scan("-desc"));
//	EXPECT_ANY_THROW(s.Scan("-copyright COPY1 COPY2"));
//	EXPECT_ANY_THROW(s.Scan("-copyright"));
	EXPECT_ANY_THROW(s.Scan("-flagfile flagfile1.txt flagfile2.txt "));
	EXPECT_ANY_THROW(s.Scan("-flagfile"));
}


TEST_F(TestVScanArguments, invalid_arg)
{
	auto s = VScanArguments();
	s.EnableForceOptional();
	EXPECT_ANY_THROW(s.Scan("-gibberish"));
}



#ifdef _WIN32
TEST_F(TestVScanArguments, illegal_values)
{
	auto s = VScanArguments();
	s.EnableForceOptional();
	EXPECT_ANY_THROW(s.Scan("-dllname  crap")); // Illegal DLL name on windows, must end with .dll 
	EXPECT_ANY_THROW(s.Scan("-exename blahh")); // Illegal exe name on windows, must end with.exe
}
#endif


