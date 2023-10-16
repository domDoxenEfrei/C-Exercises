
typedef struct SensorData{
    
    float temperature;
  
    struct SensorData* next;//this member means we are using SensorData as a Linked list

} SensorData;

void stack_allocated(){
     SensorData d1, d2, d3; //stack allocated
    d1.temperature = 22;
    d2.temperature = 33;
    d3.temperature = 44;
    
    //I want a three value linked list
    //d1->d2->d3

    //d1 act as the head of LinkedList
    d1.next = &d2; //next contains addres of d2
    d2.next = &d3; //next contains address of d3

    //Let's access d3 data from d1 !!
    
    printf("%g\n", d1.next->next->temperature); //d1 is a struct so . But d1.next is pointer so -> d1->next->next is pointer!
    
    //Let's have a pointer which represents the head of Linked list
    SensorData* head = &d1; //dedicated variable to get the Head of LL
    
    printf("%g\n", head->next->next->temperature);
}

void test_main(){
    
    
    SensorData* head = (SensorData*) calloc(sizeof(SensorData), 1); //heap allocation -> data stays after end of function
    
    head->next = (SensorData*) calloc(sizeof(SensorData), 1);
    head->next->next = (SensorData*) calloc(sizeof(SensorData), 1);
    
    head->next->next->temperature = 222;
    
    printf("%g\n", head->next->next->temperature);
    
}
