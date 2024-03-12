#include "s21_matrix_oop.h"

namespace Matrix {

void S21Matrix::SetCols(int cols) {
  S21Matrix new_matrix(rows_, cols);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols; ++j) {
      new_matrix(i, j) = matrix_[i][j];
    }
  }
  *this = std::move(new_matrix);
}

void S21Matrix::SetRows(int rows) {
  S21Matrix new_matrix(rows, cols_);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols_; ++j) {
      new_matrix(i, j) = matrix_[i][j];
    }
  }
  *this = std::move(new_matrix);
}

}  // namespace Matrix
