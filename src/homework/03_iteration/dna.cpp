#include "dna.h"
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string & sequence)
{
	double count = sequence.length();
	double gc_count = 0;

	for (int i = 0; i < sequence.length(); ++i)
	{
		if (sequence[i] == 'G' || sequence[i] == 'C') {
			gc_count++;
		}
	}

	double gc_content = gc_count / count;
	
	return gc_content;
}

/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string sequence)
{
	string reverse = "";
	for (std::size_t i = sequence.length(); i != 0; --i) 
	{
		reverse += sequence[i-1];
	}

	return reverse;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
string get_dna_complement(string sequence)
{
	string reversed_dna = get_reverse_string(sequence);

	for (char &letter : reversed_dna) {
		switch (letter) {
			case 'C':
				letter = 'G';
				break;
			case 'G':
				letter = 'C';
				break;
			case 'A':
				letter = 'T';
				break;
			case 'T':
				letter = 'A';
				break;
			default:
				break;
		}
	}

	return reversed_dna;
}
