typedef float mf32 ;
typedef double mf64 ;
typedef unsigned char mu8 ;
typedef signed char mi8 ;
typedef signed short mi16 ;
typedef unsigned short mu16 ;
typedef signed int mi32 ;
typedef unsigned int mu32 ;
#ifdef _WIN32
typedef signed long long mi64 ;
typedef unsigned long long mu64 ;
#else
typedef signed long mi64 ;
typedef unsigned long mu64 ;
#endif
void* memcpy(void* dest, const void* src, mu64 n) ;
void puts(mu8 *string) ;
mi32  main()  ;
mu64 marshmallow_mymod_myvar = 0xff ;
mu64 marshmallow_mymod_myvar0 = 0 ;
mi64 marshmallow_mymod_var64 = 64 ;
mu32 marshmallow_mymod_var = -5223 ;
mu32 marshmallow_mymod_var2 = -5222 ;
mu32 marshmallow_mymod_var3 = 42 ;
mu32 marshmallow_mymod_var4 = 24 ;
mu32 marshmallow_mymod_var300 = -5223 ;
mi32 marshmallow_mymod_var303 = 0 ;
mi32 *marshmallow_mymod_var301 = ((void*)0) ;
mu32 marshmallow_mymod_myvar1 = 07 ;
mi32 marshmallow_mymod_myvar3 = -62 ;
mu32* marshmallow_mymod_test = U"Hello World\n" ;
mu32* marshmallow_mymod_test2 = ((void*)0) ;
mi32 marshmallow_mymod_myarray42[3][3] = {{7,7,7},{7,7,7},{7,7,7}} ;
mi32  main() {
mi32 var999 = ((mi32 )0) ;
mi32 myarray43[3][3] ;
mi32 *var555 = (&marshmallow_mymod_var303) ;
mu32 var4 = -5222 ;
mu64 myvar = 0xff ;
mi64 i = 0 ;
mi64 j = 4 ;
mf64 x = 0.23 ;
mu64 *ptr = ((void*)0) ;
mf32 root = 2.f ;
mf32 q = root ;
mi32 z = (*(mi32 *)&q) ;
mu64 😀 = L'😀' ;
mi32 myarray[3][3] = {{7,7,7},{7,7,7},{7,7,7}} ;
mi32 myarray2[3][3] = {0} ;
mi32 myarray3[3][3] ;
mi64 myvar2 = 52 ;
memcpy(myarray3,myarray, sizeof(myarray3))  ;
memcpy(myarray43,marshmallow_mymod_myarray42, sizeof(myarray43))  ;
var4=marshmallow_mymod_var300  ;
marshmallow_mymod_var301=(&marshmallow_mymod_var303)  ;
((*marshmallow_mymod_var301)=0)  ;
marshmallow_mymod_myvar3=(-07)  ;
marshmallow_mymod_var3=42  ;
var4=42  ;
j=(j+(i+(2/2)))  ;
j=((mi64 )marshmallow_mymod_myvar3)  ;
j=((mi64 )marshmallow_mymod_var64)  ;
marshmallow_mymod_var64=((mi64 )((mi64 )((mi64 )((mi64 )((mi64 )j)))))  ;
z=((mi32 )(0x5f3759df-(z>>1)))  ;
q=(*(mf32 *)&z)  ;
q=(q*(1.5f-((0.5f*root)*(q*q))))  ;
root=(root*q)  ;
if ((root==1.41386008f)) {
puts(u8"yes!!!");  ;
} j=4  ;
memcpy(myarray2,myarray, sizeof(myarray2))  ;
helloworld:  ;
if ((ptr==((void*)0))) {
puts(u8"This is null!");  ;
} ptr=((mu64 *)(&j))  ;
i=((mi64 )(*ptr))  ;
if ((i==j)) {
puts(u8"i is j!");  ;
} switch ((j+0)) {
case 1:
puts(u8"Hi,");  ;
case 2:
  ;
puts(u8"Bye.");  ;
case 4:
  ;
puts(u8"Not.");  ;
break;case 3:
puts(u8"In marshmallow y😀u can have string literals that\n          exist on more than one line,\n          and they will be printed as such!!!!!");  ;
break;default:break;}  ;
j--  ;
i=0  ;
puts(u8"Hello.");  ;
myvar=L'\''  ;
if ((myvar2=((mi64 )myvar))) while ((i<2)) {
myvar=(2+2)  ;
if (0) {
puts(u8"World!!!!");  ;
} else if (1) {
puts(u8"\"\"\"\'\"'");  ;
} i++  ;
}  ;
if (j) goto helloworld;  ;
return 0  ;
}
