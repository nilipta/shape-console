#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <Menu.h>


 int _tmain(int argc, _TCHAR* argv[])
{
	Menu menu;
	menu.start();
	return 0;
}

