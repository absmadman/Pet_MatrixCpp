#include "s21_matrix_oop.h"

namespace Matrix {
S21Matrix S21Matrix::CalcComplements() {
  CheckSizing();

  S21Matrix result(GetCols(), GetRows());
  if (cols_ == 1 && rows_ == 1) {
    result(0, 0) = 1;
    return result;
  }
  for (int i = 0; i < GetRows(); ++i) {
    for (int j = 0; j < GetCols(); ++j) {
      S21Matrix minor = GetMinor(i, j);
      result(i, j) = minor.Determinant() * pow(-1, i + j);
    }
  }

  return result;
}

}  // namespace Matrix
