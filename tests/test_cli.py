import unittest
import subprocess

CLI_NAME = "push_swap"


class TestCli(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        command = [
            "make",
        ]
        subprocess.call(command)

    @classmethod
    def tearDownClass(cls):
        command = ["make", "clean"]
        subprocess.call(command)

    def test_run_version(self):
        command = [f"./{CLI_NAME}", "-h"]
        result = subprocess.run(command, capture_output=True).stdout

        expected_result = f"Usage: ./{CLI_NAME} [numbers]\n"
        expected_result = bytes(expected_result, "utf-8")

        self.assertEqual(result, expected_result)


if __name__ == "__main__":
    unittest.main()
