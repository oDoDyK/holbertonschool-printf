<img width="50" height="100" alt="C_Programming_Language svg" src="https://github.com/user-attachments/assets/ee0969da-fbbf-4fba-b216-a3614e77aa91" /> 

/**
 * ============================================================================
 *                            Mohammed - Rinad
 * ============================================================================
 *
 *                             _printf – Custom Print Function
 * ============================================================================
 *
 * This project implements a **personalized version** of the C `printf` function
 * called _printf, which allows formatted output to the standard output (stdout).
 *
 * ----------------------------------------------------------------------------
 *                             What _printf Does
 * ----------------------------------------------------------------------------
 *
 * The _printf function interprets a **format string** and prints values accordingly.
 * It supports multiple arguments of different types using variadic functions (va_list).
 *
 * Supported Format Specifiers:
 *   - Basic types:
 *       %c    : prints a single character
 *       %s    : prints a string
 *       %d/%i : prints signed integers
 *       %%    : prints a literal percent sign
 *
 *   - Extended/custom types:
 *       %b    : prints unsigned integer in binary
 *       %u    : prints unsigned integers
 *       %o    : prints numbers in octal
 *       %x/%X : prints numbers in hexadecimal (lowercase/uppercase)
 *       %S    : prints strings and escapes non-printable characters (\xNN)
 *       %p    : prints pointer addresses
 *
 * ----------------------------------------------------------------------------
 *                             Key Features
 * ----------------------------------------------------------------------------
 *
 *   - Handles multiple arguments in a single call
 *   - Safely prints "(null)" for NULL strings
 *   - Returns the number of characters printed
 *   - Designed for simplicity, clarity, and extendability
 *
 * ----------------------------------------------------------------------------
 *                             How It Works
 * ----------------------------------------------------------------------------
 *
 *   1. Scans the format string character by character
 *   2. Detects '%' symbols and identifies the following specifier
 *   3. Retrieves the corresponding argument from the variadic list
 *   4. Formats and prints the output to stdout
 *
 * ============================================================================
 */
