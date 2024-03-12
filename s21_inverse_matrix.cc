#include "s21_matrix_oop.h"

namespace Matrix {

S21Matrix S21Matrix::InverseMatrix() {
  CheckSizing();
  if (GetRows() == 1) {
    if (matrix_[0][0] == 0) throw std::invalid_argument("Division by zero");
    S21Matrix result(GetRows(), GetCols());
    result(0, 0) = 1 / matrix_[0][0];
    return result;
  }
  double determinant = Determinant();
  if (determinant == 0) throw std::invalid_argument("Division by zero");
  S21Matrix matrix_of_complements = CalcComplements();
  S21Matrix result = matrix_of_complements.Transpose();
  result.MulNumber(1 / determinant);
  return result;
}

}  // namespace Matrix
