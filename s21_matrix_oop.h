#ifndef S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_
#define S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> MatrixType;

namespace Matrix {
class S21Matrix {
 public:  // ctors dtors
  S21Matrix() : rows_{1}, cols_{1}, matrix_{{0}} {}
  S21Matrix(int rows, int cols);
  S21Matrix(S21Matrix &rhs) : matrix_(rhs.matrix_) {
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
  }
  S21Matrix(S21Matrix &&rhs) noexcept {
    matrix_ = std::move(rhs.matrix_);
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
    rhs.rows_ = 0;
    rhs.cols_ = 0;
  }
  ~S21Matrix() {
    rows_ = 0;
    cols_ = 0;
  }

 public:  // public methods
  void SumMatrix(const S21Matrix &rhs);
  void SubMatrix(const S21Matrix &rhs);
  void MulMatrix(const S21Matrix &rhs);
  void MulNumber(const double num);
  int GetCols() const { return cols_; };
  int GetRows() const { return rows_; };
  void SetCols(int cols);
  void SetRows(int rows);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();
  bool EqMatrix(const S21Matrix &rhs) const;

 public:  // operators overload
  double operator()(int i, int j) const;
  double &operator()(int i, int j);
  S21Matrix operator+=(S21Matrix &rhs) {
    SumMatrix(rhs);
    return *this;
  }
  S21Matrix operator-=(S21Matrix &rhs) {
    SubMatrix(rhs);
    return *this;
  }
  S21Matrix operator*=(S21Matrix &rhs) {
    MulMatrix(rhs);
    return *this;
  }
  S21Matrix operator*=(double number) {
    MulNumber(number);
    return *this;
  }
  S21Matrix operator+(const S21Matrix &rhs);
  S21Matrix operator-(const S21Matrix &rhs);
  S21Matrix operator*(const S21Matrix &rhs);
  S21Matrix operator*(const double rhs);
  S21Matrix &operator=(const S21Matrix &rhs);
  S21Matrix &operator=(S21Matrix &&rhs) noexcept;
  bool operator==(const S21Matrix &rhs) const { return EqMatrix(rhs); }

 private:  // methods
  void Calculations(S21Matrix &dst, const S21Matrix &rhs,
                    void(f)(S21Matrix &a, const S21Matrix &b, int i, int j));
  void CheckSizing(S21Matrix &dst, const S21Matrix &rhs);
  void CheckSizing();
  void CheckSizingMult(S21Matrix &dst, const S21Matrix &rhs);
  MatrixType AccessMatrix() const { return matrix_; };
  S21Matrix GetMinor(int i, int j);
  S21Matrix OperatorsArithmetic(S21Matrix &rhs, void (*)(S21Matrix &rhs));
  void CheckForSegv(int i, int j) const;

 private:
  int rows_, cols_;
  std::vector<std::vector<double>> matrix_;
};
}  // namespace Matrix

#endif
