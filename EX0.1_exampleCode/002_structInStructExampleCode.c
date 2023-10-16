
typedef struct Coordinate{
    
    float x,y,z;
    
} Coordinate; //Coordinate is a custom type


typedef struct SensorData{
    
    float temperature;
    float pression;
    float humidity;
    
    Coordinate position; //struct inside struct
    
} SensorData;

void test_main(){
    
    SensorData d1; //Stack allocation
    d1.temperature = 22;
    d1.pression = 0.4;
    d1.humidity = 0.7;
    //struct in struct -> access member with . 
    d1.position.x = 0.5;
    d1.position.y = 0.5;
    d1.position.z = 0.5;
    
    printf("%g\n", d1.position.z);
    
    SensorData* d_p_1 = &d1;
    
    printf(
        "temp from pointer : %g, x from pointer : %g\n", 
        d_p_1->temperature,
        d_p_1->position.x  // d_p_1 is a pointer so ->position. But ->position is not pointer ->position is a Coordinate struct
    );
    
}
