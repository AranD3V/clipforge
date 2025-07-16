#pragma once
#include "cxxopts.hpp"
#include <iostream>
#include <string>

struct CLIArgs {
    std::string input;
    std::string output;
    std::string resize;
    std::string format;
    std::string bitrate;
    bool compress = false;
};

inline CLIArgs parseArgs(int argc, char* argv[]) {
    cxxopts::Options options("clipforge", "Media Processing CLI Tool");

    options.add_options()
        ("i,input", "Input file/folder", cxxopts::value<std::string>())
        ("o,output", "Output file", cxxopts::value<std::string>()->default_value("output.mp4"))
        ("resize", "Resize (WxH)", cxxopts::value<std::string>())
        ("format", "Output format", cxxopts::value<std::string>())
        ("bitrate", "Bitrate (e.g. 2M)", cxxopts::value<std::string>())
        ("compress", "Enable compression")
        ("h,help", "Show help");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        std::exit(0);
    }

    return CLIArgs{
        result["input"].as<std::string>(),
        result["output"].as<std::string>(),
        result.count("resize") ? result["resize"].as<std::string>() : "",
        result.count("format") ? result["format"].as<std::string>() : "",
        result.count("bitrate") ? result["bitrate"].as<std::string>() : "",
        result.count("compress") > 0
    };
}
