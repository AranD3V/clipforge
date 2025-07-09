#pragma once
#include "cxxopts.hpp"
using namespace std;
struct CLIArgs {
	string input;
	string output;
	string resize;
	string format;
	string bitrate;
	bool compress = false;
};

inline CLIArgs parseArgs(int argc, char* argv[]) {
	cxxopts::Options options("clipforge", "Media Processing CLI Tool");

	options.add_options()
		("i,input", "Input file/folder", cxxopts::value<string>())
		("o,output", "Output file", cxxopts::value<string>()->default_value("output.mp4"))
		("resize", "Resize (WxH)", cxxopts::value<string>())
		("format", "Output format", cxxopts::value<string>())
		("bitrate", "Bitrate (e.g. 2M)", cxxopts::value<strin>())
		("compress", "Enable compression")
		("h,help", "Show help");

	auto result = options.parse(argc, argv);

	if (result.count("help")) {
		cout << options.help();
		exit(0);
	}

	return CLIArgs{
		result["input"].as<string>(),
		result["output"].as<string>(),
		result.count("resize") ? result["resize"].as<string>() : "",
		result.count("format") ? result["format"].as<string>() : "",
		result.count("bitrate") ? result["bitrate"].as<string>() : "",
		result.count("compress") > 0
	};
}