#include <pal.h>

/*
 * This function returns a scalar sum of the absolute differences between the
 * source block 'x' and an 16×16 region pointed to in the reference image 'm'.
 *
 * @param x     Pointer to input image, a 2D array of size 'rows' x 'cols'
 *
 * @param m     Pointer to a 16x16 sub image 
 *
 * @param r     Result scalar
 *
 * @param cols  Number of columns in input image
 *
 * @param p     Number of processor to use (task parallelism)
 *
 * @param team  Team to work with 
 *
 * @return      None
 *
 */
void p_sad16x16_f32(const float *x, float *m, float *r, int cols,
                    int p, p_team_t team)
{

     /*pseudo code
       for (i = 0; i < 16; i++)
         for (j = 0; j < 16; j++)
          sad += abs(m[j+i*16] - x[j+i*cols]);
       return sad;
     */

// the image is big... which pixel do we want the pixel for?

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			
			float v = *(m + j + i*cols) - *(b + j + i*cols);
			*(r + j + i*cols) = (1 - ((v < 0) << 1)) * v;
		}
	}
}
