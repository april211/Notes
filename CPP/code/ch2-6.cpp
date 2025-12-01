#include <iostream>

/* Be careful with macros (plain text substitution)!*/

/* Rule: Variables and functions are snake_case or camelCase. Macros are UPPER_CASE_SNAKE. */
#define SQUARE_WTOP(x) x * x
#define SQUARE_WTP(x) ((x) * (x))

#define LOG_ERROR_WTOW(msg)  std::cout << "Error: "; std::cout << msg << std::endl
#define LOG_ERROR_WTW(msg) \
    do { \
        std::cout << "Error: "; \
        std::cout << msg << std::endl; \
    } while (0)             // Note: w/o semicolon `;`!

#define MAX(a, b) ((a) > (b) ? (a) : (b))




void initialize_settings() {
    // In C++, variables created here die at the closing brace '}'.
    int local_variable = 100;
    
    // BUT, let's define a preprocessor variable here.
    // The preprocessor doesn't care about the '{' or '}' braces.
    #define MY_MACRO 42
}

void do_calculation() {
    // If this were a C++ variable, this would be an error:
    // "error: 'local_variable' was not declared in this scope"
    // std::cout << local_variable; // This would fail.

    // HOWEVER, the preprocessor variable is still alive and global!
    // The preprocessor replaces "MY_MACRO" with "42" before the compiler runs.
    std::cout << "The value is: " << MY_MACRO << std::endl;
}




int main() {

    /* 1. Variable scope */
    /* Note: even if `initialize_settings` is not executed, `MY_MACRO` will still be defined!!*/
    // initialize_settings();

    do_calculation();

    /* 2. Expression: direct substitution */
    std::cout << SQUARE_WTOP(1 + 2) << std::endl;
    std::cout << SQUARE_WTP(1 + 2) << std::endl;

    /* 3. Statement guarding */
    if (false) 
        LOG_ERROR_WTOW("This msg will be shown in the console!");          // note: some parts of macro expansion are not guarded by this ‘if’ clause

    if (false)
        LOG_ERROR_WTW("This msg will NOT be shown in the console!");

    /* 4. Double Expansion: MAX(i, ++j) -> ((a) > (++j) ? (a) : (++j))
     * Best Practice: Never call macros with ++, --, or function calls that change state. */
    int i = 5;
    int j = 4;
    std::cout << MAX(i, j++) << std::endl;          // Note: Post-increment increases `j` *after* the expresion is evaluated
    std::cout << j << std::endl;                    // (i) > (j++) -> i, `j` is increased by 1 during the evaluation -> j == 5

    i = 5;
    j = 4;
    std::cout << MAX(i, ++j) << std::endl;          // Note: Pre-increment increases `j` *before* the expresion is evaluated
    std::cout << j << std::endl;                    // (i) <= (++j) -> ++j, `j` is increased by 2 during the evaluation -> j == 6

    /* Since macros are global, they pollute the entire namespace. */
    /* Clean Up: If you define a macro inside a .cpp file just to save typing for a few lines of code, 
     * use #undef immediately after you are done.*/
    #undef MAX
    // std::cout << MAX(i, ++j) << std::endl;          // illegal: identifier "MAX" is undefined


    return 0;
}
