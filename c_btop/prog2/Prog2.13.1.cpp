#include <stdio.h>

int main() {
    char ch = 0;
    
    printf("Debug: About to read character...\n");
    printf("Please enter a character: ");
    
    if (scanf("%c", &ch) != 1) {
        printf("Debug: Failed to read character\n");
        return 1;
    }
    
    printf("Debug: Successfully read character\n");
    printf("The character is %c and the code value is %d\n", ch, ch);
    
    return 0;
}