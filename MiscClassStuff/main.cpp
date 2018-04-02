
#include <stdio.h>

#include "FileStream.hpp"
#include "FileStreamListener.hpp"
#include "ConsoleStream.hpp"
#include "ConsoleStreamListener.hpp"

#include "LogManager.hpp"

int main(int argc, char** argv)
{
	ConsoleStream con_stream;
	LogManager log_manager("testlog.txt");
	
	con_stream.AddListener(&log_manager);
	
	con_stream.Write("Woo, more entries to the console\n\n");
	
	con_stream.Write("Enter some input: ");

	std::string in_str;
	con_stream.Read(in_str);
	
	con_stream.Write("I am writing another thing to the console!\n");
	
    return 0;
}
