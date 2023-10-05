#include "pch.h"

#include <loguru.hpp>

int main(int argc, char** argv)
{
    loguru::init(argc, argv);
    LOG_F(INFO, "Hello, world!");

    return 0;
}
