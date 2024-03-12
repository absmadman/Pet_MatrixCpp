#include "s21_matrix_oop.h"

namespace Matrix {

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("Invalid");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = std::vector<std::vector<double>>(rows, std::vector<double>(cols));
}

}  // namespace Matrix
