import unittest
import subprocess

from .fixtures import BuildTestCase, CLI_NAME


class TestCli(BuildTestCase):
    def test_run_version(self):
        command = [f"./{CLI_NAME}", "-h"]
        result = subprocess.run(command, capture_output=True).stdout

        expected_result = f"Usage: ./{CLI_NAME} \"<numbers>\"\n"
        expected_result = bytes(expected_result, "utf-8")

        self.assertEqual(result, expected_result)

    # def test_run_arbitrary_input(self):
    #     command = [
    #         f"./{CLI_NAME}", "-2147483648 1 2147483647"
    #     ]
    #     result = subprocess.run(command, capture_output=True).stdout

    #     expected_result = "origin[0]: 2 \norigin[1]: 1 \norigin[2]: 0 \n"
    #     expected_result = bytes(expected_result, "utf-8")

    #     self.assertEqual(result, expected_result)

    def test_invalid_number_of_inputs(self):
        command = [
            f"./{CLI_NAME}", "-2147483648 1 2147483647", "1"
        ]

        result = subprocess.run(command, capture_output=True).stderr

        expected_result = "Error: Parse args failed\n"
        expected_result = bytes(expected_result, "utf-8")

        self.assertEqual(result, expected_result)

if __name__ == "__main__":
    unittest.main()
