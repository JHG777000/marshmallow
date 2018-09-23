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
struct myclass { _mi32 var_a ; _mi64 var_b ; _mu64 var_c ; _mu32 var_d[10] ; } ;
extern _mi32 E ;
extern struct myclass F ;
struct _myroutine_returns { _mi32 _returns_0 ; _mi32 _returns_1 ; } ;
void myroutine(struct _myroutine_returns* _returns,_mi32 D) ;
void memcpy(void *dest,void *src,_mu64 n) ;
_mi32 E ;
struct myclass F ;
void myroutine(struct _myroutine_returns* _returns,_mi32 D) {
_mi32 A = 0 ;
_mi32 B = 0 ;
_mi32 C = 0 ;
B = F.var_a ;
A = B + C ;
_returns->_returns_0 = A ;
return ;
}
_mi32 main2(_mi32 B) {
B = B + 0 ;
return B ;
}
_mi32 main() {
_mi32 _main2_get_returns ;
struct _myroutine_returns _myroutine_get_returns ;
_mi32 A = 0 ;
_main2_get_returns = main2(0) ;
A = _main2_get_returns ;
myroutine(&_myroutine_get_returns,_main2_get_returns) ;
return _myroutine_get_returns._returns_0 ;
}
