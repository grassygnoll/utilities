/******************************************************************************/
/* utils.h                                                                    */
/*                                                                            */
/* Header file for utility functions involved with Cyber Camp Exfil code      */
/******************************************************************************/

#ifndef _UTILS_H_
#define _UTILS_H_

// Max character size to read as a line from given file
#define LINE_SIZE   256
// Max key size = number of letters in latin alphabet (26)
#define KEY_MAX     26
// Lower and Upper ASCII bounds for LATIN alphabet characters
#define UPPER_FLOOR     65
#define UPPER_CEIL      90
#define LOWER_FLOOR     97
#define LOWER_CEIL      122

int get_line(FILE* inFile, char* lineBuf) ;
char caesar_encode(char inChar, int shiftKey) ;

#endif

