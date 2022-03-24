import unittest
import subprocess

from .fixtures import BuildTestCase, CLI_NAME


class TestSort(BuildTestCase):

    def setUpClass() -> None:
        ...


    def test_simple_sort(self):
        command = [f"make", "run", "--no-print-directory"]
        result = subprocess.run(command, capture_output=True).stdout

        expected_result = b"""\
pb
pb
ra
pa
ra
pa
rra
rra
"""

        self.assertEqual(result, expected_result)
