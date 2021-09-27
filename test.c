#include <stdio.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h>
#include <error.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {
  setlocale(LC_CTYPE, "en_US.utf-8");
  mbstate_t state;
  memset(&state, '\0', sizeof state);
  char ch[] = "我爱你";
  const char* p_ch = ch;
  wchar_t wch[4];
  mbsrtowcs(wch, &p_ch, MB_CUR_MAX, &state);
  if (errno) {
    error(0, errno, NULL);
  }
  printf("%s\n", ch);
  printf("%ls\n", wch);

  return 0;
}
