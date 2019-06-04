#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

int main(int argc, char** argv)
{
    int lines ;
    char inLine[LINE_SIZE] ;
    char *fl = argv[1] ;
    FILE* inFile = fopen(fl, "r") ;
    int keyUsed = 0 ;
    char result ;

    printf( "Filename: %s\n", fl ) ;
    printf( "--------------------------------------------------------------------------------\n" ) ;
//    while( (lines = get_line(inFile, inLine)) > 0 )
    while( lines = get_line(inFile, inLine) )
    {
        // key = 0 results in no shift, start with 1 and beware of upper bound
        if(++keyUsed == KEY_MAX)
            keyUsed = 1 ;

        printf("Use key: %i\tLines read: %i\tLine: %s\n", keyUsed, lines, inLine) ;
        for(int i = 0; i < strlen(inLine); i++)
            result = caesar_encode(inLine[i], keyUsed) ;
    }

    fclose(inFile) ;
    return 0 ;
}

