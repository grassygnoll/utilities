/******************************************************************************/
/* utils.c                                                                    */
/*                                                                            */
/* Implementation of utility functions involved with Cyber Camp Exfile code   */
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "utils.h"

/******************************************************************************/
/* get_line() - get next non-blank line of input from file                    */
/*            - if line is blank, it is skipped. if line starts with '#' it   */
/*              is considered a comment line and is skipped.                  */
/*            - Param1 = file to read from                                    */
/*            - Param2 = buffer to store string (buffer must be LINE_SIZE     */
/*              characters long.                                              */
/******************************************************************************/
int get_line(FILE* inFile, char* lineBuf)
{
    char temp[LINE_SIZE] ;
    int nbrLines = 0 ;
    int lineLen ; 

    // Read a non-comment, non-blank line from input file
    do
    {
        if (!fgets(temp, LINE_SIZE, inFile))
            return 0 ;
        nbrLines++ ;
    } while (*temp == '#' || *temp == '\n' || *temp == '\r') ;

    // OK, now chomp the line ending off the line
    lineLen = strlen(temp) ;
    while (lineLen > 0 && (temp[lineLen - 1] == '\n' || temp[lineLen - 1] == '\r'))
        temp[--lineLen] = '\0' ;

    strcpy(lineBuf, temp) ;
    return nbrLines ;
}

/******************************************************************************/
/* caesar_encode() - accept input character and key value, perform shift      */
/*                   based on key and return resulting character.             */
/*                 - Param1 = input character to encrypt                      */
/*                 - Param2 = key value                                       */
/******************************************************************************/
char caesar_encode(char inChar, int shiftKey)
{
    char x ;

    if(inChar >= UPPER_FLOOR && inChar <= UPPER_CEIL)
    {
        if( (inChar + shiftKey) > UPPER_CEIL )
            x = (UPPER_FLOOR - 1) + ((inChar + shiftKey) % UPPER_CEIL) ;
        else
            x = inChar + shiftKey ;

        // Debug print
        printf( "Shift %c by: %i\tResult: %c\n", inChar, shiftKey, x ) ;
    }
    else if(inChar >= LOWER_FLOOR && inChar <= LOWER_CEIL)
    {
        if( (inChar + shiftKey) > LOWER_CEIL ) 
            x = (LOWER_FLOOR - 1) + ((inChar + shiftKey) % LOWER_CEIL) ;
        else
            x = inChar + shiftKey ;

        // Debug print
        printf( "Shift %c by: %i\tResult: %c\n", inChar, shiftKey, x ) ;
    }
    else
    {
        x = inChar ;
        // Debug print
        printf( "No shift\tResult: %c\n", x ) ;
    }

    return x ;
}

