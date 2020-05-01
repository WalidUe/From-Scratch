#include "Array.h"

void Array::display()
{
	int i; 
	cout << "\nElements are"<<endl;   
	for (i = 0; i < length; i++)     
		cout << A[i] << " "; 
}


void Array::append(int x) 
{ 
	if (length < size)    
		A[length++] = x;
} 

void Array::insert(int index, int x) 
{
	int i;    
	if (index >= 0 && index <= length)
	{
		for (i = length; i > index; i--)      
			A[i] = A[i - 1];   

		A[index] = x;    
		length++;
	}
} 

int Array::remove(int index)
{ 
	int x = 0;  
	int i;    
if (index >= 0 && index < length) 
{ 
	x = A[index];  

	for (i = index; i < length - 1; i++)         
		A[i] = A[i + 1];  

	length--;  
	return x; 

}  

return 0; 
}

void Array::swap(int* x, int* y)
{
int temp;  
temp = *x; 
*x = *y;  
*y = temp; 
} 

int Array::linearSearch(int key) {
	int i;  
	for (i = 0; i < length; i++)
	{ 
		if (key == A[i]) 
		{ 
			swap(&A[i], &A[0]);  
	return i; 
		} 
	}  
return -1;
} 

int Array::binarySearch(int key) {
int l, mid, h;  
l = 0;  
h = length - 1; 

	while (l <= h) 
	{
		mid = (l + h) / 2;     
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}   

	return -1;
}

int Array::get(int index) 
{
	if (index >= 0 && index < length)   
		return A[index];  

return -1;
}

void Array::set(int index, int x)
{ 
	if (index >= 0 && index < length)     
		A[index] = x;
} 

int Array::max()
	{

	int max = A[0];  
	int i;  

	for (i = 1; i < length; i++)
	{
		if (A[i] > max)     
			max = A[i];
	}    return max;


} 

int Array::min()
{ int min = A[0]; 

int i;  
for (i = 1; i < length; i++)
{
	if (A[i] < min)
		min = A[i];
}
return min;
}

int Array::sum() {
	int s = 0;  
	int i;  
for (i = 0; i < length; i++)     
	s += A[i];   

return s; } 

float Array::avg() 
{ 
	return (float)sum() / length;
} 



void Array::reverse() 
{
	for (int i = 0; i < length / 2; i++)
	{
		swap(&A[i], &A[length - 1 - i]);
	}

} 

void Array::insertSort(int x) 
{
	int i = length - 1; 
if (length == size)      
	return;  

while (i >= 0 && A[i] > x) 
{
	A[i + 1] = A[i];   
	i--;
}
A[i + 1] = x;  
length++;
} 

int Array::isSorted() 
{ 
	int i; 
for (i = 0; i < length - 1; i++) 
{
	if (A[i] > A[i + 1])        
		return 0;
}    return 1; 
}


Array* Array::merge(Array arr2)
{ 
	int i, j, k;  
	i = j = k = 0;     
Array* arr3 = new Array(length + arr2.length);    
while (i < length && j < arr2.length)
{
	if (A[i] < arr2.A[j])
		arr3->A[k++] = A[i++];
	else
		arr3->A[k++] = arr2.A[j++];
}
for (; i < length; i++)
	arr3->A[k++] = A[i];
for (; j < arr2.length; j++)
	arr3->A[k++] = arr2.A[j];

arr3->length = length + arr2.length;

return arr3;

} 
Array* Array::Union(Array arr2)
{
	int i, j, k;    i = j = k = 0;     
	Array* arr3 = new Array(length + arr2.length);        
	while (i < length && j < arr2.length)
	{

		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}   
	for (; i < length; i++)      
		arr3->A[k++] = A[i];   
	for (; j < arr2.length; j++)    
		arr3->A[k++] = arr2.A[j];   

	arr3->length = k;  

	return arr3;
} 

Array* Array::intersection(Array arr2) {

	int i, j, k;   
	i = j = k = 0;      
	Array* arr3 = new Array(length + arr2.length);    
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			i++;     
		else if (arr2.A[j] < A[i])       
			j++;        
			else if (A[i] == arr2.A[j]) 
		{ 
			arr3->A[k++] = A[i++]; 
		j++; 
		}
	}        
	arr3->length = k;    

	return arr3;
} Array* Array::difference(Array arr2) 
{
	int i, j, k;  
	i = j = k = 0;     
	Array* arr3 = new Array(length + arr2.length);  
	while (i < length && j < arr2.length)
	{ 
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];

		else if (arr2.A[j] < A[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}   
	for (; i < length; i++)     
		arr3->A[k++] = A[i];
	arr3->length = k; 

	return arr3;
}
