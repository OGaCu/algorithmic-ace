/**
 * Input:
    [[1,2,3],
    [4,5,6],
    [7,8,9]]
 * Output:
    [[7,4,1],
    [8,5,2],
    [9,6,3]]
 */
#include <vector>
using std::vector;

void rotate_img(vector<vector<int>>& img) {
   int pivot = 0, n = img.size() - 1;
   for (int i = 0; i <= n / 2; ++i) {
      for (int j = i; j <= n - i; ++j) {
         pivot = img[j][n - i];
         img[j][n - i] = img[i][j];
         img[i][j] = img[n - j][i];
         img[n - j][i] = img[n - i][n - j];
         img[n - i][n - j] = pivot;
      }
   }
} // 48