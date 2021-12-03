from __future__ import annotations
from typing import List

class FirstCounter:

    def __init__(self, length: int):
        self._items_processed = 0
        self._values = {}

        for i in range(0, length):
            self._values[i] = 0

    def add_item(self, item: str) -> None:
        self._items_processed += 1
        for index in range(0, len(item)):
            self._values[index] += int(item[index])

    def get_gamma(self) -> str:
        result =  ""

        for index in range(0, len(self._values)):
            if self._values[index] > self._items_processed / 2:
                result += "1"
            else:
                result += "0"

        return result


    def get_epsilon(self) -> str:
        result =  ""

        for index in range(0, len(self._values)):
            if self._values[index] > self._items_processed / 2:
                result += "0"
            else:
                result += "1"

        return result


class AdventNumber:

    def __init__(self, number_word: str):
        self._number_word = number_word

    def has_char_on_position(self, char: str, position: int) -> bool:
        return self._number_word[position] == char

    def to_int(self) -> int:
        return int(self._number_word, 2)

    def __repr__(self) -> str:
        return self._number_word

class NumberSet:

    def __init__(self):
        self._numbers = []

    def add_number(self, num: AdventNumber) -> None:
        self._numbers.append(num)

    def get_occurences_of_char_on_position(self, char: str, position: int) -> int:
        occurrences = 0
        for number in self._numbers:
            if number.has_char_on_position(char, position):
                occurrences += 1

        return occurrences

    def count(self) -> int:
        return len(self._numbers)

    def filter(self, filter_cb) -> NumberSet:
        new_instance = NumberSet()

        for number in self._numbers:
            if filter_cb(number):
                new_instance.add_number(number)

        return new_instance

    def get_first(self) -> AdventNumber:
        return self._numbers[0]


class SecondCounter:

    def __init__(self):
        self._numbers = NumberSet()
        self._length = 0

    def add_number(self, word: str) -> None:
        self._numbers.add_number(AdventNumber(word))
        self._length = len(word)

    def get_oxygen(self) -> AdventNumber:
        numbers = self._numbers.filter(lambda x: True)
        for i in range(0, self._length):
            occurrences_of_one = numbers.get_occurences_of_char_on_position("1", i)
            total_numbers = numbers.count()
            if occurrences_of_one >= total_numbers / 2:
                numbers = numbers.filter(lambda number: number.has_char_on_position("1", i))
            else:
                numbers = numbers.filter(lambda number: number.has_char_on_position("0", i))

            if numbers.count() == 1:
                return numbers.get_first()

        return numbers.get_first()


    def get_scrubber(self) -> AdventNumber:
        numbers = self._numbers.filter(lambda x: True)
        for i in range(0, self._length):
            occurrences_of_zero = numbers.get_occurences_of_char_on_position("0", i)
            total_numbers = numbers.count()
            if occurrences_of_zero <= total_numbers / 2:
                numbers = numbers.filter(lambda number: number.has_char_on_position("0", i))
            else:
                numbers = numbers.filter(lambda number: number.has_char_on_position("1", i))

            if numbers.count() == 1:
                return numbers.get_first()

        return numbers.get_first()


class FirstSolver:

    def __init__(self, length: int, file: str):
        self._file = file
        self._length = length

    def solve(self) -> int:
        counter = FirstCounter(self._length)
        f = open(self._file, 'r')

        for line in f:
            counter.add_item(line.strip())
        f.close()

        gamma_str = counter.get_gamma()
        epsilon_str = counter.get_epsilon()

        return int(gamma_str, 2) * int(epsilon_str, 2)



class SecondSolver:

    def __init__(self, file: str):
        self._file = file

    def solve(self) -> int:
        f = open(self._file, 'r')
        counter = SecondCounter()

        for line in f:
            counter.add_number(line.strip())

        f.close()

        oxygen = counter.get_oxygen().to_int()
        scrubber = counter.get_scrubber().to_int()

        return oxygen * scrubber

