
#include <stdio.h>

#include "FileStream.hpp"
#include "FileStreamListener.hpp"

int main(int argc, char** argv)
{
    FileStream fs("test.txt");
    FileStreamListener fsl;

    fs.AddListener(&fsl);

    fs.Write("Some test data to write to file!");

    std::string data;

    fs.Read(data);

    printf("\nData read from file: \n- %s\n", data.c_str());

    fs.Close();

    fs.RemoveListener(&fsl);
    return 0;
}
