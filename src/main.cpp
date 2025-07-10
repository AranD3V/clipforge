#include "cli_parser.h"
#include "process.h"

using namespace std;

int main(int argc, char* argv[]) {
	try {
		CLIArgs = parseArgs(argc, argv);
		processMedia(args);
	}
	catch (const exception& ex) {
		cerr << "Error: " << ec.what() << endl;
		return 1;
	}
	return 0;
}

