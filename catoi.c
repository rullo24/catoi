#include "catoi.h" // including header

// MAX_INT >= return >= -MAX_INT --> if fail, p_err_res deref will be set to -1
int catoi(const char *str_to_conv, size_t max_str_len, int* p_err_res) {
    // if str_len == 0 --> continue until NULL byte reached (presumption made that this exists)
    int total = 0;
    size_t true_str_len = 0;

    // // // step 1. get size of string 
    if (max_str_len == 0) { // presumption that NULL byte exists
        true_str_len = strlen(str_to_conv);
    } else { // responding to user len def
        true_str_len = strnlen(str_to_conv, max_str_len);
    }

    // // // step 2. iterate over each character in the string 

    // step 2a. checking if there are too many char indexes to be stored in an int datatype & if strlen func call is successful
    if (true_str_len == 0 || true_str_len-1 > (size_t)INT_MAX) { // used for str_index in for loop
        *p_err_res = -1;
        return 0;
    }

    double index_exp = 0; // to be defined by length through string
    for (int str_index = true_str_len-1; str_index >= 0; str_index--) { // starting from back of string --> reverse operation for correct pow() calcs
        // step 2b. iterate over each character --> check if num
        uint64_t curr_char_val = 0; // large mem size used for pow() comparison in step 2b.
        switch (str_to_conv[str_index]) {
            case '0':
                curr_char_val = 0;
                break;
            case '1':
                curr_char_val = 1;
                break;
            case '2':
                curr_char_val = 2;
                break;
            case '3':
                curr_char_val = 3;
                break;
            case '4':
                curr_char_val = 4;
                break;
            case '5':
                curr_char_val = 5;
                break;
            case '6':
                curr_char_val = 6;
                break;
            case '7':
                curr_char_val = 7;
                break;
            case '8':
                curr_char_val = 8;
                break;
            case '9':
                curr_char_val = 9;
                break;

            // the negative case
            case '-':
                // checking if the '-' is at the beginning of the string. If not, int is invalid
                if (str_index != 0) {
                    *p_err_res = -1;
                    return 0;
                }
                total *= -1; // no checks required --> all +ve ints can also be -ve ints
                return total; // total returned (check prev made that '-' is at beginning of str)

            // the invalid char case --> checking if out-of-bounds (ASCII)
            default: 
                *p_err_res = -1; // returning error flag
                return 0; // invalid number detected
        }

        // step 2c. if char is num --> find what 10^(exponent) * char_val should be
        double curr_dec_pow = pow(10.0, index_exp); // will always return a whole num
        uint64_t dec_val = (uint64_t)curr_dec_pow * curr_char_val; // uint64_t type conv will not truncate any data as whole nums are always returned by pow() in this case

        // step 2d. check that adding this num doesn't surpass the limit (causing an overflow)
        if (dec_val > (uint64_t)(INT_MAX - total)) { // the subtraction checks if there is sufficient space
            *p_err_res = -1;
            return 0;
        }

        // step 2e. if no overflow, add the value to the total
        total += (int)dec_val; // cast to int as any values > INT_MAX will have been caught by this stage

        // step 2f. ++ the exponent for the next char in the string
        index_exp++;
    }

    // // // step 3. repeat all part 2 steps for each char until end of string --> return total 
    return total;
}