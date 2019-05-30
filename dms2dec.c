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

/* Define constants used in conversion */
#define MIN_DIVISOR 60.0
#define SEC_DIVISOR 3600.0

/********************************************************/
/* convert_mins() - Convert mins to degree decimals     */
/*                                                      */
/* - accepts: Float value representing minutes of angle */
/* - returns: Float value representing decimal value    */
/********************************************************/
float convert_mins(float b) 
{
    return (b / MIN_DIVISOR) ;
} /* End convert_mins() */

/********************************************************/
/* convert_secs() - Convert secs to degree decimals     */
/*                                                      */
/* - accepts: Float value representing seconds of angle */
/* - returns: Float value representing decimal value    */
/********************************************************/
float convert_secs(float c) 
{
    return (c / SEC_DIVISOR) ;
} /* End convert_secs */

/****************************************/
/* show_usage() - display program usage */
/****************************************/
void show_usage(char *name)
{
    printf( "Usage: %s -d <degrees> -m <minutes> -s <seconds>\n\n", name ) ;
    printf( "Where:\n" ) ;
    printf( "   -d <degrees>        Degrees of angle to convert\n" ) ;
    printf( "   -m <minutes>        Minutes of angle to convert\n" ) ;
    printf( "   -s <seconds>        Seconds of angle to convert\n\n" ) ;
    printf( "Example:\n" ) ;
    printf( "   %s -d 30 -m 15 -s 45\n", name ) ;
    printf( "   ---------------------------------------------\n" ) ;
    printf( "   Original:  30 degrees, 15 minutes, 45 seconds\n" ) ;
    printf( "   Converted: 30.262501\n\n" ) ;

    exit(1) ;
} /* End show_usage */

/**********************/
/* Main program entry */
/**********************/
int main(int argc, char *argv[]) 
{
    /* Argument count should = 7 (program name + 3 switches + 3 values) */
    if( argc != 7 ) 
        show_usage(argv[0]) ;

    /* Declare variables */
    int flag ;
    float degree = 0.0, min = 0.0, sec = 0.0, dec = 0.0 ;

    /* Process command line parameters */
    while( --argc > 0 && (*++argv)[0] == '-' ) {
        flag = *++argv[0] ;
        switch(flag) {
            case 'd':
                degree = atof(*++argv) ;
                argc-- ; 
                break ;
            case 'm':
                min = atof(*++argv) ;
                argc-- ; 
                break ;
            case 's':
                sec = atof(*++argv) ;
                argc-- ; 
                break ;
            default:
                printf("%s: Illegal Option %c\n\n", argv[0], flag) ;
                show_usage(argv[0]) ;
        }
    }

    /* Convert input from DMS to Decimal */
    dec = degree + convert_mins(min) + convert_secs(sec) ;

    /* Output results */
    printf( "%i degrees %i minutes and %i seconds converts to %f degrees decimal\n",
            (int)degree, (int)min, (int)sec, dec) ;

    return 0 ;
} /* End of Main */

