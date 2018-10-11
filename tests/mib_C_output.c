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
struct _other_routine_returns { _mi32 _returns_0 ; _mi32 _returns_1 ; _mi32 _returns_2 ; _mi32 _returns_3 ; _mi32 _returns_4[10] ; } ;
void other_routine(struct _other_routine_returns* _returns,_mi32 A,_mi32 B,_mi32 C,_mi32 D) ;
struct _myroutine_returns { _mi32 _returns_0 ; _mi32 _returns_1 ; } ;
void myroutine(struct _myroutine_returns* _returns) ;
void memcpy(void *dest,void *src,_mu64 n) ;
void other_routine(struct _other_routine_returns* _returns,_mi32 A,_mi32 B,_mi32 C,_mi32 D) {
_mi32 E[10] ;
_mi32 _V0 ;
_mi32 _V1 ;
if (A) { ;
loop: ;
_V0 = A < B ;
if (_V0) { ;
_V1 = A + B ;
A = _V1 ;
goto loop ;
} ;
} ;
_returns->_returns_0 = A ;
_returns->_returns_1 = B ;
_returns->_returns_2 = C ;
_returns->_returns_3 = D ;
memcpy(_returns->_returns_4,E,sizeof(E)) ;
return ;
}
void myroutine(struct _myroutine_returns* _returns) {
struct _other_routine_returns _other_routine_get_returns ;
_mi32 x = 0 ;
_mi32 y = 0 ;
_mi32 z = 0 ;
_mi32 z2 = 0 ;
_mi32 z3 = 0 ;
_mi32 z4 = 0 ;
_mi32 _V0 ;
_mi32 _V1 ;
_mi32 _V2 ;
_mi32 _V3 ;
_mi32 _V4 ;
_mi32 _V5 ;
other_routine(&_other_routine_get_returns,1,2,x,y) ;
z = _other_routine_get_returns._returns_0 ;
z2 = _other_routine_get_returns._returns_1 ;
z3 = _other_routine_get_returns._returns_2 ;
z4 = _other_routine_get_returns._returns_3 ;
switch (z) { ;
case 1: ;
_V0 = z2 * z ;
break ;
case 2: ;
_V1 = z2 / z ;
break ;
default: ;
_V2 = z2 % z ;
break ;
} ;
_V3 = 1 + x ;
_V4 = y + _V3 ;
x = _V4 ;
_V5 = x > y ;
if (_V5) { ;
} else { ;
} ;
_returns->_returns_0 = 1 ;
_returns->_returns_1 = 2 ;
return ;
}
_mi32 main() {
struct _myroutine_returns _myroutine_get_returns ;
myroutine(&_myroutine_get_returns) ;
return 0 ;
}
