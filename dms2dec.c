/******************************************************************************/
/* dms2dec.c                                                                  */
/*                                                                            */
/* Program to convert Geo-coords from degrees, minutes, seconds into degree   */
/* decimal notation                                                           */
/*                                                                            */
/* Ben Wheeless                                                               */
/* 05/29/2019                                                                 */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define min_divisor 60.0
#define sec_divisor 3600.0

/* Convert mins to degree decimals */
float convert_mins(float b) {
    return (b / min_divisor) ;
} 

/* Convert secs to degree decimals */
float convert_secs(float c) {
    return (c / sec_divisor) ;
}

/* Main program entry */
int main(int argc, char *argv[]) {
    // TODO: Add command line parameter acceptance of values (-d degree, -m mins, -s secs)
    int degree = 30 ;
    float min = 15.0 ;
    float sec = 33.0 ;
    
    float dec = 0.0 ;

    /* Convert input from DMS to Decimal */
    dec = degree + convert_mins(min) + convert_secs(sec) ;

    /* Output results */
    printf( "%i degrees %i minutes and %i seconds converts to %f degrees decimal\n",
            degree, (int)min, (int)sec, dec) ;

    return 0 ;
}

