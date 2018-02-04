# The Completionist No. 1 - Brainfuck Interpreter

"The Completionist" aims to be a collection of projects that aim to be completed relatively fast, while learning. In the first installment of the series, a Brainf*ck interpreter. To learn more about what this is, you can check https://en.wikipedia.org/wiki/Brainfuck

## Assumptions

We follow the more traditional Brainf*ck definition (or try to)

* Signed 8-bit memory cells
* 30000 memory cells
* No limit on jump nesting

## Contents

Apart from the source code and a Visual Studio 2015 solution, the project contains several examples of Brainf*ck programs under the "Examples" folder. All of them have been tested with the interpreter. You can also contribute examples as the aim is to build a collection as extensive as possible.

## Usage

StuBF.exe program.bf

## How to contribute programs

Add them in the folder examples and in the list below. Then check if they work, and if not raise an issue.

## List of Example Code

* **A.bf** prints the character "A" on the standard output.
* **HelloWorld.bf** prints the traditional "Hello World!" message to the standard output.
* **TestOverflow.bf** a test program that outputs the size of each memory cell.
* **Sierpinski.bf** prints the Sierpinski triangle.
* **Rot13.bf** does Rot-13 "encryption" on the text from standard input. Press Ctrl-C to end.

## License

MIT License

Copyright (c) 2018 David Gil de Gómez Pérez (Studiosi)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.