#include <calfunction.h>



int isLeapYear( int y ){
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}
 
int leapYears( int y ){
    return y/4 - y/100 + y/400;