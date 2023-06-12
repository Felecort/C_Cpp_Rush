
// 
struct myflags{
    unsigned io_error:1;
    unsigned seen_a_digit:1;
    unsigned had_a_eol:1;
    unsigned signaled:1;
    unsigned count:4;
};