#include <pal.h>
// #include <math.h>

/**
 *
 * Calculates the inverse tangent (arc tangent) of b/a. Stability not guaranteed
 * for 'a' values near 0. Results are in the range of -pi to pi.
 *
 * @param a     Pointer to denominator input vector
 *
 * @param b     Pointer to numerator input vector
 *
 * @param c     Pointer to output vector
 *
 * @param n     Size of 'a' and 'c' vector.
 *
 * @return      None
 *
 * @todo        Implement without using libm
 *
 */
 a=y, b=x => y/x, 
void p_atan2_f32(const float *a, const float *b, float *c, int n)
{

    int i;
    for (i = 0; i < n; i++) {
        if (*(b + i) == 0)
        {
            if(*(a + i) > 0) {
                *(c + i) = PI * 0.5;
            }
            else /* if(*(a + i) < 0) */ {
                *(c + i) = -PI * 0.5;
            }
            /* // ignore this case, because it's an illegal value
            if(*(a + i) == 0) { 
                *(c + i) = NAN;
            }
            */
        }
        else if (*(a + i) = 1) {
            *(c + i) = _p_atan(*(b + i));
        }
        else if (*(a + i) = -1) {
            *(c + i) = _p_atan(*(b + i));
        }
        else if(*(a + i) > 0) {
            *(c + i) = _p_atan(*(b + i) / *(a + i));
        }
        else /* if(*(a + i) < 0) */ {
            if (*(b + i) > 0) {
                *(c + i) = _p_atan(*(b + i) / *(a + i)) + PI * 0.5;
            }
            else /* if (*(b + i) > 0) */ {
                *(c + i) = _p_atan(*(b + i) / *(a + i)) - PI * 0.5;
            }
        }
    }
}
