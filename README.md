# Utilities

This repo holds several utility programs that a small simple (_even trivial_) programs that perform various tasks.  Explainations of each are outlined below.

## Convert HTML

<u>Included Files</u>:

1. convert.sh

This is a very simplistic shell script that runs against an HTML report file created by the Cellebrite tool (_Cell Phone Forensics_).  The report contains header information followed by the body in one long line.  This script simply runs `dos2unix` to convert the line endings and then uses several `sed` transformations to transform the HTML body from one long line to multiple lines split on **table** tags.

----

## Latitude/Longitude Converter

<u>Included Files</u>:

1. dms2dec.c

Currently, this is a lone source file that can be compiled by itself.  It is a very simple command line program that accepts a latitude or longitude in the **deg/min/sec** format and converts it to **decimal degress** format.  The output can then be used in Google Maps to search for a location by entering the decimal degress of the latitude followed by the longitude (_separated by a comma_).  For example:  `35.38976, -81.22439`.

----

## Exfil Application

<u>Included Files</u>:

1. utils.h  
1. utils.c  
1. test.c  
1. testfile.txt  

`test.c` is really just the main driver code.  `utils.h` and `utils.c` contain the functions leveraged in the main driver program allowing for the "_enciphering_" of the data found in `testfile.txt`, which is just a file containing test/sample data.  This code is one component of a suite of cyber camp related tools.  This intent of this application is as follows: 

1. Read a list of usernames and passwords  
1. "Encrypt" them with caesar cipher algorithm  
1. Connect to a related server program and send them over the network (think 'echo' server - receives confirmation of number sent from server)   
1. Sleeps for 5 min and repeats  


### Pseudo Code

<u>Reading List:</u>

<pre>
Open file: 
    until EOF read a line
        select next encode value
        encode line
        store into char* array
Close file  
</pre>

<u>Encode/Encrypt:</u>

**input**: line read from file, encode key value    

<pre>
until EOL read char
    Perform encode and store result  
    return string  
</pre>

<u>Connect to remote server:</u>

<pre>
Open connection  
Push all data in char* array  
</pre>

