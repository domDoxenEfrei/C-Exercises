
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
    
    SensorData* data = (SensorData*) calloc(sizeof(SensorData), 10); // Array of struct
    //data contains the address of first element
    
    data->humidity = 10;
    printf("%g\n", data->humidity); //data address is first struct value so use ->
    
    printf("%g\n", data[0].humidity); //data[0] IS the first struct so . 
    
}
