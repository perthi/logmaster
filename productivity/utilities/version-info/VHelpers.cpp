
#include "VHelpers.h"
#include <utilities/GRegexp.h>

#include <vector>

using std::vector;

namespace VHELPERS
{

    string path(int argc, const char** argv)
    {
        string path = "";
        if (argc < 2)
        {
            path = ".";
        }
        else
        {
            path = "\"" + string(argv[1]);
        }

        if (g_string()->Contains(path, "@"))
        {
            path += "@";
        }
        return path;
    }

    

    string
        year()
    {
        return GTime( ).GetYear( );
    }


    string
        platform()
    {
        string platform;
#ifdef _WIN64
        platform = "x64 (64 bit)";
#else
        platform = "x86 (32 bit)";
#endif
        return platform;
    }

    string
        versionString(string version)
    {
        vector<int> version_numbers;
        vector<string> num = g_regexp()->ScanNumber(version, "1,4");

        for (unsigned int i = 0; i < num.size(); i++)
        {
            if (i < 4)
            {
                version_numbers.push_back(g_numbers()->ToInteger<int>(num[i]));
            }
        }

        return g_string()->Vec2String(version_numbers, ",");
    }


    FILE* file(const string directory, const string fname)
    {
        FILE* fp_h = 0;
        string filepath = directory + "\\" + fname;

#ifdef _WIN32
        fopen_s(&fp_h, filepath.c_str(), "w");  /// @todo check on return value
#else
        fp_h = fopen(filepath.c_str(), "w");
#endif

        if (fp_h == 0)
        {

#ifdef _WIN32
            fopen_s(&fp_h, fname.c_str(), "w"); /// @todo check on return value 
#else
            fp_h = fopen(fname.c_str(), "w"); /// @todo check on return value 
#endif        

            if (fp_h == 0)
            {
                cout << "Error opening file " << fname << ", or " << filepath << "aborting" << endl;
                exit(-1);
            }
        }

        return fp_h;
    }

    string configuration()
    {

#ifdef _DEBUG
        return "Debug";
#else
        return "Release";
#endif    

    }


    void  
    helpMenu()
    {
        cout << "Usage:  verion-info.exe [filepath]  option" << endl;
        cout << "NB ! A file path must be specified before any of the switches, Use \".\" (dot) to refere to the current directory" << endl;
        cout << "**** Command line switches *****" << endl;
        //  cout << "1)\t--generate-files  Generate the files/classes  and Version.h containing SVN information to be used by other applications (this i done as default if no parameters are given)" << endl;
        cout << "2)\t--repo-name\tPrints out the name of the repository as given in SVN" << endl;
        cout << "3)\t--branch\tPrints out wether you are in the trunk, tags or release branch" << endl;
        cout << "4)\t--version\tPrints out the SW version of this repository. Please note that if you are in the \"trunk\" branch then the version will also be \"trunk\"" << endl;
        cout << "5)\t--rev\tPrints the svn revision number of this subversion repository" << endl;
        cout << "6)\t--lc-rev\tPrints out the last changed revision of the file or directory pointed to by [filepath]" << endl;
        cout << "7)\t--info\tPrint out the SVN info as returned by the \"svn info\" command" << endl;
        cout << "8)\t--help\tPrints out this help menu" << endl;

    }

}

