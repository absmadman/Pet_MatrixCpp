#include "s21_matrix_oop.h"

namespace Matrix {

void S21Matrix::CheckForSegv(int i, int j) const {
  if (rows_ < i || cols_ < j) {
    throw std::invalid_argument("Invalid");
  }
}

double S21Matrix::operator()(int i, int j) const {
  CheckForSegv(i, j);
  return matrix_[i][j];
}

double &S21Matrix::operator()(int i, int j) {
  CheckForSegv(i, j);
  return matrix_[i][j];
}

S21Matrix S21Matrix::operator+(const S21Matrix &rhs) {
  S21Matrix result(*this);
  result.SumMatrix(rhs);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &rhs) {
  S21Matrix result(*this);
  result.SubMatrix(rhs);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &rhs) {
  S21Matrix result(*this);
  result.MulMatrix(rhs);
  return result;
}

S21Matrix S21Matrix::operator*(const double rhs) {
  S21Matrix result(*this);
  result.MulNumber(rhs);
  return result;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &rhs) {
  matrix_ = rhs.AccessMatrix();
  rows_ = rhs.GetRows();
  cols_ = rhs.GetCols();
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&rhs) noexcept {
  rows_ = rhs.GetRows();
  cols_ = rhs.GetCols();
  matrix_ = std::move(rhs.matrix_);
  return *this;
}

}  // namespace Matrix
