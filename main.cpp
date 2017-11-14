#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wolf_config.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

using namespace std;
int main(int argc, char *argv[]){
    if (argc < 2)
    {
        fprintf(stdout, "%s Version %d.%d\n", argv[0], wolf_VERSION_MAJOR, wolf_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
    double outputValue = mysqrt(inputValue);
#else
    double outputValue = sqrt(inputValue);
#endif
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}