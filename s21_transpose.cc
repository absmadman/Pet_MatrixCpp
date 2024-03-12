#include "s21_matrix_oop.h"

namespace Matrix {

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(GetCols(), GetRows());
  for (int i = 0; i < GetRows(); ++i) {
    for (int j = 0; j < GetCols(); ++j) {
      result(j, i) = matrix_[i][j];
    }
  }
  return result;
}

}  // namespace Matrix
