#!/usr/bin/env python3

"""
Local testing tool for Nailoong vs. Bombloong 1.

Disclaimer: This is NOT the same code used to test your solution when it is submitted.
This tool is provided as-is. Its purpose is to help with debugging the communication
problem and it has no ambitions to extensively test all possibilities that
are allowed by the problem statement. The result may differ if the tested program
does not use the correct formatting or exhibits other incorrect behavior.

The behavior is controlled by an input data file.
The first line of the file contains two integers: k and x.
The second line contains 2^k integers: the initial array a_1, a_2, ..., a_{2^k}.

Here is an example file (k=2, x=3, a=[1, 0, 0, 1]):
2 3
1 0 0 1

The testing tool is run like this::

    python nailoong_vs_bombloong1_testing_tool.py <data_file> <program> <arguments>

where `arguments` are optional arguments to the program to run. On Windows,
use `python` or `py` instead of `python3`. The following show examples for
different languages::

    python nailoong_vs_bombloong1_testing_tool.py 1.in ./myprogram.exe
    python nailoong_vs_bombloong1_testing_tool.py 1.in java -cp . MyProgram
    python nailoong_vs_bombloong1_testing_tool.py 1.in python myprogram.py

The tested program is started directly from the argument list, without
`shell=True`, so paths and arguments containing spaces are handled more
reliably. To run a .bat or .cmd file on Windows, call it through `cmd /c`.

The tool logs the complete interaction.
If you do not want that, pass `--quiet` (before the data file name).
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from typing import List, Optional, Tuple

verbose = True
process = None
run_id = 0


class WrongAnswer(RuntimeError):
    pass


class EndOfFile(RuntimeError):
    pass


def vprint(*args, **kwargs) -> None:
    if verbose:
        print("< ", end="")
        print(*args, **kwargs)
        sys.stdout.flush()
    print(*args, file=process.stdin, flush=True, **kwargs)


def vreadline(optional: bool = False) -> str:
    line = process.stdout.readline()
    if verbose and line:
        print(">", line.rstrip("\n"))
    if not line and not optional:
        raise EndOfFile()
    return line


def read_data(path: str) -> Tuple[int, int, List[int]]:
    with open(path, "r", encoding="utf-8") as f:
        tokens = f.read().strip().split()
    if not tokens:
        raise ValueError("Input file is empty.")
    if len(tokens) < 2:
        raise ValueError("Not enough integers for k and x.")
    
    k = int(tokens[0])
    x = int(tokens[1])
    
    if not (0 <= k <= 16):
        raise ValueError(f"k={k} is out of bounds [0, 16].")
        
    expected_len = 1 << k
    if not (1 <= x <= expected_len):
        raise ValueError(f"x={x} is out of bounds [1, {expected_len}].")
        
    if len(tokens) < 2 + expected_len:
        raise ValueError(f"Not enough array elements. Expected {expected_len}.")
        
    a = []
    for i in range(expected_len):
        val = int(tokens[2 + i])
        if val not in (0, 1):
            raise ValueError(f"Array element a[{i+1}] must be 0 or 1, got {val}.")
        a.append(val)
        
    return k, x, a


def format_command(program: List[str]) -> str:
    return subprocess.list2cmdline(program)


def start_process(program: List[str], phase: str, bufsize: Optional[int] = None) -> subprocess.Popen:
    global run_id, process
    run_id += 1
    if verbose:
        print(f"[run {run_id}] {phase}: {format_command(program)}")
    kwargs = {
        "stdin": subprocess.PIPE,
        "stdout": subprocess.PIPE,
        "text": True,
    }
    if bufsize is not None:
        kwargs["bufsize"] = bufsize
    try:
        process = subprocess.Popen(program, **kwargs)
    except FileNotFoundError as exc:
        raise RuntimeError(f"Failed to start program: {format_command(program)}") from exc
    if process.stdin is None or process.stdout is None:
        raise RuntimeError("Failed to open pipes.")
    return process


def run_nailong(program: List[str], k: int, x: int, a: List[int]) -> int:
    start_process(program, "Nailong (First Run)")
    
    vprint("1")
    vprint(f"{k} {x}")
    vprint(" ".join(map(str, a)))
        
    try:
        process.stdin.close()
    except Exception:
        pass

    lines = []
    while True:
        line = vreadline(optional=True)
        if line == "":
            break
        stripped = line.strip()
        if stripped != "":
            lines.append(stripped)

    process.wait()
    if process.returncode != 0:
        raise WrongAnswer(f"Nailong (First Run) exit code {process.returncode}.")

    tokens = []
    for line in lines:
        tokens.extend(line.split())
        
    if not tokens:
        raise WrongAnswer("No output from Nailong.")
        
    try:
        y = int(tokens[0])
    except ValueError:
        raise WrongAnswer(f"Invalid y: {tokens[0]}")
        
    expected_len = 1 << k
    if not (1 <= y <= expected_len):
        raise WrongAnswer(f"y = {y} is out of bounds [1, {expected_len}].")
        
    return y


def run_bombloong(program: List[str], k: int, a_modified: List[int]) -> int:
    start_process(program, "Bombloong (Second Run)")
    
    vprint("2")
    vprint(f"{k}")
    vprint(" ".join(map(str, a_modified)))
        
    try:
        process.stdin.close()
    except Exception:
        pass

    lines = []
    while True:
        line = vreadline(optional=True)
        if line == "":
            break
        stripped = line.strip()
        if stripped != "":
            lines.append(stripped)

    process.wait()
    if process.returncode != 0:
        raise WrongAnswer(f"Bombloong (Second Run) exit code {process.returncode}.")
        
    tokens = []
    for line in lines:
        tokens.extend(line.split())
        
    if not tokens:
        raise WrongAnswer("No output from Bombloong.")
        
    try:
        ans_x = int(tokens[0])
    except ValueError:
        raise WrongAnswer(f"Invalid x: {tokens[0]}")
        
    expected_len = 1 << k
    if not (1 <= ans_x <= expected_len):
        raise WrongAnswer(f"Output x = {ans_x} is out of bounds [1, {expected_len}].")
            
    return ans_x


def main() -> int:
    parser = argparse.ArgumentParser(
        usage="%(prog)s [--quiet] data.in program [args...]"
    )
    parser.add_argument(
        "--quiet", "-q", action="store_true", help="Do not show interactions"
    )
    parser.add_argument("data", help="Input file containing the initial k, x and array a")
    parser.add_argument("program", nargs=argparse.REMAINDER, help="Program to run")
    args = parser.parse_args()

    global verbose
    verbose = not args.quiet

    if not args.program:
        parser.error("Must specify program to run")

    try:
        k, x, a = read_data(args.data)
    except Exception as e:
        print(f"Failed to read input file: {e}", file=sys.stderr)
        return 1

    y = run_nailong(args.program, k, x, a)
    
    a_modified = a[:]
    a_modified[y - 1] = 1 - a_modified[y - 1]

    if verbose:
        print(f"[System] Nailong chose to flip index y={y}. Original a_{y} was {a[y-1]}, now {a_modified[y-1]}.")

    ans_x = run_bombloong(args.program, k, a_modified)

    # Verification
    if ans_x != x:
        raise WrongAnswer(f"Bombloong answered {ans_x}, but the hidden secret x was {x}.")
        
    print(f"Correct! Bombloong successfully recovered the hidden integer x={x}.", file=sys.stderr)

    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except WrongAnswer as exc:
        print(f"Error: {exc}", file=sys.stderr)
        sys.exit(1)
    except RuntimeError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        sys.exit(1)
