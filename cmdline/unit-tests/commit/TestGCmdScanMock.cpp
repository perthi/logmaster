#include "TestGCmdScanMock.h"


#include <cmdline/GCommandLineArgument.h>
#include <cmdline/GArgumentDefinitions.h>
#include <utilities/GTokenizer.h>

using ::testing::AtLeast;





TEST(TestGCmdScanMockImpl, verify_calls)
{
    
    double f1, f2, f3 = 0;
    std::shared_ptr < GArgument> arg1 = std::make_shared < GCommandLineArgument<double> >("-fval1", &f1);
    std::shared_ptr < GArgument> arg2 = std::make_shared < GCommandLineArgument<double> >("-fval2", &f2);
    std::shared_ptr < GArgument> arg3 = std::make_shared < GCommandLineArgument<double> >("-fval3", &f3);
    arg_deque all_args = { arg1, arg2, arg3 };

///    std::shared_ptr < GCommandLineArgument<double> > arguments;
    const char* argv[4] = { 0 };
    
    
    
    TestGCmdScanMock mock;
    EXPECT_CALL(mock, Verify).Times(1);
    
    int argc = 0;
    string cmdline = "-fval1 52";


    g_tokenizer()->TokenizeCommandline(cmdline, &argc, argv, 4);

    mock.ScanArguments(argc, (const char**)argv, arg1);

    GArgumentParsed v;
    std::shared_ptr<GArgument> a;
    

    
}

