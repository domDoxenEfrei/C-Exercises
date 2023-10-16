
typedef struct Coordinate{
    
    float x,y,z;
    
} Coordinate; //Coordinate is a custom type


void forbidden_use_of_pointer_memory(){
   
    //creating a single variale of type Coordinate;
    //type     variablename
    Coordinate c1;
    c1.x = 1;
    c1.y = 3;
    c1.z = 1.1;
    
    
    //Creating a pointer Only allocate memory for the pointer (adress)
    //Coordinate pointer
    Coordinate* coordinate_pointer1; //pointer adress is somewhere random in memory
    printf("%g\n", coordinate_pointer1->x);
    coordinate_pointer1->x = 2.2;
    printf("%g\n", coordinate_pointer1->x);
}

void test_main(){
    
    Coordinate c1; //Stack allocation
    c1.x = 1;
    c1.y = 3;
    c1.z = 1.1;
    //store the address of c1 (already allocated (STACK)
  
    Coordinate* coordinate_pointer1 = &c1; 
    
    //-> is same as deferencing the struct adress and
    //access the member
    coordinate_pointer1->x = 100;
    //both value are the same
    printf("%g same as %g\n", coordinate_pointer1->x, c1.x);
    
}
