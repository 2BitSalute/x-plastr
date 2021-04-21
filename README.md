# x-plastr

## What Is This?

Cross-platform examples of situations in C/C++ code involving ANSI and Unicode strings.

## Sources and References

- Microsoft:
  - [printf, _printf_l, wprintf, _wprintf_l](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l)
  - [Format specification syntax: printf and wprintf functions](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160)
- Apple:
  - [wprintf](https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/wprintf.3.html)
- Raymond Chen:
  - [The sad history of Unicode printf-style format specifiers in Visual C++](https://devblogs.microsoft.com/oldnewthing/20190830-00/?p=102823)
- MySQL:
  - [my_wc_t](https://github.com/google/mysql/blob/master/include/m_ctype.h)
  - [Unicode conversion functions](https://github.com/mysql/mysql-server/blob/8.0/strings/mb_wc.h)

## Windows UTF-8 Support

According to the [Microsoft documentation of `setlocale`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-160#utf-8-support):

> UTF-8 Support
> Starting in Windows 10 build 17134 (April 2018 Update), the Universal C Runtime supports using a UTF-8 code page. This means that char strings passed to C runtime functions will expect strings in the UTF-8 encoding. To enable UTF-8 mode, use "UTF-8" as the code page when using setlocale. For example, setlocale(LC_ALL, ".utf8") will use the current default Windows ANSI code page (ACP) for the locale and UTF-8 for the code page.

## MacOS UTF-8 Support

To list all installed locales, run `locale -a` in the terminal:

```bash
<...>
C
<...>
en_US
en_US.ISO8859-1
en_US.ISO8859-15
en_US.US-ASCII
en_US.UTF-8
<...>
POSIX
<...>
```

The only useful locale for 