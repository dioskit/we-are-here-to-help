/**********************************************************************************
this code is to read a code form a file and change it to html tsxt so that we can copy past it directly
-help me imporve this code 
-also we dont want this head part and body part of html all we need is to print the porgram part nothing else

thank you commit 1.
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void copy(char *s);

int main() {
    // Open the input file in read mode
    FILE *inputFile = fopen("text.txt", "r");
    
    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Open the output file in write mode
    FILE *outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    // Write HTML header to the output file
    fprintf(outputFile, "\n <code> ");

    // Process the content of the input file
    int c;
    while ((c = fgetc(inputFile)) != EOF) {
        switch (c) {
            case '<':
                fprintf(outputFile, "&lt;");
                break;
            case '>':
                fprintf(outputFile, "&gt;");
                break;
            case '&':
                fprintf(outputFile, "&amp;");
                break;
            case '\t':
                fprintf(outputFile, "&nbsp;&nbsp;&nbsp;&nbsp;");
                break;
            case '\n':
                fprintf(outputFile, "<br>\n");
                break;
            default:
                fputc(c, outputFile);
        }
    }

    // Write HTML footer to the output file
    fprintf(outputFile, "\n </code>");

    fclose(inputFile);
    fclose(outputFile);

    printf("File successfully converted to HTML.\n");

    return 0;
}

