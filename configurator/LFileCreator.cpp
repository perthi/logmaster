

#include "LFileCreator.h"

#include "LGenerator.h"
#include <logging/GException.h>


namespace CONFIGURATOR
{
    /** Loops over a vector of file generators and generates the corresponding files.
    See documentation of @ref GenerateSingleFile */
    void
    LFileCreator::GenerateFiles(const generator_vec& gens, const loglevel_vec& loglevels, const subsystem_vec& subs)
    {
        for (auto &gen : gens)
        {
            GenerateSingleFile(gen, loglevels, subs);
        }

    }

    /** Generate a .cpp/h source file. First the content will be generated using an 
    *  implementation of one of the generators. Then the generated content will 
    * be written to file. 
    * @param[in] gen The file generator
    * @param[in] loglevels A vector of logging levels (DEBUG, INFO etc..) parsed form the XML file
    * @param[in] subsystems A vector of sub systems parsed from the XML config file 
    * @exception GException if the file cannot be created */
    void
    LFileCreator::GenerateSingleFile(const generator& gen, const loglevel_vec& loglevels, const subsystem_vec& subsystems)
    {
        gen->GenerateContent(loglevels, subsystems); /// Generating the file content
        vector<string> lines = gen->GetContent();
        FILE* fp = nullptr;

#ifdef _WIN32
        fopen_s(&fp, gen->GetFilePath().c_str(), "w");
#else // 
        fp = fopen(gen->GetFilePath().c_str(), "w");
#endif
        //CERR << "FILEPATH =  " << gen->GetFilePath() << ENDL;

        if (fp != nullptr)
        {
            for (auto& l : lines)
            {
                fprintf(fp, "%s\n", l.c_str());
            }

            fclose(fp);
        }
        else
        {
            XML_EXCEPTION("FILE IS ZERO POINTER");
        }

    }

}