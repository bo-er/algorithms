## Introduction

Dynamic programming is a strategy for **solving** a complex problem by breaking it down into a collection of simpler subproblems, solving each subproblem only once, and then **storing** the solutions to prevent repeating calculations, according to the definition.

- It breaks down the complicated problem into simpler subproblems.
- It finds the optimal solution to these sub-problems.
- It stores the results of subproblems (memoization) (memoization). The technique of keeping the effects of subproblems is known as memory.
- It reuses them such that the same sub-problem is calculated more than once.
- Finally, calculate the impact of the complicated problem.

The above five steps are the basic steps for dynamic programming. Those problems are having **overlapping** subproblems and optimum substructures. Here, optimum substructure means that the solution of **optimization** issues may be reached by simply combining the optimal solution of all the subproblems.

## Problem Sets

### Cutting the rode

| length i | 1 | 2 | 3 | 4 | 5  | 6  | 7  | 8  | 9  | 10 |
|----------|---|---|---|---|----|----|----|----|----|----|
| price p1 | 1 | 5 | 8 | 9 | 10 | 17 | 17 | 20 | 24 | 30 |
