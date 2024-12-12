/* calculating average payment by weekly payment*/
#include <stdio.h>

int main(void)
{
    float weekly_payment = 0.0f;
    float working_hours = 0.0f;
    float average_hourly_pay =0.0f;

    printf("Enter your weekly payment: ");
    scanf("%f", &weekly_payment);
    printf("Enter your working hours: ");
    scanf("%f", &working_hours);
    average_hourly_pay = weekly_payment/working_hours;
    printf("Your average hourly pay is %d dollars and %d cents\n", 
           (int)average_hourly_pay, 
           (int)((average_hourly_pay * 100.0f)) - ((int)average_hourly_pay * 100));
    
    return 0;
}