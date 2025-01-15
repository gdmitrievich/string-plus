#include "s21_string.h"

#if defined(__APPLE__)
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "

static const char *errorList[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};

#elif defined(__linux__)
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#define ERROR "Unknown error "

static const char *errorList[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#endif

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *result = S21_NULL;
  if (str) {
    unsigned char *ch = (unsigned char *)str;
    int flag = 0;
    while (n > 0 && flag == 0) {
      if (*ch == c) {
        result = ch;
        flag = 1;
      }
      ch += 1;
      n -= 1;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ch_1 = (const unsigned char *)str1;
  const unsigned char *ch_2 = (const unsigned char *)str2;

  int result = 0;
  int flag = 0;
  while (n > 0 && !flag) {
    if (*ch_1 != *ch_2) {
      result = *ch_1 - *ch_2;
      flag = 1;
    }
    ch_1 += 1;
    ch_2 += 1;
    n -= 1;
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    s[i] = (unsigned char)c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest_new = dest;
  while (*dest != '\0') {
    dest += 1;
  }

  s21_size_t i = 0;
  while (i < n && *src != '\0') {
    *dest = *src;
    dest += 1;
    src += 1;
    i += 1;
  }
  *dest = '\0';
  return dest_new;
}

char *s21_strchr(const char *str, int c) {
  const char *res = S21_NULL;
  if (str) {
    int flag = 0;
    while (*str != '\0' && flag == 0) {
      if (*str == (char)c) {
        res = str;
        flag = 1;
      }
      str += 1;
    }

    if (c == '\0') {
      res = str;
    }
  }
  return (char *)res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  int flag = 0;
  while (!flag && n > 0) {
    if (*str1 != *str2) {
      result = *str1 - *str2;
      flag = 1;
    }
    if (!flag && *str1 == '\0') {
      result = 0;
      flag = 1;
    }
    str1 += 1;
    str2 += 1;
    n -= 1;
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i += 1;
  }

  while (i < n) {
    dest[i] = '\0';
    i += 1;
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  const char *b = str1;
  int flag = 0;

  while (!flag && *b) {
    const char *a = str2;
    int found = 0;

    while (!flag && *a) {
      if (*b == *a && !flag) {
        found = 1;
        flag = 1;
      }
      a += 1;
    }

    if (found) {
      flag = 1;
    } else {
      count += 1;
    }
    b += 1;
  }

  return count;
}

char *s21_strerror(int errnum) {
  static char result[512] = {'\0'};

  if (errnum <= MIN_ERRLIST || errnum >= MAX_ERRLIST) {
    s21_sprintf(result, "%s%d", ERROR, errnum);
  } else {
    s21_size_t err_length = s21_strlen(errorList[errnum]);
    s21_strncpy(result, errorList[errnum], err_length + 1);
  }

  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  const char *a = str;
  while (*a != '\0') {
    count += 1;
    a += 1;
  }
  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = !str1 || !str2;
  char *result = S21_NULL;
  while (!flag && *str1) {
    const char *temp = str2;
    while (*temp && flag == 0) {
      if (*str1 == *temp) {
        flag = 1;
        result = (char *)str1;
      }
      temp += 1;
    }
    str1 += 1;
  }

  return result;
}

char *s21_strrchr(const char *str, int c) {
  const char *res = S21_NULL;
  if (str) {
    while (*str != '\0') {
      if (*str == (char)c) {
        res = str;
      }
      str += 1;
    }
    if (c == '\0') {
      res = str;
    }
  }
  return (char *)res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int flag = 0;
  char *result = S21_NULL;
  if (*needle == '\0') {
    result = (char *)haystack;
    flag = 1;
  }
  if (!flag) {
    while (flag == 0 && *haystack) {
      const char *h = haystack;
      const char *n = needle;
      while (*h && *n && (*h == *n)) {
        h += 1;
        n += 1;
      }
      if (*n == '\0') {
        flag = 1;
        result = (char *)haystack;
      }
      haystack += 1;
    }
  }
  return result;
}
char *s21_strtok(char *str, const char *delim) {
  static char *next_tok = S21_NULL;
  char *tok = S21_NULL;
  char *result = S21_NULL;
  int flag = 0;

  if (str != S21_NULL) {
    next_tok = str;
  }
  if (next_tok == S21_NULL) {
    result = S21_NULL;
    flag = 1;
  }
  while (!flag && *next_tok && s21_strchr(delim, *next_tok)) {
    next_tok += 1;
  }
  if (!flag && *next_tok == '\0') {
    flag = 1;
    result = S21_NULL;
    next_tok = S21_NULL;
  }

  tok = next_tok;

  while (!flag && *next_tok && !s21_strchr(delim, *next_tok)) {
    next_tok += 1;
  }
  if (!flag && *next_tok) {
    *next_tok = '\0';
    next_tok += 1;
  }

  if (flag == 0) result = tok;

  return result;
}
