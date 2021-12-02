

class FirstSolver:

    def __init__(self, file: str):
        self._file = file

    def solve(self) -> int:
        f = open(self._file, 'r')
        results = {
            "forward": 0,
            "down": 0,
            "up": 0,
        }
        for line in f:
            instruction, param_string = line.split(' ', 2)
            param = int(param_string)

            results[instruction] += param
        f.close()



        return results["forward"] * (results["down"] - results["up"])




class SecondSolver:

    def __init__(self, file: str):
        self._file = file

    def solve(self) -> int:
        f = open(self._file, 'r')
        aim = 0
        depth = 0
        horizontal = 0

        for line in f:
            instruction, param_string = line.split(' ', 2)
            parameter = int(param_string)

            if instruction == 'down':
                aim += parameter
            elif instruction == 'up':
                aim -= parameter
            else:
                horizontal += parameter
                depth += aim * parameter


        f.close()



        return horizontal * depth
