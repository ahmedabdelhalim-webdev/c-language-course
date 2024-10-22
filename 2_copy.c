/*To create an identical copy of a string in C using dynamic memory allocation, you can use functions like `malloc` or `calloc` 
to allocate memory for the new string. Here’s an example that demonstrates this process:*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Original string
    char original[] = "Hello, World!";
    
    // Allocate memory for the copy (length of original + 1 for null terminator)
    char *copy = (char *)malloc(strlen(original) + 1);
    
    // Check if malloc succeeded
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit with error code
    }
    
    // Copy the original string to the new memory location
    strcpy(copy, original);
    
    // Print both strings
    printf("Original: %s\n", original);
    printf("Copy: %s\n", copy);
    
    // Free the allocated memory
    free(copy);
    
    return 0;
}
/*

### Explanation of the Code

1. **Include Headers:**
   - `#include <stdio.h>`: Required for input and output functions like `printf`.
   - `#include <stdlib.h>`: Required for memory allocation functions like `malloc` and `free`.
   - `#include <string.h>`: Required for string handling functions like `strlen` and `strcpy`.

2. **Original String:**
   - The original string `"Hello, World!"` is defined in the `original` array.

3. **Memory Allocation:**
   - `malloc(strlen(original) + 1)` allocates enough memory to hold a copy of the original string, including space for the null terminator (`'\0'`).
   - The return value of `malloc` is cast to `char *` and assigned to `copy`.

4. **Check Memory Allocation:**
   - If `malloc` returns `NULL`, it indicates that memory allocation failed. An error message is printed, and the program exits.

5. **Copying the String:**
   - `strcpy(copy, original)` copies the contents of `original` into the newly allocated memory pointed to by `copy`.

6. **Printing Strings:**
   - Both the original string and the copied string are printed to the console.

7. **Freeing Memory:**
   - After using the dynamically allocated memory, `free(copy)` is called to release the memory back to the system.

### Output of the Program

When you run this program, the output will be:

```
Original: Hello, World!
Copy: Hello, World!
```

### Summary

- This example demonstrates how to create a new identical copy of a string in C using dynamic memory allocation.
- Always ensure to free the allocated memory to avoid memory leaks.
- Proper error handling during memory allocation is crucial for robust programs.*/