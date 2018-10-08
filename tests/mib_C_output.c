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

struct myclass ; 
struct myclass { _mi32 var_a ; _mi64 var_b ; _mu64 var_c ; _mi32 var_d[10] ; } ;
struct _myroutine_returns { _mi32 _returns_0 ; _mi32 _returns_1 ; } ;
void myroutine(struct _myroutine_returns* _returns) ;
void memcpy(void *dest,void *src,_mu64 n) ;
void myroutine(struct _myroutine_returns* _returns) {
_mi32 x ;
_mi32 y ;
_mi32 V0 ;
_mi32 V1 ;
_mi32 V2 ;
V0 = 1 + x ;
V1 = y + V0 ;
x = V1 ;
V2 = x > y ;
if (V2) { ;
} else { ;
} ;
_returns->_returns_0 = 1 ;
_returns->_returns_1 = 2 ;
return ;
}
_mi32 main() {
return 0 ;
}
