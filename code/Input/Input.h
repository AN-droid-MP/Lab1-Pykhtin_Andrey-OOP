#ifndef INPUT_H
#define INPUT_H

#include <string>
#include "../Matrix/Matrix.h"

void signalHandler(int signal);

int getInteger(std::istream &in);

#endif //INPUT_H