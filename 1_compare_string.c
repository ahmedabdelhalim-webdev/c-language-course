/*The `strcmp` function in C is used to compare two strings. It returns:

- A negative value if the first string is less than the second string.
- Zero if both strings are equal.
- A positive value if the first string is greater than the second string.

Here's a simple example demonstrating the use of `strcmp`:

### Example Code

*/
#include <stdio.h>
#include <string.h>

int main() {
    // Declare and initialize two strings
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[] = "Hello";

    // Compare str1 and str2
    int result1 = strcmp(str1, str2);
    if (result1 < 0) {
        printf("\"%s\" is less than \"%s\"\n", str1, str2);
    } else if (result1 > 0) {
        printf("\"%s\" is greater than \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" is equal to \"%s\"\n", str1, str2);
    }

    // Compare str1 and str3
    int result2 = strcmp(str1, str3);
    if (result2 < 0) {
        printf("\"%s\" is less than \"%s\"\n", str1, str3);
    } else if (result2 > 0) {
        printf("\"%s\" is greater than \"%s\"\n", str1, str3);
    } else {
        printf("\"%s\" is equal to \"%s\"\n", str1, str3);
    }

    return 0;
}
/*

### Explanation of the Code

1. **Include Headers:**
   - `#include <stdio.h>` is included for input/output functions.
   - `#include <string.h>` is included for string handling functions like `strcmp`.

2. **String Declaration:**
   - Three strings are declared: `str1`, `str2`, and `str3`. 
   - `str1` is initialized to "Hello", `str2` to "World", and `str3` to "Hello".

3. **Comparing Strings:**
   - `strcmp(str1, str2)` compares `str1` ("Hello") with `str2` ("World").
   - The result of the comparison is stored in `result1`.
   - Depending on the value of `result1`, it prints whether `str1` is less than, greater than, or equal to `str2`.

4. **Second Comparison:**
   - `strcmp(str1, str3)` compares `str1` ("Hello") with `str3` ("Hello") and stores the result in `result2`.
   - Similar conditional checks are performed to print the appropriate message.

### Output of the Program

When you run the program, you should see output like this:

```
"Hello" is less than "World"
"Hello" is equal to "Hello"
```

### Summary

- The `strcmp` function is a straightforward way to compare strings in C.
- It returns an integer indicating the relationship between the two strings, which you can use for conditional logic in your programs.*/