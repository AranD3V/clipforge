#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include "cli_parser.h"
using namespace std;

inline void processorMedia(const CLIAtgs& args) {
	string cmd = "ffmpeg -y -i \"" + args.input + "\" ";
    if (!args.resize.empty())
        cmd += "-vf scale=" + args.resize + " ";

    if (!args.bitrate.empty())
        cmd += "-b:v " + args.bitrate + " ";

    if (!args.format.empty())
        cmd += "-f " + args.format + " ";

    if (args.compress)
        cmd += "-compression_level 2 ";

    cmd += "\"" + args.output + "\"";

    cout << "Executing command:\n" << cmd << "\n";

    int result = system(cmd.c_str());
    if (result != 0) {
        cerr << "FFmpeg command failed with code: " << result << "\n";
    }
}