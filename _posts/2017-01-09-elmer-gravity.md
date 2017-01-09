---
layout: post
published: true
title: Elmer_Gravity
subtitle: 다양한 마크다운 표현 테스트
date: '2017-01-09'
---
## 개요
* 외팔보 형태의 물체에서, 자중에 의한 쳐짐을 해석한다.
* Transient 조건으로 시간에 의한 형상 변화를 관찰한다.
* 2개 이상의 CPU를 이용하는 MPI 병렬 연산을 해 본다.
* Repository : https://github.com/dymaxionkim/ElmerFEM_Examples/tree/master/20160630_Gravity_Transient

## Geometry
![](https://cloud.githubusercontent.com/assets/12775748/16570910/02208944-428b-11e6-8eef-6f0121eb8ea5.png)

## Key
* Body 전체에 중력이 작용하도록 하기 위해, Body Force를 준다.
* Body Force는, `밀도*중력가속도`로 계산되도록 한다.
* 이때 MATC로 계산되도록 `$`기호를 앞에 붙여준다.
* 정상상태로 결과를 간단히 보려면 Simulatin Type을 Steady State로 해 주고, 시간에 따른 변화를 보려면 Transient로 해 주면 된다.

## case.sif
```
Header
  CHECK KEYWORDS Warn
  Mesh DB "." "."
  Include Path ""
  Results Directory ""
End

Simulation
  Max Output Level = 1
  Coordinate System = Cartesian
  Coordinate Mapping(3) = 1 2 3
  Simulation Type = Transient
  Steady State Max Iterations = 1
  Output Intervals = 200
  Timestepping Method = BDF
  BDF Order = 1
  Timestep intervals = 200
  Timestep Sizes = 0.1
  Solver Input File = case.sif
  Post File = case.ep
Coordinate Scaling = Real 0.1
End

Constants
  Gravity(4) = 0 -1 0 9.82
  Stefan Boltzmann = 5.67e-08
  Permittivity of Vacuum = 8.8542e-12
  Boltzmann Constant = 1.3807e-23
  Unit Charge = 1.602e-19
End

Body 1
  Target Bodies(1) = 1
  Name = "Body 1"
  Equation = 1
  Material = 1
  Body Force = 1
End

Solver 1
  Equation = Result Output
  Procedure = "ResultOutputSolve" "ResultOutputSolver"
  Output File Name = case
  Output Format = Vtu
  Exec Solver = After Timestep
End

Solver 2
  Equation = Linear elasticity
  Procedure = "StressSolve" "StressSolver"
  Variable = -dofs 3 Displacement
  Calculate Loads = True
  Calculate Stresses = True
  Exec Solver = Always
  Stabilize = True
  Bubbles = False
  Lumped Mass Matrix = False
  Optimize Bandwidth = True
  Steady State Convergence Tolerance = 1.0e-5
  Nonlinear System Convergence Tolerance = 1.0e-7
  Nonlinear System Max Iterations = 20
  Nonlinear System Newton After Iterations = 3
  Nonlinear System Newton After Tolerance = 1.0e-3
  Nonlinear System Relaxation Factor = 1
  Linear System Solver = Iterative
  Linear System Iterative Method = BiCGStab
  Linear System Max Iterations = 500
  Linear System Convergence Tolerance = 1.0e-5
  BiCGstabl polynomial degree = 2
  Linear System Preconditioning = Diagonal
  Linear System ILUT Tolerance = 1.0e-3
  Linear System Abort Not Converged = False
  Linear System Residual Output = 1
  Linear System Precondition Recompute = 1
End

Equation 1
  Name = "Equation 1"
  Calculate Stresses = True
  Plane Stress = True
  Active Solvers(2) = 1 2
End

Material 1
  Name = "Steel (carbon - generic)"
  Heat expansion Coefficient = 13.8e-6
  Heat Conductivity = 44.8
  Sound speed = 5100.0
  Heat Capacity = 1265.0
  Mesh Poisson ratio = 0.285
  Density = 7850.0
  Poisson ratio = 0.285
  Youngs modulus = 200.0e9
End

Body Force 1
  Name = "Gravity"
  Stress Bodyforce 2 = $(-7850*9.82)
End

Boundary Condition 1
  Target Boundaries(1) = 8 
  Name = "Fix"
  Displacement 3 = 0
  Displacement 2 = 0
  Displacement 1 = 0
End
```

## Script for MPI
```
#!/bin/bash
ElmerGrid 2 2 ./mesh -metis 4
mpirun -np 4 ElmerSolver_mpi
```

## Result
<iframe width="560" height="315" src="https://www.youtube.com/embed/71PqHrWLbKE" frameborder="0" allowfullscreen></iframe>