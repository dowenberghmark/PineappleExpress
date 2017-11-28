#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
#include <string.h>

using namespace std;


#define uchar unsigned char
#define uint unsigned int

void pre_process(char* element){
/*appends 1 after string*/
  int num = 1;
  uchar one;
    if(*(char *)&num == 1){   // Little-Endian
      one = 1 << 7;
    } else{  // Big-Endian
      one = 1;
    }
    int strLen = strlen(element);
    element[strLen++] = one;
    strLen--;
    uchar bytes[4];
    char l_append;
    l_append = strLen*8;

    if(*(char *)&num == 1){  // if Little-Endian
      l_append = strLen*8;
      bytes[0] = (l_append >> 24) & 0xFF;
      bytes[1] = (l_append >> 16) & 0xFF;
      bytes[2] = (l_append >> 8) & 0xFF;
      bytes[3] = l_append & 0xFF;
      element[60] = bytes[0];
      element[61] = bytes[1];
      element[62] = bytes[2];
      element[63] = bytes[3];    
    } else{} // Big-Endian
  }