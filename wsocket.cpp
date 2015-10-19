#define WIN32
#include "wsocket.hh"
static void init(void)
{

   int err = WSAStartup(MAKEWORD(2, 2), &wsa);
   if(err < 0)
   {
      puts("WSAStartup failed !");
      exit(EXIT_FAILURE);
   }
}

#endif 