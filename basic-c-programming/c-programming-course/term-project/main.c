#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

int main()
{

    Figure *figs;

    figs = read_commands_defaults("commands.txt", "defaults.txt");

    export_eps(figs);

    return 0;
}