#include <stdio.h>
#include <unistd.h>

int main(void) {
  char perc []= "\\|/-";
  while (1) {
    for (int i = 0; i < 4; i++) {
      printf("%c", perc[i]);
      fflush(NULL);
      usleep(100000);
      printf("\b");
    } 
  }

  return 0;
}
