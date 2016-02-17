#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

const uint64_t c  = 299792458;
const uint64_t ly = 9460730472580800;

int main(void) {
    float_t l, l0, l1;
    float_t t, t0, t1, t2;
    uint64_t v;
    float_t ratio, factor;
    
    printf("What is relative velocity between the moving object and the observer (m/s)?\n");
    scanf("%lu", &v);
    
    assert(v <= c && v >= 0);
    
    ratio = powl(v, 2) / powl(c, 2);
    factor = sqrtf(1 - ratio);
    
    printf("What is object's length at rest?\n");
    scanf("%f", &l0);
    
    assert(l0 >= 0);
    
    printf("Time elapsed in moving frame?\n");
    scanf("%f", &t0);
    
    assert(t0 >= 0);
    
    l = l0 * factor;
    t = t0 / factor;
    printf("Length observed by an observer in relative motion with respect to the object: %f\n", l);
    printf("Time elapsed in static frame: %.2f\n", t);
    
    l1 = ly * factor;
    t1 = l1 / v;
    printf("Time to travel 1ly for the traveler, assuming v constant: %.2f s.\n", t1);
    
    t2 = t1 / factor;
    printf("For the static observer, travel lasted: %.2f s.\n", t2);
    
    return 0;
}
