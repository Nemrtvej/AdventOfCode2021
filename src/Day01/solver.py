

class FirstSolver:

    def __init__(self, file: str):
        self._file = file

    def solve(self) -> int:
        result = 0
        previous_value = -1
        f = open(self._file, 'r')
        for line in f:
            current_value = int(line)
            if current_value > previous_value:
                result += 1
            previous_value = current_value

        f.close()

        return result - 1

class SecondSolver:

    def __init__(self, file: str):
        self._file = file

    def solve(self) -> int:
        f = open(self._file, 'r')
        values = []
        previous_value = 999999999
        result = 0

        for line in f:
            current_number = int(line)
            values.append(current_number)
            if (len(values) < 3):
                continue

            current_value = sum(values)
            if current_value > previous_value:
                result += 1

            previous_value = current_value
            values = values[1:3]
        f.close()

        return result
