# ClipForge ???  
**A Cross-Platform CLI Tool for Media Processing (Built with C++ & FFmpeg)**

---

## ? Features
- ?? Convert videos between formats (MP4, WebM, etc.)
- ??? Resize videos/images with custom resolution
- ?? Apply compression using FFmpeg options
- ??? Batch-friendly via command-line automation
- ??? Built in C++ with CMake — Fast & Portable

---

## ?? How It Works
ClipForge is a wrapper around **FFmpeg**, designed for simple media processing with clean CLI flags.  
It auto-generates the correct FFmpeg commands based on your input.

---

## ??? Usage Example

```bash
ClipForge.exe --input "../../input.mp4" --output "resized.mp4" --resize 1280x720 --bitrate 2M
