typedef float MFloat ;
typedef double MDouble ;
typedef unsigned char MByte ;
typedef signed char MSByte ;
typedef signed short MShort ;
typedef unsigned short MUShort ;
typedef signed int MInt ;
typedef unsigned int MUInt ;
#ifdef _WIN32
typedef signed long long MLong ;
typedef unsigned long long MULong ;
#else
typedef signed long MLong ;
typedef unsigned long MULong ;
#endif

void puts(MByte *string) ;
void marshmallow_mymod_main(MInt * returns_marshmallow_mymod_main_0)  ;
int main(int argc, const char **argv) {
MInt returns_marshmallow_mymod_main_0 = 0 ;
marshmallow_mymod_main(&returns_marshmallow_mymod_main_0) ;
return returns_marshmallow_mymod_main_0; 
} 
MULong marshmallow_mymod_myvar = 0xff ;
MULong marshmallow_mymod_myvar0 ;
void marshmallow_mymod_main(MInt * returns_marshmallow_mymod_main_0) {
MULong myvar = 0xff ;
MULong i = 0 ;
MULong j = 2 ;
MInt myarray[] = {7,7,7} ;
MULong myvar2 = 0xff ;
helloworld:  ;
switch (j) {
case 0:
puts("Hello");  ;
case 1:
break;  ;
break;case 2:
puts("Hello");  ;
break;default:break;}  ;
j--  ;
i=0  ;
puts("Hello");  ;
myvar=52  ;
if (1) while ((i<2)) {
myvar=(2+2)  ;
puts("World!!!!");  ;
i++  ;
}  ;
if (j) goto helloworld;  ;
}
