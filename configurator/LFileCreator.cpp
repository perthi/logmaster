

#include "LFileCreator.h"

#include "LGenerator.h"
#include <logging/GException.h>


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
        

        static int cnt = 0;

        
      

        if ( gen->IsEnabledHeader( ) )
        {

            CERR << "writing header to " << gen->GetFilePath() << "  cnt = "<< cnt  << endl;
            

            CERR << " (gen->GetContentHeader( ).size()" << gen->GetContentHeader( ).size( ) << endl;
            
            
            WriteFile(gen->GetContentHeader( ), gen->GetFilePath( ));
        }
        else if ( gen->IsEnabledSource( ) )
        {
            CERR << "writing source to " << gen->GetFilePath( ) << endl;
            WriteFile(gen->GetContentSource( ), gen->GetFilePath( ));
        }
        else
        {
            CERR << "DOING nothing " << gen->GetFilePath( ) << endl;
            // Nothing to do
            /** @todo write warning/error message or throw exception */
        }

        cnt++;
    }



    void
        LFileCreator::WriteFile(const vector<string>& content, const string& filepath)
    {
        PUSH( );
        SET_LOGFORMAT("0000111");
        FILE* fp = nullptr;

        CERR << "Content size = " << content.size() << "\tpath = " << filepath << ENDL;

#ifdef _WIN32
        fopen_s(&fp, filepath.c_str( ), "w");
#else // 
        fp = fopen(gen->GetFilePath( ).c_str( ), "w");
#endif
        FORCE_DEBUG("FilePath = %s", filepath.c_str( ));
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
        POP( );
    }
  

}