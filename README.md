# BRKDEC
Portable Anti Decompiler Library


**The concept of this project was derived from prior work by [android1337/brkida](https://github.com/android1337/brkida).**

## Disclaimer
This project and all associated materials are provided strictly for authorized red teaming and educational and research purposes only.

This project declares that **it is NOT intended to hinder malware analysis or disrupt DFIR.**

## Executive Summary


## Scope
The scope of this project covers **binaries written in C or C++** for the following operating systems:
* **Windows 11**
* **Windows 10**
* **Ubuntu Linux**

This project aims to develop an anti-reverse engineering library designed against:
* IDA Free
* Ghidra
* Binary Ninja
* RetDec
* RecStudio
* Snowman

## Tools & Environment

### Dev Environment
| Environment           | Information               |
|:----------------------|:--------------------------|
| Operating System      | Ubuntu 24.04.4 LTS        |
| Virtualization Engine | QEMU emulator 8.2.2       |
| Architecture          | Intel x64                 |

### Testing Environment
1. Windows 10 (QEMU virtualized)
2. Windows 11 (Samsung Laptop)
3. Ubuntu 24.04 LTS (Acer Laptop)

## Methodology

### Fundamental Concepts & Definitions
Fundamentally, **commercial decompilers often statically reconstruct C or C-like pseudocode from assembly instructions within a binary.** A decompilation process often looks like this:
* Disassembly
  * Translates machine language into assembly language
  * Recovers function boundaries
  * Identifies code sections and data sections
* Control Flow Analysis
  * Analyzes branches (if)
  * Analyzes loops (for/while)
  * Constructs CFG (Control Flow Graph)
* Data Flow Analysis
  * Abstracts variables from registers
  * Analyzes use of stack and heap memory
  * Transforms IR (Intermediate Representation) into SSA (Static Single Assignment) form
* Type Recovery
  * Identifies integers and pointers
  * Reconstructs structures (struct)
  * Infers function parameters and return types
* High-level Reconstruction
  * Converts condition branches (if/else) to C-like pseudocode
  * Converts loops (for/while) to C-like pseudocode
  * Converts function calls to C-like pseudocode
  * Removes or restructures low-level control flow (e.g., goto)
  * Simplifies expressions
* Symbol Recovery
  * Applies debug symbols (if present)
  * Matches known function names (e.g. libraries)

Control Flow Graph (CFG) is **a graph representation of all possible execution paths (flows) within a function, based on branches, loops, and jump instructions.**

Intermediate Representation (IR) is **an abstract representation of code used between source code and machine language** for program analysis and transformation.

Static Single Assignment (SSA) is **a form of code representation in which each variable is assigned exactly once**, enabling precise data flow analysis.

### Techniques & Strategies 
**Commercial decompilers often cannot precisely determine runtime-dependent values** (e.g., return addresses, timestamps, or environment-dependent data). As decompilers heavily rely on the CFG, **conditional branches that depend on runtime values can be exploited to distort CFG reconstruction, resulting in misleading or junk decompiled output.**

### Validation Method

## Research


## Validation


## Limitations


## References
* [https://github.com/android1337/brkida](https://github.com/android1337/brkida)
* [https://en.wikipedia.org/wiki/Disassembler](https://en.wikipedia.org/wiki/Disassembler)
* [https://en.wikipedia.org/wiki/Control-flow_graph](https://en.wikipedia.org/wiki/Control-flow_graph)