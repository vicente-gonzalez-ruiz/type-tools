#define BUF_SIZE 4096

#include <stdio.h>

int main(int argc, char *argv[]) {
  if(argc>1) {
    fprintf(stderr,"< input > output\n");
    return 1;
  }
  
  fprintf(stderr,"%s: running ...\n",argv[0]);
  for(;;) {
    unsigned char x[BUF_SIZE];
    char y[BUF_SIZE];
    int r = fread(x,sizeof(unsigned char),BUF_SIZE,stdin);
    if(r==0) break;
    {
      int i;
      for(i=0; i<r; i++) {
	if(x[i]>127) y[i] = 127;
	else y[i] = (char)x[i];
      }
    }
    fwrite(y,sizeof(char),r,stdout);
  }
  fprintf(stderr,"%s: done\n",argv[0]);
  return 0;
}
