typedef float _mf32 ;
typedef double _mf64 ;
typedef unsigned char _mu8 ;
typedef signed char _mi8 ;
typedef signed short _mi16 ;
typedef unsigned short _mu16 ;
typedef signed int _mi32 ;
typedef unsigned int _mu32 ;
#ifdef _WIN32
typedef signed long long _mi64 ;
typedef unsigned long long _mu64 ;
#else
typedef signed long _mi64 ;
typedef unsigned long _mu64 ;
#endif

extern _mi32 E ;
struct _myroutine_returns{_mi32   _returns_0;} ;
void myroutine(struct _myroutine_returns _returns) ;
