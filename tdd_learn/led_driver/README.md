Author: 	Pradeepa Senanayake
Date: 		22-11-2015
Version:	1.0 - Initial setup
ChangeLog:

Description:

This folder structure is prepared to make it easy for anyone to exercise TDD using Unity when developing Embedded Applications in C. 

Intended usage of folders as follows,

src - Production code source
inc - Production code headers
library - Production code libraries

tests - Folder which contains all the tests and the main test runner (AllTests.c)
tests/groupX - Rename the groupX according to the required test group. Idea here is to properly segment the tests into welldefined groups.
tests/unity.framework - Folder contains the Unity source files. (Do not change the files inside the folder)
tests/lib - Contains the test related library files (This folder will be created during the make)

-------------------------------------------

Mainly there are two Makefiles in this folder structure.

Makefile - Main makefile to be used for Production code

tests/Makefile - Makefile which includes another .mk file to configure and run the tests. This Makefile needs to be executed to run the TDD tests.

tests/MakefileUnity.mk - Need to specify the all the directories which contains the source files of TESTs and the Production code.

----------------------------------------------



