#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Ensure correct argument is given
    if (argc != 2)
    {
        printf("Only accepts 1-command line argument (name of forensic image).\n");
        return 1;
    }
    
    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    
    // Buffer
    BYTE buffer[512];
    
    // Counter to count JPGS
    int count = 0;
    
    // Name of jpg will be 000.jpg\0
    char jpg[8];
    
    // Pointer
    FILE *img;
    
    while ((fread(buffer, sizeof(buffer), 1, file) == 1))
    {
        // If JPG
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (count == 0) // First JPG
            {
                //Naming jpg file
                sprintf(jpg, "%03d.jpg", count);
                count += 1;
                
                //Open jpg for writing
                img = fopen(jpg, "w");
                
                //Write
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            else    // Subsequent JPG
            {
                //Close previous file first before writing new one
                fclose(img);
                
                //Naming jpg file
                sprintf(jpg, "%03d.jpg", count);
                count += 1;
                
                //Open jpg for writing
                img = fopen(jpg, "w");
                
                //Write
                fwrite(buffer, sizeof(buffer), 1, img);
            }
        }
        // Else if not JPG
        else if (count > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }
    
    fclose(img);
    fclose(file);
    return 0;
}
