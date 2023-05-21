

#include  <utilities/GCommon.h>
#include  <utilities/GLocation.h>



#define XML(s,l, m) \
if( s >= 0 ) \
{ \
   GCommon().HandleError( m, l, THROW_EXCEPTION ); \
}



#define XML_ASSERT(expr, m, l)  \
if(! (expr) ) \
{ \
   GCommon().HandleError( m, l, THROW_EXCEPTION ); \
}


