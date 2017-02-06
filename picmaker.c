#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX 255

int main(){
  const int dimx = 450, dimy = 450;
  int i, j;
  umask(0000);
  int fd = open("pic.ppm", O_CREAT | O_RDWR | O_EXCL, 0644);
  char header[25];
  sprintf(header, "P3 %d %d %d\n", dimx, dimy, MAX);
  write(fd, header, strlen(header));
  for (j = 0; j < dimy; ++j)
  {
    int r,g,b;
    for (i = 0; i < dimx; ++i)
    {
      char colors[20];
      r += (rand()*i + rand()*j);
      r /= rand();
      r %= (MAX+1);  /* red */
      g += i + j;
      g %= (MAX+1);  /* green */
      b = (i * j + rand());
      b /= rand();
      b %= (MAX+1);  /* blue */
      sprintf(colors, "%d %d %d\n", r, g, b);
      write(fd, colors, strlen(colors));
    }
  }
  close(fd);
  return 0;
}
