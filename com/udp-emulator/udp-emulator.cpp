
// -*- mode: c++ -*-

#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include  <kf-com/KFServerUDP.h>
#include  <kf-com/KFServerTCP.h>
#include  <kf-com/KFClientTCP.h>

#include  <kf-commands/KFArgumentPort.h>
#include  <kf-commands/KFArgumentHostName.h>
#include  <kf-commands/KFArgumentComMode.h>
#include  <cmdline/GLogApplication.h>
#include  <version-info/GVersionMenu.h>
#include  <kf-com/KFComFactory.h>
#include  <kf-commands/KFArgument.h>

#include <com/GServerUDPRelay.h>

void   start_server( const int port );


void RelaySubscriber( const string msg );


int main(int argc, const char **  argv )
{   
    GVersionMenu::Instance()->ScanArguments(argc, argv);
    KFMessageHandler::SetVerbose(true);
    SET_LOGFORMAT("--short-user");
    int port_dest = 0;
    string host;
    
    KFArgumentPort *port_arg_dest = new  KFArgumentPort( "-dest-port", &port_dest );
    KFArgumentPort *port_arg_list = new  KFArgumentPort( "-list-port", &port_dest );

    KFArgumentHostName *host_arg = new KFArgumentHostName("-dest-host", &host);


  //  eCOM_MODE com_mode = eCOM_MODE::UNKNOWN;
  //  KFArgumentComMode *com_arg = new KFArgumentComMode( &com_mode );
    
    std::shared_ptr<GLogApplication>  g =  std::make_shared<GLogApplication>();
    g->InitLogArgs();
    g->AddArgument(port_arg_dest);
    g->AddArgument(port_arg_list);
    g->AddArgument(host_arg);

    ///g->AddArgument(com_arg);
    g->ScanArguments(argc, argv);
    start_server( port_dest );
    return 0;
}



void start_server( const int port  )
{ 
    FORCE_DEBUG("starting server at port %d", port);
    std::shared_ptr<GServerUDPRelay> t  = std::make_shared<GServerUDPRelay>();
    t->RegisterSubscriber( RelaySubscriber );
    t->Open(port);
}


void 
RelaySubscriber( const string msg )
{
    std::shared_ptr<KFClientTCP> t = std::make_shared< KFClientTCP>();
    
    

    FORCE_DEBUG("Inside callback !!!!!!!!!!!!!: msg = %s", msg.c_str()  );
}