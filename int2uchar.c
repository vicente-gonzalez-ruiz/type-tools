#define BUF_SIZE 4096

#include <stdio.h>

main(int argc, char *argv[]) {
  if(argc>1) {
    fprintf(stderr,"< input > output\n");
    return 1;
  }

#if defined DEBUG
  fprintf(stderr,"%s: running ...\n",argv[0]);
#endif
  for(;;) {
    int x[BUF_SIZE];
    unsigned char y[BUF_SIZE];
    int r = fread(x,sizeof(int),BUF_SIZE,stdin);
    if(r==0) break;
    {
      int i;
      for(i=0; i<r; i++) {
	if(x[i]<0) y[i] = 0;
	else if(x[i] > 255) y[i] = 255;
	else y[i] = (unsigned char)x[i];
      }
    }
    fwrite(y,sizeof(unsigned char),r,stdout);
  }
#if defined DEBUG
  fprintf(stderr,"%s: done\n",argv[0]);
#endif
  return 0;
}
