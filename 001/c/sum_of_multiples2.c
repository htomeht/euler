#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    int top = 999;

    int res = (floor(top/3)*(3+(floor(top/3)*3)))/2 + 
              (floor(top/5)*(5+(floor(top/5)*5)))/2 - 
              (floor(top/15)*(15+(floor(top/15)*15)))/2;
    printf("%i\n",res);
}
