#include <stdio.h>
#include <wchar.h> // necessary on MacOS for wprintf
#include <locale.h> // necessary on MacOS for setlocale

// Conclusion on MacOS: little difference between printf and wprintf, as long as the right format specifiers are used

int main(void)
{
    // Makes wprintf work on MacOS; see https://stackoverflow.com/a/15206743/132042
    setlocale(LC_ALL, "");
    
    char ch = 'h';
    const char *string = "computer";
  
    // Small Greek lambda
    // Same as:
    //  wchar_t wch = L'\u03BB';
    wchar_t wch_lambda = L'λ';

    // Uppercase Cyrillic letter YA
    wchar_t wch_ya = L'Я';
    
    // Original:
    // const wchar_t *wstring = L"Unicode";

    // TODO: This is UTF-32 that will not work on Windows without further changes
    // Mathematical bold small lambda
    const wchar_t *wstring_lambda = L"\u1D6CC";

    const wchar_t *wstring_nihongo = L"日本語";

    // TODO: This would work on Windows with UTF-16
    // const wchar_t *wstring = L"\uD835\uDECC";

    printf("printf (c): %c\n", ch);
    // TODO: on MacOS, printf does not recognize %hc
    printf("printf (hc): %hc\n", ch);

    // TODO: on MacOS, after setlocale, printf prints all of the below characters fine
    printf("printf YA (C): %C\n", wch_ya);
    printf("printf YA (lc): %lc\n", wch_ya);
    printf("printf lambda (C): %C\n", wch_lambda);
    printf("printf lambda (lc): %lc\n", wch_lambda);

    printf("\n");

    wprintf(L"wprintf (C): %C\n", ch);
    wprintf(L"wprintf (hc): %hc\n", ch);
    // TODO: this does not work at all on MacOS
    wprintf(L"wprintf YA (c): %c\n", wch_ya);
    // TODO: on MacOS, this prints as a question mark unless setlocale above is invoked first
    wprintf(L"wprintf YA (lc): %lc\n", wch_ya);
    // TODO: this does not print anything at all on MacOS
    wprintf(L"wprintf lambda (c): %c\n", wch_lambda);
    // TODO: on MacOS, this prints as a question mark unless setlocale above is invoked first
    wprintf(L"wprintf lambda (lc): %lc\n", wch_lambda);

    printf("\n\nStrings:\n\n");

    printf("printf (s): %s\n", string);

    // TODO: On MacOS, this generates a compiler warning, but prints fine (as the warning says, no effect)
    printf("printf (hs): %hs\n", string);
    printf("printf lambda (S): %S\n", wstring_lambda);
    printf("printf lambda (ls): %ls\n", wstring_lambda);
    printf("printf nihongo (S): %S\n", wstring_nihongo);
    printf("printf nihongo (ls): %ls\n", wstring_nihongo);
    printf("\n");

    // TODO: this does not print the string on MacOS
    wprintf(L"wprintf (S): %S\n", string);

    // OK: this prints fine on MacOS
    wprintf(L"wprintf (s): %s\n", string);

    // OK: this prints fine on MacOS
    wprintf(L"wprintf (hs): %hs\n", string);

    // TODO: this prints a letter "l" on MacOS
    wprintf(L"wprintf lambda (s): %s\n", wstring_lambda);

    // OK: this prints fine on MacOS
    wprintf(L"wprintf lambda (S): %S\n", wstring_lambda);

    // OK: this prints fine on MacOS
    wprintf(L"wprintf lambda (ls): %ls\n", wstring_lambda);

    // TODO: this doesn't print at all on MacOS
    wprintf(L"wprintf nihongo (s): %s\n", wstring_nihongo);

    // OK: this prints fine on MacOS
    wprintf(L"wprintf nihongo (S): %S\n", wstring_nihongo);

    // OK: this prints fine on MacOS
    wprintf(L"wprintf nihongo (ls): %ls\n", wstring_nihongo);
    printf("\n");
}