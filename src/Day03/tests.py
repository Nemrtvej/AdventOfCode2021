import unittest
from solver import FirstSolver, SecondSolver

class FirstSolverTest(unittest.TestCase):

    def test_first(self):
        solver = FirstSolver(5, 'input/First/input1.txt')

        self.assertEqual(198, solver.solve())

    def test_second(self):
         solver = FirstSolver(12, 'input/First/input2.txt')

         self.assertEqual(3969000, solver.solve())


class SecondSolverTest(unittest.TestCase):

    def test_first(self):
        solver = SecondSolver('input/First/input1.txt')
        self.assertEqual(230, solver.solve())

    def test_second(self):
        solver = SecondSolver('input/First/input2.txt')

        self.assertEqual(4267809, solver.solve())


if __name__ == '__main__':
    unittest.main()
