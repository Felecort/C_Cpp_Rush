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
        return -1;
    }
    if((text_len == 0) && (pattern_len == 0)){
        return 0;
    }
    unsigned matches = 0;
    for (unsigned i = 0; i < text_len; i++){
        matches = 0;
        for(unsigned j = 0; j < pattern_len; j++){
            if (pattern[j] != text[i + j]){
                // cout << text[i + j] << " - " << pattern[j] << endl;
                break;
            } else {
                matches++;
                // cout << text[i + j] << " - " << pattern[j] << endl;
            }
        }
        if (matches == pattern_len){
            return i;
        }
    }
    return -1;
}

void test()
{
 (0  == strstr("","")) ? cout<<"OK : 1"<< " (" << 0 << " : " << (0  == strstr("","")) << " )" << endl : cout<< "Failed : 1"<< " (" << 0 << " : " << (0  == strstr("","")) << " )" << endl ;
  (0 == strstr("a", "")) ? cout<<"OK : 2"<< " (" << 0 << " : " <<   (0 == strstr("a", "")) << " )" << endl : cout<< "Failed : 2"<< " (" << 0 << " : " <<   (0 == strstr("a", "")) << " )" << endl ;
  (0 == strstr("a", "a")) ? cout<<"OK : 3"<< " (" << 0 << " : " <<   (0 == strstr("a", "a")) << " )" << endl : cout<< "Failed : 3"<< " (" << 0 << " : " <<   (0 == strstr("a", "a")) << " )" << endl ;
  (-1 == strstr("a", "b")) ? cout<<"OK : 4"<< " (" << -1 << " : " <<   (-1 == strstr("a", "b")) << " )" << endl : cout<< "Failed : 4"<< " (" << -1 << " : " <<   (-1 == strstr("a", "b")) << " )" << endl ;
               
  (0 == strstr("aa", "")) ? cout<<"OK : 5"<< " (" << 0 << " : " <<   (0 == strstr("aa", "")) << " )" << endl : cout<< "Failed : 5"<< " (" << 0 << " : " <<   (0 == strstr("aa", "")) << " )" << endl ;
  (0 == strstr("aa", "a")) ? cout<<"OK : 6"<< " (" << 0 << " : " <<   (0 == strstr("aa", "a")) << " )" << endl : cout<< "Failed : 6"<< " (" << 0 << " : " <<   (0 == strstr("aa", "a")) << " )" << endl ;
  (0 == strstr("ab", "a")) ? cout<<"OK : 7"<< " (" << 0 << " : " <<   (0 == strstr("ab", "a")) << " )" << endl : cout<< "Failed : 7"<< " (" << 0 << " : " <<   (0 == strstr("ab", "a")) << " )" << endl ;
  (1 == strstr("ba", "a")) ? cout<<"OK : 8"<< " (" << 1 << " : " <<   (1 == strstr("ba", "a")) << " )" << endl : cout<< "Failed : 8"<< " (" << 1 << " : " <<   (1 == strstr("ba", "a")) << " )" << endl ;
  (-1 == strstr("bb", "a")) ? cout<<"OK : 9"<< " (" << -1 << " : " <<   (-1 == strstr("bb", "a")) << " )" << endl : cout<< "Failed : 9"<< " (" << -1 << " : " <<   (-1 == strstr("bb", "a")) << " )" << endl ;
               
  (0 == strstr("aaa", "")) ? cout<<"OK : 10"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "")) << " )" << endl : cout<< "Failed : 10"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "")) << " )" << endl ;
  (0 == strstr("aaa", "a")) ? cout<<"OK : 11"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "a")) << " )" << endl : cout<< "Failed : 11"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "a")) << " )" << endl ;
  (1 == strstr("abc", "b")) ? cout<<"OK : 12"<< " (" << 1 << " : " <<   (1 == strstr("abc", "b")) << " )" << endl : cout<< "Failed : 12"<< " (" << 1 << " : " <<   (1 == strstr("abc", "b")) << " )" << endl ;
  (2 == strstr("abc", "c")) ? cout<<"OK : 13"<< " (" << 2 << " : " <<   (2 == strstr("abc", "c")) << " )" << endl : cout<< "Failed : 13"<< " (" << 2 << " : " <<   (2 == strstr("abc", "c")) << " )" << endl ;
  (-1 == strstr("abc", "d")) ? cout<<"OK : 14"<< " (" << -1 << " : " <<   (-1 == strstr("abc", "d")) << " )" << endl : cout<< "Failed : 14"<< " (" << -1 << " : " <<   (-1 == strstr("abc", "d")) << " )" << endl ;
               
  (-1 == strstr("a", "aa")) ? cout<<"OK : 15"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aa")) << " )" << endl : cout<< "Failed : 15"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aa")) << " )" << endl ;
  (-1 == strstr("a", "ba")) ? cout<<"OK : 16"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ba")) << " )" << endl : cout<< "Failed : 16"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ba")) << " )" << endl ;
  (-1 == strstr("a", "ab")) ? cout<<"OK : 17"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ab")) << " )" << endl : cout<< "Failed : 17"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ab")) << " )" << endl ;
  (-1 == strstr("a", "bb")) ? cout<<"OK : 18"<< " (" << -1 << " : " <<   (-1 == strstr("a", "bb")) << " )" << endl : cout<< "Failed : 18"<< " (" << -1 << " : " <<   (-1 == strstr("a", "bb")) << " )" << endl ;
               
  (-1 == strstr("a", "aaa")) ? cout<<"OK : 19"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aaa")) << " )" << endl : cout<< "Failed : 19"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aaa")) << " )" << endl ;
  (-1 == strstr("aa", "aaa")) ? cout<<"OK : 20"<< " (" << -1 << " : " <<   (-1 == strstr("aa", "aaa")) << " )" << endl : cout<< "Failed : 20"<< " (" << -1 << " : " <<   (-1 == strstr("aa", "aaa")) << " )" << endl ;
  (0 == strstr("aaa", "aaa")) ? cout<<"OK : 21"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "aaa")) << " )" << endl : cout<< "Failed : 21"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "aaa")) << " )" << endl ;
  (0 == strstr("aaab", "aaa")) ? cout<<"OK : 22"<< " (" << 0 << " : " <<   (0 == strstr("aaab", "aaa")) << " )" << endl : cout<< "Failed : 22"<< " (" << 0 << " : " <<   (0 == strstr("aaab", "aaa")) << " )" << endl ;
  (1 == strstr("baaa", "aaa")) ? cout<<"OK : 23"<< " (" << 1 << " : " <<   (1 == strstr("baaa", "aaa")) << " )" << endl : cout<< "Failed : 23"<< " (" << 1 << " : " <<   (1 == strstr("baaa", "aaa")) << " )" << endl ;
  (1 == strstr("baaaa", "aaa")) ? cout<<"OK : 24"<< " (" << 1 << " : " <<   (1 == strstr("baaaa", "aaa")) << " )" << endl : cout<< "Failed : 24"<< " (" << 1 << " : " <<   (1 == strstr("baaaa", "aaa")) << " )" << endl ;
  (1 == strstr("baaab", "aaa")) ? cout<<"OK : 25"<< " (" << 1 << " : " <<   (1 == strstr("baaab", "aaa")) << " )" << endl : cout<< "Failed : 25"<< " (" << 1 << " : " <<   (1 == strstr("baaab", "aaa")) << " )" << endl ;
  (-1 == strstr("abd", "abc")) ? cout<<"OK : 26"<< " (" << -1 << " : " <<   (-1 == strstr("abd", "abc")) << " )" << endl : cout<< "Failed : 26"<< " (" << -1 << " : " <<   (-1 == strstr("abd", "abc")) << " )" << endl ;
               
  (2 == strstr("ababc", "abc")) ? cout<<"OK : 27"<< " (" << 2 << " : " <<   (2 == strstr("ababc", "abc")) << " )" << endl : cout<< "Failed : 27"<< " (" << 2 << " : " <<   (2 == strstr("ababc", "abc")) << " )" << endl ;
  (3 == strstr("abdabc", "abc")) ? cout<<"OK : 28"<< " (" << 3 << " : " <<   (3 == strstr("abdabc", "abc")) << " )" << endl : cout<< "Failed : 28"<< " (" << 3 << " : " <<   (3 == strstr("abdabc", "abc")) << " )" << endl ;
  (-1  == strstr("","a")) ? cout<<"OK : 29"<< " (" << 0 << " : " << (0  == strstr("","")) << " )" << endl : cout<< "Failed : 29"<< " (" << 0 << " : " << (-1  == strstr("","")) << " )" << endl ;
}

int main(void)
{
    char text[] = "aa";
    char pattern[] = "a";
    cout << "match: " << strstr(text, pattern);
    test();
struct test{
    int ret_value;
    const char *text;
    const char *pattern;
};
test tests[] = {
        {0, "", ""}, //0
        {0, "a", ""}, //1
        {0, "a", "a"}, //2
        {-1, "a", "b"}, //3
        {0, "aa", ""}, //4
        {0, "aa", "a"}, //5
        {0, "ab", "a"}, //6
        {1, "ba", "a"}, //7
        {-1, "bb", "a"}, //8
        {0, "aaa", ""}, //9
        {0, "aaa", "a"}, //10
        {1, "abc", "b"}, //11
        {2, "abc", "c"}, //12
        {-1, "abc", "d"}, //13
        {-1, "a", "aa"}, //14
        {-1, "a", "ba"}, //15
        {-1, "a", "ab"}, //16
        {-1, "a", "bb"}, //17
        {-1, "a", "aaa"}, //18
        {-1, "aa", "aaa"}, //19
        {0, "aaa", "aaa"}, //20
        {0, "aaab", "aaa"}, //21
        {1, "baaa", "aaa"}, //22
        {1, "baaaa", "aaa"}, //23
        {1, "baaab", "aaa"}, //24
        {-1, "abd", "abc"}, //25
        {2, "ababc", "abc"}, //26
        {3, "abdabc", "abc"}, //27
        {-1, "", "a"}, //28
        {2, "asasaf", "asaf"}, //29
        {2, "ababac", "abac"} //30
};
for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
    int ret = strstr(tests[i].text, tests[i].pattern);
    (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
     cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
}
    return 0;
}