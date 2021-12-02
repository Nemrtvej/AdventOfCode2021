import unittest
from solver import FirstSolver, SecondSolver

class FirstSolverTest(unittest.TestCase):

    def test_first(self):
        solver = FirstSolver('input/First/input1.txt')

        self.assertEqual(7, solver.solve())


    def test_second(self):
        solver = FirstSolver('input/First/input2.txt')

        self.assertEqual(1713, solver.solve())


class SecondSolverTest(unittest.TestCase):

    def test_first(self):
        solver = SecondSolver('input/Second/input1.txt')

        self.assertEqual(5, solver.solve())


    def test_second(self):
        solver = SecondSolver('input/Second/input2.txt')

        self.assertEqual(1734, solver.solve())


if __name__ == '__main__':
    unittest.main()
