#include <stdio.h>
#include <locale.h>
// #include <libintl.h>

#define _(TXT) gettext((TXT))

int main()
{
    printf(_("Hello, wordl\n"));

    return 0;
}