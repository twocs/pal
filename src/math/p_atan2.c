#include <pal.h>
// #include <math.h>

static const float pi_2 = (float) M_PI * 0.5f;


/*
 * code from pal/p_atan()
 * -1 <= x <= 1
 * atan x = a1 * x + a3 * x^3 + ... + a9 * x^9 + e(x)
 * |e(x)| <= 10^-5
 */
static inline float _p_atan(const float x)
{
    const float a1 =  0.9998660f;
    const float a3 = -0.3302995f;
    const float a5 =  0.1801410f;
    const float a7 = -0.0851330f;
    const float a9 =  0.0208351f;
    float x2 = x * x;
    return x * (a1 + x2 * (a3 + x2 * (a5 + x2 * (a7 + x2 * a9))));
}


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
void p_atan2_f32(const float *a, const float *b, float *c, int n)
{

    int i;
    for (i = 0; i < n; i++) {
        if (*(b + i) == 0)
        {
            if(*(a + i) > 0) {
                *(c + i) = pi_2;
            }
            else /* if(*(a + i) < 0) */ {
                *(c + i) = - pi_2;
            }
            /* // ignore this case, because it's an illegal value
            if(*(a + i) == 0) { 
                *(c + i) = NAN;
            }
            */
        }
        else if (*(a + i) == 1) {
            *(c + i) = _p_atan(*(b + i));
        }
        else if (*(a + i) == -1) {
            *(c + i) = -_p_atan(*(b + i));
        }
        else if(*(a + i) > 0) {
            *(c + i) = _p_atan(*(b + i) / *(a + i));
        }
        else /* if(*(a + i) < 0) */ {
            if (*(b + i) > 0) {
                *(c + i) = _p_atan(*(b + i) / *(a + i)) + pi_2;
            }
            else /* if (*(b + i) > 0) */ {
                *(c + i) = _p_atan(*(b + i) / *(a + i)) - pi_2;
            }
        }
    }
}
