/*
Read the following code and tell what is the various variable values in the program after a given line has been executed

expression:n1
line n°:4

expression:n2
line n°:4

expression:v3
line n°:11
*/

int combine(int n1, int n2){
    
    
    int result = n1 + n2 * 2;
    return result;
}

void main(){
    
    int v1 = 2;
    int v2 = 3;
    int v3 = combine(v1, v2);
}