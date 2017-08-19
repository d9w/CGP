cgp version 1.1
Author: Julian Miller

Date: 20 July 2009

Comments
---------

First public release of cgp program (version 1.1)

Necessary files
cgp.c
cgp.h
cgp-functions.c
node-function.c

cgp.c
-----

This contains the main function 

cgp-functions.c
---------------

This lists all function implementations in the code except for the
function defining node type

cgp.h
-----

This lists all defined data_types (see later for more details), defined constants
global variables and function prototypes

node-function.c
---------------

this gives the implementation of the cgp node functions. 

Compile instructions
--------------------

I compile the code in Microsoft C++ version 6.0 but it is written in ANSI C so should compile
in a variety of C compilers.

Place the cgp-functions.c, cgp.c, node-function.c in a source file directory and cgp.h in a header file directory.


Instructions for use
--------------------

cgp version 1.1 allows for three types of data to be used in cgp. 
The data type is defined using the defined variables

/*
#define DATA_IS_UNSIGNED_INT
#define DATA_IS_INT
#define DATA_IS_DOUBLE
*/

So when using the program (before compiling) you must decide what data type
you need for your application.

You uncomment the data type definition you need. For example

/*
#define DATA_IS_UNSIGNED_INT
#define DATA_IS_INT
*/

#define DATA_IS_DOUBLE

this means that the data being processed will be double (floating point numbers)

once one of these defined variables are uncommented a number of compiler directives are invoked
and the compiled code because becomes dedicated to that data type.

The functions that CGP can use are defined in node-function.c. 
If you want to add some more functions you will need to modify these to suit. The cgp program assumes that
the maximum number of possible functions that could be chosen is defined by

#define MAX_NUM_FUNCTIONS 20

This is currently 20. If you need more you will have to change this and alter the functions defined in 
node-functions.c. You will also have to edit the parameters files (see shortly) as these assume a maximum 
of 20 functions also.

Running cgp program after compiling
---------------------------

The command line instruction to run cgp looks like

For data_type UNSIGNED_INT

cgp cgp-boolean.par file.plu

file.plu is a 32-bit compression of a boolean truth table. The reason for doing this
is that the processor chip can do 32 bits simultaneously (some do 64 but this has not been implemented).

For example mult2.plu encodes the truth table of a 2-bit parallel Boolean multiplier.

It looks like

.i 4
.o 4
.t 1
65280 61680 52428 43690   32768 19456 27328 41120 
.e

It encodes

.i 4
.o 4
.t 16
0000 0000
0001 0000
0010 0000
0011 0000
0100 0000
0101 0001
0110 0010
0111 0011
1000 0000
1001 0010
1010 0100
1011 0110
1100 0000
1101 0011
1110 0110
1111 1001
.e

65280 is the 16 bit binary number 1111111100000000 (read the first input variable of the truth table) 
from bottom to top.
 
cgp-boolean.par looks like (all .par files have a similar format, but functions are different)

5         population_size
3.0       per_cent_mutate
10000      num_generations
1        num_runs_total
1         num_rows
20        num_cols
20        levels_back
1	    progress_report
1000      report_interval
173156789 global_seed
0         save_best_chrom
0         run_from_chrom
0         shrink_phenotype
0  0       '0'-0
0  0       '1'-1
0  1       a-2
0  1       b-3
0  1       !a-4
0  1       !b-5
1  2       ab-6
1  2       a!b-7
0  2       !ab-8
0  2       !a!b-9
1  2        a^b-10
0  2       !a^b-11
0  2       a|b-12
0  2       a|!b-13
0  2       !a|b-14
0  2       !a|!b-15
0  3       mux-16
0  3       mux-17
0  3       mux-18
0  3       mux-19

population_size
A population size of 5 (or lower) is recommended when running cgp.

pre_cent_mutate 
This decides how many genes per genotype are mutated. Usually
the number of genes mutated should be a relatively small number (but it needs to rise, slightly with increasing
numbers of genes). For say 300 genes 1% mutation is recommended, this rate should decreases with increasing length
of the genotype.

num_generations
How many generations you want to run the EA for 

num_runs_total
Ho many independent EA runs you wish to have

num_rows
number of rows of nodes (usually set to 1)

num_cols
number of columns of nodes (when num_rows is 1, this is the *maximum* number of nodes you want)

levels_back
this is how many levels back a node in one column can connect to. Usually this is set
to num_cols

progress_report
When set to 1, this switches on verbose progress reporting. It will mean that for each evolutionary run 
a complete history of each generational improvement will be written to a file cgp<run>.prg. Also
progress reporting will be written to the Command prompt window. When doing lots of runs for statistics
gathering it is recommended that this parameter is set to 0.


report_interval
This decides when the program prints how many generations have elapsed

global_seed
A user defined global seed. This seeds the random number generator. Repeated experiments
with the same parameters and seed produce identical results.

save_best_chrom
When set to 1 this saves the best genotype found in all runs to a file called cgp.chr
when set to zero, the program does not save the genotype.

run_from_chrom
When set to 1, this allows evolution to begin with a given genotype (e.g. cgp.chr) you must ensure
that the number of genes defined in the parameters file (.par) is the same as the number of genes
that are in the file cgp.chr (otherwise the program will detect an error and halt the run.

shrink_phenotype
When set to 1, this allows the evolutionary algorithm to run past the point when a perfect solution
is found. The EA tries to minimize the number of active nodes in a perfect program. This is useful
if you want small solutions to your problem. It is only useful when the parameters have been set
so that perfect solutions are found reasonably quickly so that there is time for the EA to mimimize
the number of active nodes.

0  0       '0'-0
0  0       '1'-1
0  1       a-2
0  1       b-3
0  1       !a-4
0  1       !b-5
1  2       ab-6
1  2       a!b-7
0  2       !ab-8
0  2       !a!b-9
1  2        a^b-10
0  2       !a^b-11
0  2       a|b-12
0  2       a|!b-13
0  2       !a|b-14
0  2       !a|!b-15
0  3       mux-16
0  3       mux-17
0  3       mux-18
0  3       mux-19

To choose a function in your function set, set the leftmost field to 1. The second field
declares the arity of the function used. The third field is a string describing the actual 
node function and which address (function_gene) that cgp will use for it. So here three functions
are used  AND(first_input, second_input), AND(first_input, NOT(second_input)) and XOR(first_input, second_input).
These functions will be given the function addresses, 6, 7 and 10 in the genotype.


For data_type INT

cgp cgp-int.par file.dat

for example cgp-int.par might look like

5         population_size
6.0       per_cent_mutate
2      num_generations
1        num_runs_total
1         num_rows
15        num_cols
15        levels_back
1	    progress_report
1000      report_interval
173156789 global_seed
0         save_best_chrom
1         run_from_chrom
0         shrink_phenotype
1  2      addition-0
1  2      subtraction-1
1  2      multiplication-2
1  2      division-3
0  2      addition-4
0  2      subtraction-5
0  2      multiplication-6
0  2      division-7
0  2      addition-8
0  2      subtraction-9
0  2      multiplication-10
0  2      division-11
0  2      addition-12
0  2      subtraction-13
0  2      multiplication-14
0  2      division-15
0  2      addition-16
0  2      subtraction-17
0  2      multiplication-18
0  2      division-19

For the int data type, CGP has only four node functions defined: addition, subtraction, multiplication 
and division (protected). 

A sample .dat file is provided below. It is called primes.dat and lists prime numbers and their index.

.i 1
.o 1
.t 5
1 2
2 3
3 5
4 7
5 11
6 13
7 17
8 19
9 23
10 29

and so on.

when the program command line is

cgp cgp-int.par primes.dat

the cgp program will attempt to find a formula that predicts the number of consecutive primes defned by
the number after ".t" (i.e. 5). If you have an integer problem having more than one input and output you 
need to adjust the numbers after ".i" and ".o" to suit your problem. You then need to supply a table of data
values in the above format.

For data_type double

cgp cgp-double.par file.dat

for example cgp-double.par might look like

5         population_size
0.5       per_cent_mutate
100      num_generations
1        num_runs_total
1         num_rows
200        num_cols
200        levels_back
1	    progress_report
1000      report_interval
173156789 global_seed
0         save_best_chrom
0         run_from_chrom
0         shrink_phenotype
0  1      modulus-0
0  1      sqrt-1
0  1      reciprocal-2
0  1      sin-3
0  1      cos-4
0  1      tan-5
0  1      exp-6
0  1      sinh-7
0  1      cosh-8
0  1      tanh-9
0  1      nat-log-10
0  1      logbase10-11
0  2      sin(a+b)-12
0  2      cos(a+b)-13
0  2      hypoteneuse-14
0  2      power-15
1  2      addition-16
1  2      subtraction-17
1  2      multiplication-18
1  2      division-19


So you see that 20 mathematical functions are provided and can be chosen from.

For example to tackle the symbolic regression problem koza-quintic ( a polynomial)

.i 1
.o 1
.t 21
-1.0	0.0
-0.9	-0.03249
-0.8	-0.10368
-0.7	-0.18207
-0.6	-0.24576
-0.5	-0.28125
-0.4	-0.28224
-0.3	-0.24843
-0.2	-0.18432
-0.1	-0.09801
0.0	0.0
0.1	0.09801
0.2	0.18432
0.3	0.24843
0.4	0.28224
0.5	0.28125
0.6	0.24576
0.7	0.18207
0.8	0.10368
0.9	0.03249
1.0	0.0
.e

This is a table of 21 values of the independent variable x and the polynomial x^5 - 2x^3 + x

So using the command

cgp cgp-double.par koza-quintic-polynomial.dat

with the data type double selected, will make the cgp program try to evolve a formula that 
gives the same output as the polynomial.

CGP chromosome printing
-----------------------

In some of the files generated by the cgp program a genotype is output in which non-coding genes
are represented by *. For example the geneotype below was evolved using num_rows = 1, num_cols = 10
and levels_back = 10. It represents a correct 2-bit multiplier (data type UNSIGNED_INT)

(0,3,[6]:4)	(1,2,[6]:5)	(4,5,[6]:6)	(5,4,[10]:7) (2,6,[6]:8) (0,2,[6]:9) (*,*,[*]:10) (9,8,[7]:11) (*,*,[*]:12)	(3,1,[6]:13) 6 11 7 13

The first node has genes 0 3 6. This means that it is connected to input 0 and input 3 (inputs columns in
mult2.plu) and the node function is AND (the address of an AND gate). the number after the colon
is the address of the data the node outputs (addresses 0 to 3 are input data) so the first node
has an address 4.

The nodes with addresses 10 and 12 are not used (i.e. they are non-coding) and all their genes
are represented by * to indicate this. This helps when one is writing out an expression
for the cgp program.

Other output files produced by the program
-------------------------------------------

The program always produces a text file cgp.txt that summarizes the results. It contains a few statistics.

It always saves the best chromosome of all the runs in cgp.chr.



Number of inputs to the cgp chromosome (added 13 June 2013)
--------------------------------------

In the file cgp.h there is the line

#define MAX_NUM_CONSTANT_INPUTS 3

This refers to how many extra constant inputs the evolved program is assumed to have.

in the function read_data, that reads in the data supplied in either the .plu or .dat files you will see the lines

	#ifdef DATA_IS_UNSIGNED_INT
		num_constant_inputs = 0;
	#endif
	#ifdef DATA_IS_INT
		num_constant_inputs = MAX_NUM_CONSTANT_INPUTS;
	#endif
	#ifdef DATA_IS_DOUBLE
		num_constant_inputs = MAX_NUM_CONSTANT_INPUTS;
	#endif
	num_inputs = num_inputs + num_constant_inputs;

So you can see that the actual number of inputs used is the number of inputs read from the .plu or .dat file PLUS the
number of constant inputs.

The values given to the constant inputs are defined in the function that decodes the chromosome (decode_cgp)

	data_type constant_inputs[MAX_NUM_CONSTANT_INPUTS] = {1, 2, 3};

So if you don't want any constants then change the line in the cgp.h file to

#define MAX_NUM_CONSTANT_INPUTS 0

If you want different constants then assign your own values to the array that holds the constant inputs (constant_inputs)




