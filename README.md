# BRKDEC
Lightweight Anti-Decompiler Library


The concept of this project was derived from prior work:  [android1337/brkida](https://github.com/android1337/brkida)


## Disclaimer
This project and all associated materials are provided **strictly for authorized red teaming and educational and research purposes only.**

This project declares that **it is NOT intended to hinder malware analysis or disrupt DFIR.**


## Executive Summary
BRKDEC is a lightweight anti-decompiler library designed to disrupt static analysis by exploiting fundamental limitations in control flow reconstruction of known commercial decompilers, ultimately to protect sensitive binaries from being reverse engineered.


## Purpose
The ultimate goal of this project is to analyze the decompilation process of commercial decompilers, identify their limitations, and thereby develop anti-decompilation techniques. This project is a research initiative developed to investigate anti-decompilation techniques by combining ideas from [android1337/brkida](https://github.com/android1337/brkida) with an anti-decompilation technique originally studied in the FrontierGuard project (temporary discontinued).


## Scope
The scope of this project covers **binaries written in C or C++** which can be reverse engineered with the following decompilers/reverse engineering toolkits:
* IDA Free
* Ghidra
* Binary Ninja

The outcome of this project will be tested on the binaries for the following operating systems:
* Windows 11
* Windows 10
* Ubuntu Linux

### Out Of Scope
- Packed or self-modifying binaries
- Kernel-mode drivers
- Heavy obfuscation frameworks (e.g., VM-based obfuscation)


## Tools & Environment

### Dev Environment
| Environment           | Information               |
|:----------------------|:--------------------------|
| Operating System      | Ubuntu 24.04.4 LTS        |
| Virtualization Engine | QEMU emulator 8.2.2       |
| Architecture          | Intel x64                 |

### Testing Environment
1. Windows 10 (QEMU virtualized)
2. Ubuntu 24.04 LTS (Acer Laptop)

### Compilers
* Windows Compiler
  * x86_64-w64-mingw32-gcc (GCC) 13-win32
* Ubuntu Compiler
  * Ubuntu clang version 18.1.3 (1ubuntu1)


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
To demonstrate the effectiveness of the outcomes, simple samples written in C and C++ will be divided into two groups: those with BRKDEC applied and those without. First, for a quick inspection, the samples will be uploaded to [Decompiler Explorer](https://dogbolt.org/) to examine the decompilation results, allowing comparison and analysis of the actual decompiled outputs. Second, for a more detailed inspection, IDA Free, Ghidra (+ Cutter), and Binary Ninja will be used to directly compare and analyze the decompilation results.

### Validation Standards
- Pseudocode readability
- Variable recovery accuracy
- Function boundary accuracy

### Validation Assumption
- The compiled binary does not contain debug symbols


## Research

### Function Boundary Obfuscation
Through three days of experimentation, I have observed that when the return adddress is manipulated to cause an abnormal transfer of execution flow between functions, commerical decompilers fail to precisely track the actual execution path.

This technique exploits the assumption made by decompilers that normal call/return operations occur within a function. Typically, a decompiler constructs a CFG on an intra-procedural basis, assuming that each function has an identifiable entry point and a `ret`-based termination/return point.

However, when the return address is manipulated such that a called function (e.g. printf in libc) transfers execution flow to a function other than the original caller, the actual execution flow continues across function boundaries. This creates a discrepancy between the CFG constructed by the decompiler and the actual execution flow, ultimately resulting in a function boundary detection failure.

![BRKDEC_FUNC_BOUNDARY](./rsrc/function_boundary/BRKDEC_FUNC_BOUNDARY.png)

[Ret2 Reverse Engineering Blog](https://blog.ret2.io/2017/11/16/dangers-of-the-decompiler/) also introduced a related technique. In that blog post, an exploit-like stack pivoting technique was demonstrated using a ROP chain embedded within the binary to achieve return hijacking.

The research presented in that blog focused on malware and anti-decompilation techniques. In contrast, this research focuses more on lightweight anti-decompilation methods.

### Pseudocode Obfuscation

### Variable Obfuscation


## Validation


## Limitations


## References
ChatGPT, Gemini, and DeepSeek were used to improve the technical English expressions in this document.

* [https://github.com/android1337/brkida](https://github.com/android1337/brkida)
* [https://en.wikipedia.org/wiki/Disassembler](https://en.wikipedia.org/wiki/Disassembler)
* [https://en.wikipedia.org/wiki/Control-flow_graph](https://en.wikipedia.org/wiki/Control-flow_graph)
* [https://blog.ret2.io/2017/11/16/dangers-of-the-decompiler/](https://blog.ret2.io/2017/11/16/dangers-of-the-decompiler/)