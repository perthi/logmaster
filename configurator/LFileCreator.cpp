

#include "LFileCreator.h"

#include "LGenerator.h"
#include "LFileInfo.h"
#include <logging/GException.h>
#include <format.h>

namespace CONFIGURATOR
{
    /** Loops over a vector of file generators and generates the corresponding files.
    See documentation of @ref GenerateSingleFile */
    void
    LFileCreator::GenerateFiles(const generator_vec& gens, const logentity_vec loglevels, const sysentity_vec  subs)
    {
        for (auto &gen : gens)
        {
            GenerateSingleFile(gen,  loglevels, subs);
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
    LFileCreator::GenerateSingleFile(const generator_ptr& gen, const logentity_vec  loglevels, const sysentity_vec subsystems)
    {
        gen->GenerateContent(loglevels, subsystems); /// Generating the file content

        string basepath = gen->GetFileInfo()->GetPath();

        if ( !gen->IsEnabledHeader( )  && !gen->IsEnabledSource( ) )
        {
            //  Nothing to do, that must be an error
            XML_EXCEPTION("Nothing to do, neither Source or Header generation is enabled");
        }

        if ( gen->IsEnabledHeader( ) )
        {
            string filename = basepath + gen->GetFileInfo()->GetHeaderName();
            XML_INFO("Writing header to: %s",  filename.c_str() );
            WriteFile(gen->GetContentHeader( ),  filename );
        }
        
        if ( gen->IsEnabledSource( ) )
        {
            string filename = basepath + gen->GetFileInfo()->GetSourceName();
            XML_INFO("Writing source to: %s", filename.c_str());
            WriteFile(gen->GetContentSource( ), filename );
        }
    }



    void
        LFileCreator::WriteFile(const vector<string>& content, const string& filepath)
    {
        XML_ASSERT_EXCEPTION(filepath !="", "The filename is empty");
        FILE* fp = nullptr;

#ifdef _WIN32
        fopen_s(&fp, filepath.c_str( ), "w");
#else // 
      //  fp = fopen(gen->GetFilePath( ).c_str( ), "w");
        fp = fopen(filepath.c_str( ), "w");

#endif
        XML_ASSERT_EXCEPTION(fp !=nullptr, fmt::format("Could not open: {}, fp = nullptr", filepath).c_str() );
        
        if ( fp != nullptr )
        {
            for ( auto& l : content )
            {
                fprintf(fp, "%s\n", l.c_str( ));
            }

            fclose(fp);
        }
        else
        {
            XML_EXCEPTION("FILE IS ZERO POINTER");
        }
       
    }
  

}