#include "s21_matrix_oop.h"

namespace Matrix {

bool S21Matrix::EqMatrix(const S21Matrix& rhs) const {
  if (GetRows() != rhs.GetRows() || GetCols() != rhs.GetCols()) {
    return false;
  }
  for (int i = 0; i < GetRows(); i++) {
    for (int j = 0; j < GetCols(); j++) {
      if (fabs(matrix_[i][j] - rhs(i, j)) > 1e-6) {
        return false;
      }
    }
  }
  return true;
}

}  // namespace Matrix
