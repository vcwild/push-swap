import unittest
import subprocess

CLI_NAME = "push_swap"

class BuildTestCase(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        command = [
            "make",
        ]
        subprocess.call(command)

    @classmethod
    def tearDownClass(cls):
        command = ["make", "fclean"]
        subprocess.call(command)
