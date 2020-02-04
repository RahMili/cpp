#include<iostream>
//attaching the lexigography header file
#include"lexicography.h"
#include<cstring>
#include<fstream>
using namespace std;

//main function
int main()
{
	int j=0, i=0, m=0;
	string data;
	ifstream input("input.txt");
	//taking input from the input.txt file
	while(!input.eof()) {
		input >> st[i].str;
		char c= st[i].str[ele];
		st[i].val=c;
		i++;
	}
	n=i;
	i=0;
	minheap(n, 0);
	ele=findfl(0, n);
	
	ofstream file1;
	file1.open("output.txt");
	cout << "The strings in lexicographic order : ";
	//sending output to output.txt file
	for (int i=0; i<n; i++) {
		file1 << st[i].str << " ";
	}
	file1.close();
	input.close();
	//printing the output.txt file
	ifstream print("output.txt");
	print>>data;
	while (!print.eof()) {
		cout << data << " ";
		print >> data;
	}
}
