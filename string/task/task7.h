#ifndef INC_TASK7_H
#define INC_TASK7_H

#include "../string_.h"

void outputRevers(char *s) {
    getBagOfWords(&bag_, s);
    WordDescriptor *endBag = bag_.words + bag_.size-1;
    while(endBag >= bag_.words){
        char *bs = endBag->begin;
        char *es = endBag->end;
        while (bs != es) {
            printf("%c",*bs);
            bs++;
        }
        printf("\n");
        endBag--;
    }
}

#endif