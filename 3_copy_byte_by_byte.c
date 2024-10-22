#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Open source file for reading and destination file for writing
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb"); // Open in write mode

    // Check if files opened successfully
    if (src == NULL || dst == NULL) {
        fprintf(stderr, "Error opening files.\n");
        return 1;
    }

    BYTE b;

    // Read from source and write to destination
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(src);
    fclose(dst);

    return 0;
}
/*

### Step-by-Step Explanation

1. **Include Header Files**:
   ```c
   #include <stdio.h>
   #include <stdint.h>
   ```
   - `#include <stdio.h>`: This includes the Standard Input/Output library, which provides functions for file handling and console output.
   - `#include <stdint.h>`: This includes definitions for fixed-width integer types. Here, it allows the use of `uint8_t`, which represents
    an 8-bit unsigned integer.

2. **Define a New Type**:
   ```c
   typedef uint8_t BYTE;
   ```
   - This line creates an alias `BYTE` for `uint8_t`, making it easier to work with byte-sized data and improving code readability.

3. **Main Function**:
   ```c
   int main(int argc, char *argv[])
   ```
   - This defines the entry point of the program. `argc` is the count of command-line arguments, and `argv` is an array of strings 
   representing those arguments.

4. **Check Command-Line Arguments**:
   ```c
   if (argc != 3) {
       fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
       return 1;
   }
   ```
   - This block checks if exactly two arguments are provided (the source file and the destination file).
   - If not, it prints an error message to `stderr` and returns `1`, indicating an error.

5. **Open Source and Destination Files**:
   ```c
   FILE *src = fopen(argv[1], "rb");
   FILE *dst = fopen(argv[2], "wb");
   ```
   - `fopen(argv[1], "rb")`: Opens the source file (first command-line argument) in binary read mode. The file pointer `src` is used to
    read from this file.
   - `fopen(argv[2], "wb")`: Opens the destination file (second command-line argument) in binary write mode. The file pointer `dst` is 
   used to write to this file.

6. **Check if Files Opened Successfully**:
   ```c
   if (src == NULL || dst == NULL) {
       fprintf(stderr, "Error opening files.\n");
       return 1;
   }
   ```
   - This block checks if either `src` or `dst` is `NULL`, which indicates that the file opening failed (e.g., the file does not exist 
   or permissions are insufficient).
   - If either file failed to open, it prints an error message and exits with `1`.

7. **Declare a Variable to Hold Data**:
   ```c
   BYTE b;
   ```
   - This declares a variable `b` of type `BYTE` (which is an alias for `uint8_t`), intended to hold a single byte of data read from the source file.

8. **Read from Source and Write to Destination**:
   ```c
   while (fread(&b, sizeof(b), 1, src) != 0)
   {
       fwrite(&b, sizeof(b), 1, dst);
   }
   ```
   - `fread(&b, sizeof(b), 1, src)`: This reads one byte from the source file into the variable `b`. 
     - `&b`: The address of `b`, where the data will be stored.
     - `sizeof(b)`: The size of `b`, which is 1 byte.
     - `1`: The number of elements to read (1 byte in this case).
   - The `while` loop continues as long as `fread` returns a non-zero value, indicating that bytes are still being read.
   - Inside the loop, `fwrite(&b, sizeof(b), 1, dst)`: This writes the byte stored in `b` to the destination file.

9. **Close the Files**:
   ```c
   fclose(src);
   fclose(dst);
   ```
   - `fclose(src)`: Closes the source file to free resources and ensure that all data is flushed to disk.
   - `fclose(dst)`: Closes the destination file similarly.

10. **Return Statement**:
    ```c
    return 0;
    ```
    - This indicates successful completion of the program, returning `0` to the operating system.

### Summary

This code effectively implements a byte-by-byte copy of a source file to a destination file, handling potential errors 
related to command-line arguments and file operations. It demonstrates good practices such as checking for
successful file opening and ensuring that resources are properly freed by closing files.
*/