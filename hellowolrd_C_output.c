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
puts("In marshmallow you can have string literals that\n          exist on more than one line,\n          and they will printed as such!!!!!");  ;
break;default:break;}  ;
j--  ;
i=0  ;
puts("Hello");  ;
myvar='\''  ;
if ((myvar2=myvar)) while ((i<2)) {
myvar=(2+2)  ;
if (0) {
puts("World!!!!");  ;
} else if (1) {
puts("\"\"\"\'\"'");  ;
} i++  ;
}  ;
if (j) goto helloworld;  ;
(*returns_marshmallow_mymod_main_0)=0  ;
}
