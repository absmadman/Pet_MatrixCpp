#include "s21_matrix_oop.h"

namespace Matrix {

S21Matrix S21Matrix::GetMinor(int ix, int jx) {
  S21Matrix minor(GetRows() - 1, GetCols() - 1);
  int rowm = 0;
  int colm = 0;
  for (int i = 0; i < GetRows(); ++i) {
    if (ix != i) {
      for (int j = 0; j < GetCols(); ++j) {
        if (jx != j) {
          minor(rowm, colm) = matrix_[i][j];
          colm++;
        }
      }
      rowm++;
      colm = 0;
    }
  }
  return minor;
}

double S21Matrix::Determinant() {
  if (GetCols() != GetRows()) throw std::invalid_argument("Invalid");
  if (GetCols() == 1) return matrix_[0][0];
  if (GetCols() == 2)
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  double result = 0;
  for (int i = 0; i < GetRows(); ++i) {
    S21Matrix Minor = GetMinor(0, i);
    result += matrix_[0][i] * Minor.Determinant() * pow(-1, i);
  }
  return result;
}

}  // namespace Matrix
