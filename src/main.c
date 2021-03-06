/**********************************************************************
//    Copyright (c) 2016 Henry Seurer & Samuel Kelly
//
//    Permission is hereby granted, free of charge, to any person
//    obtaining a copy of this software and associated documentation
//    files (the "Software"), to deal in the Software without
//    restriction, including without limitation the rights to use,
//    copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the
//    Software is furnished to do so, subject to the following
//    conditions:
//
//    The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//    OTHER DEALINGS IN THE SOFTWARE.
//
**********************************************************************/

#include <stdio.h>
#include "pi_am2315.h"

int main() {

    int fd = pi_am2315_open();

    if (fd == -1) {
        printf("{\"error\": \"pi_am2315_open failed\"}\n");
        return -1;
    }
    float temperature = 0.0;
    float humidity = 0.0;

    bool success = false;
    for (int retry = 3; 0 < retry; retry--){
        success = pi_am2315_readTemperatureAndHumidity(fd, &temperature, &humidity);

        if (success){
            break;
        }
    }

    if (success) {
        printf("{\"temperature\": \"%f\", \"humidity\": \"%f\"}\n", temperature, humidity);
        return 0;
    }
    else {
        printf("{\"error\": \"crc failed\", \"temperature\": \"%f\", \"humidity\": \"%f\"}\n", temperature, humidity);
        return -1;
    }
}