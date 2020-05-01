#pragma once
#include <iostream>

using namespace std;

class Array {

private:  
	int *A;
	int size;
	int length;

void swap(int *x,int *y);

public:   
	Array()
{  size=10;
   length=0;
   A=new int[size];
}
 Array(int sz)
 {
	 size=sz;      
	 length=0;      
	 A=new int[size];   
 }
 ~Array(){  delete []A; } 

 void display();  
 void append(int x); 
 void insert(int index,int x); 
 int remove(int index);  

 int linearSearch(int key); 
 int binarySearch(int key);  

 int get(int index);
 void set(int index,int x);

 int max();
int min();  
int sum();   
float avg();  

void reverse();  
void insertSort(int x);  
int isSorted(); 
 

Array* merge(Array arr2);  
Array* Union(Array arr2);  
Array* difference(Array arr2); 
Array* intersection(Array arr2); };