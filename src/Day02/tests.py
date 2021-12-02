import unittest
from solver import FirstSolver, SecondSolver

class FirstSolverTest(unittest.TestCase):

    def test_first(self):
        solver = FirstSolver('input/First/input1.txt')

        self.assertEqual(150, solver.solve())

    def test_second(self):
        solver = FirstSolver('input/First/input2.txt')

        self.assertEqual(2036120, solver.solve())


class SecondSolverTest(unittest.TestCase):

    def test_first(self):
        solver = SecondSolver('input/Second/input1.txt')

        self.assertEqual(900, solver.solve())


    def test_second(self):
        solver = SecondSolver('input/Second/input2.txt')

        self.assertEqual(2015547716, solver.solve())


if __name__ == '__main__':
    unittest.main()
