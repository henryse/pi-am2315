#include <printf.h>
#include "pi_am2315.h"

int main() {

    int fd = pi_am2315_open();

    if (fd == -1)
    {
        printf("pi_am2315_open failed\n");
        return 0;
    }
    float temperature = 0;
    float humidity = 0;

    pi_am2315_readTemperatureAndHumidity(fd, &temperature, &humidity);
    printf("hello world %f, %f", temperature, humidity);

    return 0;
}