//robo made dis
#include <stdio.h>
#include <stdlib.h>
//comment if you want LRS of "aaaaa" to be "aaaa" instead of "aa"
#define NOOVERLAP

int main(void){
	char * tbuf =0;
	size_t tbufsize = 0;
	int x, y, pp;
	int bp = 0;
	int bl = 0;
	int tbp = 0;
	char c;
	while((c = getc(stdin)) != EOF){
		if(tbp >= tbufsize){
			tbufsize = tbp + 128;
			tbuf = realloc(tbuf, tbufsize);
		}
		tbuf[tbp++] = c;
	}
	for(x = 0; x < tbp; x++){
		for(y = x+1; y < tbp; y++){
			#ifdef NOOVERLAP
			for(pp= 0; x+pp < y && y+pp < tbp && tbuf[x+pp] == tbuf[y+pp]; pp++);
			#else
			for(pp= 0; y+pp < tbp && tbuf[x+pp] == tbuf[y+pp]; pp++);
			#endif
			if(pp > bl){
				bl = pp;
				bp = x;
			}
		}
	}
	for(x = 0; x < bl; x++) putc(tbuf[bp +x], stdout);
	if(tbuf)free(tbuf);
}
