#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>

struct gpiod_chip *chip; 
struct gpiod_line *ledLine;   

int main(void) { 

    static const char *const chip_path = "/dev/gpiochip4"; // selection of gpio bank
    int i;

    chip = gpiod_chip_open(chip_path);
    if (!chip) {
		printf("could not open chip\n");
        return 0;
    }

    ledLine = gpiod_chip_get_line(chip, 26); // selection of gpio line, this case 0xD2 = 26
    if (!ledLine) {
		printf("could not get line\n");
        return 0;
    }

    gpiod_line_request_output(ledLine, "example1", 0); // request for change of role to output

    i = 0;
    while (true) {
        
        gpiod_line_set_value(ledLine, (i & 1) != 0); // setting value of line
        
        usleep(1000000);
        i++;
  }

    return 0;
}