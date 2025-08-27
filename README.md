<h1 align="center">String Plus</h1>

<h3 align="center">Implementation of the string.h library & sprintf function from the stdio.h</h2>

> In this team project I implemented `sprintf` function.

<h2>Table of Contents</h2>

- [Features](#features)
- [Tech Stack](#tech-stack)
- [Project Experience](#project-experience)

<h2 id="features">Features</h2>

- `sprintf` behaves like the standart function from the `stdio.h` library.
- `sprintf` accepts a format specifier with the following prototype: `%[flags][width][.precision][length]specifier`.
- Supported `[flags]`: `-, +, (space).
- Supported `[length]`: h, l.
- Supported `[specifier]`: c, d, f, s, u, %.

<h2 id="tech-stack">Tech Stack</h2>

- Languages: C (C11).
- Libraries: Standart C Libraries, string.h, stdarg.h.
- Build System: Makefile.
- Unit Testing: check.h (C library).
- Version Control: git.

<h2 id="project-experience">Project Experience</h2>

In this project I consolidated structured programming & Dijkstra's principles.

I practised:
- Version Controlling with git in the team.
- Writing unit tests using AAA pattern.
- Handling variadic function arguments.
- Clean code principles and practices:
	- Single Responsibility Principle (SRP): each function performs a single responsibility.
	- Open/Closed Principle: while the sprintf functionality is closed for modification once implemented, it's open for extension through adding new format specifiers and modifiers incrementally.
	- Separation of Concerns: Functional decomposition separates concerns effectively. Parsing, formatting, and output generation steps are distinct.
	- D.R.Y. (Don't Repeat Yourself): avoid duplicated code blocks.
	- Code is self-explanatory and easily readable.
		- The function names reflects their implementation.
		- Magic numbers were replaced with the enums and constants to enhanse readability.
		- Arguments and return types clearly communicate intent, avoiding implicit assumptions.
		- The code was written according to [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
	- Error Handling: solution prevents crashes or undefined behaviors.
	- Modular design allows future enhancements (like supporting additional format specifiers) without disrupting existing functionality.