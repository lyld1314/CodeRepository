#include <iostream>
#include <windows.h>

int main(){
    HMODULE hModule = LoadLibraryA("libmylib.dll");
 
    using myfun = void(*)();

    myfun function = (myfun)GetProcAddress(hModule, "dis");
    function();

    FreeLibrary(hModule);
    return 0;
}