#include <cstdio>
/*
Insertion sort with steps printing.
*/

#include <cstdio>

void printArray(int ar_size, int* ar){    
    for(int i=0;i<ar_size;++i){
        char s;
        if(i!=ar_size-1)
            s=' ';
        else s='\n';        
        printf("%d%c",*ar++,s);
    }                         
}
void insertionSort(int ar_size, int *  ar) {
    if(ar_size<2){
        printArray(ar_size,ar);
        return;
    }
    for(int i=1;i<ar_size;++i){
        int x = ar[i];
        int j = i;
        while(j>0 && ar[j-1]>x){
            ar[j] = ar[j-1];
            --j;       
        }
        ar[j]=x;
        printArray(ar_size,ar);
    }
}
int main(void) {
   
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}
