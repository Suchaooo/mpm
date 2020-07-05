#include "assembler_base.h"
#include "assembler_eigen_semi_implicit_navierstokes.h"

#include "cg_eigen.h"
#include "krylov_petsc.h"
#include "solver_base.h"

// Assembler collections
// Asssembler 2D
static Register<mpm::AssemblerBase<2>,
                mpm::AssemblerEigenSemiImplicitNavierStokes<2>>
    assembler_eigen_semi_implicit_navierstokes_2d(
        "EigenSemiImplicitNavierStokes2D");
// Asssembler 3D
static Register<mpm::AssemblerBase<3>,
                mpm::AssemblerEigenSemiImplicitNavierStokes<3>>
    assembler_eigen_semi_implicit_navierstokes_3d(
        "EigenSemiImplicitNavierStokes3D");

// Linear Solver collections
// Eigen Conjugate Gradient
static Register<mpm::SolverBase<Eigen::SparseMatrix<double>>,
                mpm::CGEigen<Eigen::SparseMatrix<double>>, unsigned, double>
    solver_eigen_cg("CGEigen");

// Krylov Methods PTSC
#ifdef USE_PETSC
static Register<mpm::SolverBase<Eigen::SparseMatrix<double>>,
                mpm::KrylovPETSC<Eigen::SparseMatrix<double>>, unsigned, double>
    solver_krylov_petsc("KrylovPETSC");
#endif
