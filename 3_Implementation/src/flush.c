#include <calfunction.h>
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}