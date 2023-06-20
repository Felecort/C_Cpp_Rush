# Memory allocation  
`new` for single value and `new []` for arrays  
`delete` for single value and `delete []` for arrays  

`int (*)m = new int (5)`  
`delete m`  

`int *m = new [N]`  
`delete [] m`  

Существует мнемоническое правило, позволяющее легко запомнить, к чему относится const. Надо провести черту через "*", если const слева, то оно относится к значению данных; если справа — к значению указателя.



# Multidimentions type cast  
![alt text for screen readers](/.images/array_types_cast.png "Functions")  
