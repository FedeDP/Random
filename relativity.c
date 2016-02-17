#include <stdio.h>
#include <math.h>
#include <stdint.h>

const uint64_t c = 299792458;

int main(void) {
    float_t l, l0;
    float_t t, t0;
    uint64_t v;
    float_t ratio;
    
    printf("What is relative velocity between the moving object and the observer (m/s)?\n");
    scanf("%lu", &v);
    ratio = powl(v, 2) / powl(c, 2);
    
    printf("What is object resting length?\n");
    scanf("%f", &l0);
    l = l0 * sqrtf(1 - ratio);
    
    printf("Time elapsed in moving frame?\n");
    scanf("%f", &t0);
    t = t0 / sqrtf(1 - ratio);
    
    printf("Length observed by an observer in relative motion with respect to the object: %f\n", l);
    printf("Time elapsed in static frame: %.2f\n", t);
    
    return 0;
}
