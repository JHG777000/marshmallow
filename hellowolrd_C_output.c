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
void marshmallow_mymod_main(mi32 * returns_marshmallow_mymod_main_0)  ;
int main(int argc, const char **argv) {
mi32 returns_marshmallow_mymod_main_0 = 0 ;
marshmallow_mymod_main(&returns_marshmallow_mymod_main_0) ;
return returns_marshmallow_mymod_main_0; 
} 
mu64 marshmallow_mymod_myvar = 0xff ;
mu64 marshmallow_mymod_myvar0 ;
mu32 marshmallow_mymod_var = 5223 ;
mu32 marshmallow_mymod_var2 = 5224 ;
mu32 marshmallow_mymod_var3 = 42 ;
mu32 marshmallow_mymod_myvar1 = 07 ;
void marshmallow_mymod_main(mi32 * returns_marshmallow_mymod_main_0) {
mu32 var4 = 5224 ;
mu64 myvar = 0xff ;
mu64 i = 0 ;
mu64 j = 4 ;
mf64 x = 0.23 ;
mu64 *ptr = ((void*)0) ;
mu64 😀 = L'😀' ;
mu32 myarray[3][3] = {{7,7,7},{7,7,7},{7,7,7}} ;
mu32 myarray2[3][3] ;
mu64 myvar2 = 52 ;
marshmallow_mymod_var3=42  ;
var4=43  ;
j=(j+(i+(2/2)))  ;
j=4  ;
memcpy(myarray2,myarray, sizeof(myarray2))  ;
helloworld:  ;
if ((ptr==((void*)0))) {
puts(u8"This is null!");  ;
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
if ((myvar2=myvar)) while ((i<2)) {
myvar=(2+2)  ;
if (0) {
puts(u8"World!!!!");  ;
} else if (1) {
puts(u8"\"\"\"\'\"'");  ;
} i++  ;
}  ;
if (j) goto helloworld;  ;
(*returns_marshmallow_mymod_main_0)=0  ;
}
