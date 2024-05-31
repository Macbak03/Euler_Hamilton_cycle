import os
import shutil
import sys


def generate_file(filename, n, saturation=30):
    with open(filename, 'w') as file:
        if (graph_type == "hamilton"):
            file.write(f"{n}\n{saturation}\n")
        elif (graph_type == "non-hamilton"):
            file.write(f"{n}\n")

if __name__ == "__main__":

    if len(sys.argv) < 2 or len(sys.argv) == 3 or len(sys.argv) > 4:
        print("Usage: python generate.py <type> [start_exponent] [end_exponent]")
        sys.exit(1)
    try:
        if len(sys.argv) == 4:
            start_exponent = int(sys.argv[2])
            end_exponent = int(sys.argv[3])
        graph_type = sys.argv[1]
    except ValueError as e:
        print(f"Error: {e}")
        print("Usage: python generate.py <type> [start_exponent] [end_exponent]")
        sys.exit(1)

    # Directory where files will be saved
    directory = 'benchmark'

    # Clear the contents of the benchmark directory
    if os.path.exists(directory):
        shutil.rmtree(directory)
    os.makedirs(directory)

    if graph_type == "non-hamilton":
        end_exponent = 24
        max_n_length = 2
        n = 0
        for i in range(0, end_exponent // 2):
            n = n+2
            filename = os.path.join(directory, f"generate.{n:0{max_n_length}}")
            generate_file(filename, n)

    elif graph_type == "hamilton":
        max_n_length = len(str(2 ** end_exponent))  # Determine the length of the largest n
        for i in range(start_exponent, end_exponent + 1):
            n = 2 ** i
            filename = os.path.join(directory, f"generate.{n:0{max_n_length}}")
            generate_file(filename, n)
