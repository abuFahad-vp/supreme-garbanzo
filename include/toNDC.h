#ifndef TO_NDC_H_
#define TO_NDC_H_
float toNDC(float coord,float screenMaxSize) {
    float percentage = (coord/screenMaxSize)*100;
    return ((percentage*2)/100-1);
} 
#endif