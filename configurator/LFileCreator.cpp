

#include "LFileCreator.h"

#include "LGenerator.h"
#include <logging/GException.h>

void 
LFileCreator::GenerateFiles(const generator_vec& gens, const loglevel_vec& loglevels, const subsystem_vec& subs)
{
	for (auto gen : gens)
	{
		GenerateSingleFile(gen,  loglevels, subs );
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
        fp = fopen(gen->GetFilePath().c_str(), "w");
#endif
        CERR << "FILEPATH =  " << gen->GetFilePath() << ENDL;



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
