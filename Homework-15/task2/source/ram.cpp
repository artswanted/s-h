#include "main.h"

std::string operateMemory = "11111111";

std::string loadMemCache (){
    return operateMemory;
}

void writeMemoryCache(std::string cachedMemory){
    operateMemory = cachedMemory;
}