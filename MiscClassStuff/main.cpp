
#include <stdio.h>

#include "FileStream.hpp"
#include "FileStreamListener.hpp"
#include "ConsoleStream.hpp"
#include "ConsoleStreamListener.hpp"

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

    ConsoleStream cs;
    ConsoleStreamListener csl;

    cs.AddListener(&csl);

    cs.Write("\nSome test data to write to the console!\n");

    cs.Write("Enter some input: ");

    std::string con_input;

    cs.Read(con_input);

    cs.Write("\nYou entered: " + con_input + "\n");

    cs.Close();

    cs.RemoveListener(&csl);
    return 0;
}
