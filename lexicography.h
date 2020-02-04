#include<iostream>

using namespace std;

struct strin {
	string str;
	int val;
}st[20];


int n, ele;

//heapify function
void heapify(int idx, int max) {
	string temp;
	int left, right, lar;
	left = 2 * idx + 1; //declaring left child
	right = 2 * idx + 2;  //declaring right child
	//looking for larger element
	if (left < max && st[left].val > st[idx].val) {
		lar=left;
	}
	else lar=idx;
	if (right < max && st[right].val > st[lar].val) {
		lar=right;
	}
	//swapping the large funcion with the beginning element
	if (lar != idx) {
		st[idx].val=st[idx].val+st[lar].val-(st[lar].val=st[idx].val);
		temp=st[lar].str;
		st[lar].str=st[idx].str;
		st[idx].str=temp;
		heapify(lar, max);
	}
}
//minheap function
void minheap(int no, int j) {
	string temp;
	//dividing problem into two subarrays
	for (int i=(no/2-1); i>=j; i--) {
		heapify(i, no);
	}
	for (int i=no-1; i>=1; i--) {
		st[j].val=st[j].val+st[i].val-(st[i].val=st[j].val);
		temp=st[i].str;
		st[i].str=st[j].str;
		st[j].str=temp;
		//calling heapify function
		heapify(j, i);
	}
}


int findfl(int j, int l) {
	int start=-1;
	ele++;
	int last;
	while (j<l-1) {
		loop:
		if (st[j].val==st[j+1].val) {
			if (start==-1) {
				start=j;
			}
			last=j+1;
			j++;
			goto loop;
		}
		if (start!=last && start>-1) {
			for (int count=start; count<=last; count++) {
				st[count].val=st[count].str[ele];
			}
			minheap(last+1, start);
			ele = findfl(start, last+1);
			start=-1;
		}
		j++;
	}
	return ele;
}

