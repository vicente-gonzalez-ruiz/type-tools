#define BUF_SIZE 4096

#include <stdio.h>

main(int argc, char *argv[]) {
  if(argc>1) {
    fprintf(stderr,"< entrada > salida\n");
    return 1;
  }

  fprintf(stderr,"%s: running ...\n",argv[0]);
  for(;;) {
    int x[BUF_SIZE];
    float y[BUF_SIZE];
    int r = fread(x,sizeof(int),BUF_SIZE,stdin);
    if(r==0) break;
    {
      int i;
      for(i=0; i<r; i++) {
	y[i] = (float)x[i];
      }
    }
    fwrite(y,sizeof(float),r,stdout);
  }
  fprintf(stderr,"%s: done\n",argv[0]);
}
