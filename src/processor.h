#pragma once
#include "cli_parser.h"
#include <iostream>
#include <cstdlib>

inline void processMedia(const CLIArgs& args) {
    std::string cmd = "ffmpeg -y -i \"" + args.input + "\" ";

    if (!args.resize.empty())
        cmd += "-vf scale=" + args.resize + " ";

    if (!args.bitrate.empty())
        cmd += "-b:v " + args.bitrate + " ";

    if (!args.format.empty())
        cmd += "-f " + args.format + " ";

    if (args.compress)
        cmd += "-compression_level 2 ";

    cmd += "\"" + args.output + "\"";

    std::cout << "Executing command:\n" << cmd << std::endl;

    int result = std::system(cmd.c_str());
    if (result != 0) {
        std::cerr << "FFmpeg command failed with code: " << result << std::endl;
    }
}
