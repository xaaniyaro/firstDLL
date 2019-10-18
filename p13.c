#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HINSTANCE hCodigoDll;

char* bin = "1001";
char *hex = "3B";
char *dou = "-10.2";
int binToInt;
int asToInt;
double asToDouble;

typedef int(asciiHEXToInt)(char*);
typedef int(asciiBinaryToInt)(char*);
typedef double(asciiToDouble)(char*);

asciiHEXToInt* ptrHex=0;
asciiBinaryToInt* ptrBin=0;
asciiToDouble* ptrDou=0;

void LoadAndCallFunction(){
if(hCodigoDll=LoadLibrary("p9.dll")){
    if(ptrBin=(asciiBinaryToInt*)GetProcAddress(hCodigoDll,"asciiBinaryToInt")){
        binToInt = (*ptrBin)(bin);
        printf("%s binary to int %d\n", bin, binToInt);
    }
    else{
        printf("Error: routine not found");
    }
    if(ptrHex=(asciiHEXToInt*)GetProcAddress(hCodigoDll,"asciiHEXToInt")){
        asToInt = (*ptrHex)(hex);
        printf("%s HEX to int %d\n", hex, asToInt);
    }
    else{
        printf("Error: routine not found");
    }
    if(ptrDou=(asciiToDouble*)GetProcAddress(hCodigoDll,"asciiToDouble")){
        asToDouble = (*ptrDou)(dou);
        printf("%s ascii to double %f\n", dou, asToDouble);
    }
    else{
        printf("Error: routine not found");
    }
}
else{
    printf("Error: Library not found\n");
}
FreeLibrary(hCodigoDll);
}

int main(){
    LoadAndCallFunction();
    getchar();
}
