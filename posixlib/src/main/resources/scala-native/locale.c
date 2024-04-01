#if defined(SCALANATIVE_COMPILE_ALWAYS) || defined(__SCALANATIVE_POSIX_LOCALE)
#if !(defined __STDC_VERSION__) || (__STDC_VERSION__ < 201112L)
#ifndef SCALANATIVE_SUPPRESS_STRUCT_CHECK_WARNING
#warning "Size and order of C structures are not checked when -std < c11."
#endif
#else // POSIX
#include <stddef.h>
#include <locale.h>

#ifdef __APPLE__
#include <xlocale.h>
#endif // __APPLE__

// Symbolic constants

#ifndef _WIN32

// not supported on Windows
// see https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170

locale_t scalanative_lc_global_locale() { return LC_GLOBAL_LOCALE; }

int scalanative_lc_messages() { return LC_MESSAGES; }

int scalanative_lc_messages_mask() { return (1 << LC_MESSAGES); }

#endif ! _WIN32

int scalanative_lc_all_mask() { return (1 << LC_ALL); }

int scalanative_lc_collate_mask() { return (1 << LC_COLLATE); }

int scalanative_lc_ctype_mask() { return (1 << LC_CTYPE); }

int scalanative_lc_monetary_mask() { return (1 << LC_MONETARY); }

int scalanative_lc_numeric_mask() { return (1 << LC_NUMERIC); }

int scalanative_lc_time_mask() { return (1 << LC_TIME); }

#endif // POSIX
#endif
