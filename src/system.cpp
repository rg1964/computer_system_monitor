#include <unistd.h> //this Unix/Linux related - provides access to POSIX system API
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// defien namespace since a lot of functions are implemented in LinuxParser
using namespace LinuxParser;
// a list of accessor function is listed below
// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() {
    auto pids = LinuxParser::Pids(); 
    processes_ = {};
     for (int& pid : pids)
    {
        Process p(pid) ;
        processes_.push_back(p); 
    }
    std::sort(processes_.begin(), processes_.end()); 
    return processes_;
    }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// TODO: Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// TODO: Return the number of seconds since the system started running
// Implemented as a passthrough function
long int System::UpTime() { return LinuxParser::UpTime(); }
