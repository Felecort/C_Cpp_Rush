#include <iostream>
// #include <cstring>
using std::cout;
using std::cin;
using std::endl;

unsigned strlen(const char *str)
{
    unsigned len = 0;
    while (*str++) {
        ++len;
    }
    return len;
}


int strstr(const char *text, const char *pattern)
{
    unsigned text_len = strlen(text);
    unsigned pattern_len = strlen(pattern);
    // cout << "text len " << text_len << " Pattern len: " << pattern_len << endl;
    if (text_len < pattern_len){
        return 0;
    }
    unsigned matches = 0;
    for (unsigned i = 0; i < text_len; i++){
        matches = 0;
        for(unsigned j = 0; i < pattern_len; i++){
            if (pattern[j] != text[i + j]){
                break;
            } else {
                matches++;
            }
        }
        if (matches == pattern_len){
            return 1;
        }
    }
    return 0;
}



int main(void)
{
    char text[] = "Hello world";
    char pattern[] = "wor";
    cout << "match: " << strstr(text, pattern);

    return 0;
}