

#include "LFileCreator.h"

#include "LGenerator.h"


void 
LFileCreator::GenerateFiles(const generator_vec& generators, const loglevel_vec& loglevels, const subsystem_vec& subsystem)
{
	for (auto gen : generators)
	{
		GenerateSingleFile(gen,  loglevels, subsystem );
	}

}


void 
LFileCreator::GenerateSingleFile(const generator& gen, const loglevel_vec& loglevels, const subsystem_vec& subsystems )
{
        gen->GenerateContent(loglevels, subsystems);
        vector<string> lines = gen->GetContent();
        FILE* fp = nullptr;

#ifdef _WIN32
        fopen_s(&fp, gen->GetFilePath().c_str(), "w");
#else // 
        fp = fopen(gen->GetFilename().c_str(), "w");
#endif

        if (fp != nullptr)
        {
            for (auto& l : lines)
            {
                fprintf(fp, "%s\n", l.c_str());
            }

            fclose(fp);
        }

}
