#include "s21_matrix_oop.h"

namespace Matrix {

void S21Matrix::CheckSizingMult(S21Matrix &dst, const S21Matrix &rhs) {
  if (rhs.GetRows() != dst.GetCols() || rhs.GetCols() != dst.GetRows()) {
    throw std::invalid_argument("Invalid");
  }
}

void S21Matrix::CheckSizing() {
  if (GetRows() != GetCols() || GetRows() < 1 || GetCols() < 1) {
    throw std::invalid_argument("Invalid");
  }
}

void S21Matrix::CheckSizing(S21Matrix &dst, const S21Matrix &rhs) {
  if (rhs.GetRows() != dst.GetRows() || rhs.GetCols() != dst.GetCols()) {
    throw std::invalid_argument("Invalid");
  }
}

void S21Matrix::Calculations(S21Matrix &dst, const S21Matrix &rhs,
                             void(f)(S21Matrix &a, const S21Matrix &b, int i,
                                     int j)) {
  for (int i = 0; i < dst.GetRows(); ++i) {
    for (int j = 0; j < dst.GetCols(); ++j) {
      f(dst, rhs, i, j);
    }
  }
}

void S21Matrix::SumMatrix(const S21Matrix &rhs) {
  CheckSizing(*this, rhs);
  Calculations(*this, rhs,
               [](S21Matrix &a, const S21Matrix &b, int i, int j) -> void {
                 a(i, j) = a(i, j) + b(i, j);
               });
}

void S21Matrix::SubMatrix(const S21Matrix &rhs) {
  CheckSizing(*this, rhs);
  Calculations(*this, rhs,
               [](S21Matrix &a, const S21Matrix &b, int i, int j) -> void {
                 a(i, j) = a(i, j) - b(i, j);
               });
}

void S21Matrix::MulMatrix(const S21Matrix &rhs) {
  CheckSizingMult(*this, rhs);
  S21Matrix res(this->GetRows(), rhs.GetCols());
  for (int i = 0; i < this->GetRows(); ++i) {
    for (int j = 0; j < rhs.GetCols(); ++j) {
      for (int k = 0; k < rhs.GetRows(); ++k) {
        res(i, j) = res(i, j) + matrix_[i][k] * rhs(k, j);
      }
    }
  }
  rows_ = cols_;
  matrix_ = res.matrix_;
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->GetRows(); ++i) {
    for (int j = 0; j < this->GetCols(); ++j) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

}  // namespace Matrix
