// -*- mode: c++ -*-


/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no>  http:///www.embc.no ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/


#include "GCmdScan.h"




GCmdScan::GCmdScan() : fDoIgnoreStrayArguments(false)
{

}


GCmdScan::~GCmdScan()
{

}

/*
* Set parameters of fundamental type + strings
*/
template <typename T>
inline void
GCmdScan::SetParameterVal_t(std::shared_ptr<GArgument> a, GArgumentParsed v) const
{
    std::shared_ptr<GCommandLineArgument<T>> ab = std::dynamic_pointer_cast<GCommandLineArgument<T>>(a);
    G_ASSERT_EXCEPTION(ab != nullptr, "ZERO POINTER");

    if (ab != nullptr)
    {
        double d = 0;

        if (ab->GetTypeIdBase() == "Val_t")
        {
            vector<string> args_v = v.GetArguments();

            if (args_v.size() == 0)
            {
                G_FATAL("%s: Argument missing !!", ab->GetCommand().c_str());
                // d = -1;
            }
            else
            {
                d = g_numbers()->ToFloat(v.GetArguments()[0]);
            }
        }
        ab->SetParameterVal_t(&d);
    }
}

template<typename T>
inline vector<GArgumentParsed>
GCmdScan::ScanArgument(const uint64_t argc, const char** argv, std::shared_ptr<GCommandLineArgument<T> > arg) const
{
    deque< std::shared_ptr<GArgument>  > v;
    v.push_back(arg);
    return ScanArguments(argc, argv, &v);

}


/*
* Set parameters of fundamental type + strings
*/
template<typename T>
inline void
GCmdScan::SetParametersF(std::shared_ptr<GArgument>  a, GArgumentParsed v) const
{
    std::shared_ptr<  GCommandLineArgument < T >   > ab = dynamic_pointer_cast<GCommandLineArgument < T >>(a);
    G_ASSERT_EXCEPTION(ab != nullptr, "ZERO pointer");

    if (ab != nullptr)
    {
        if (Verify(a, v) == true)
        {
            T d = 0;

            if (g_numbers()->IsIntegerType(d) || ab->GetTypeIdBase() == "Val_t")
            {
                d = g_numbers()->ToInteger<T>(v.GetArguments()[0]);
            }

            if (g_numbers()->IsFloatType(d) || ab->GetTypeIdBase() == "Val_t")
            {
                d = g_numbers()->ToFloat<T>(v.GetArguments()[0]);
            }
            ab->SetParameterF(&d);
        }
    }
}


template<>
inline void
GCmdScan::SetParametersF<string>(std::shared_ptr<GArgument>  a, GArgumentParsed v) const
{
    std::shared_ptr<   GCommandLineArgument < string>  > ab = std::dynamic_pointer_cast<GCommandLineArgument < string>>(a);
    G_ASSERT_EXCEPTION(ab != nullptr, "ZERO pointer ");

    if (ab != nullptr)
    {
        {
            if (v.GetArguments().size() == 0)
            {
                INVALID_ARGUMENT_EXCEPTION("Missing argument to %s", a->fCmd.c_str());
            }
            else
            {
                ab->SetParameter(&v.GetArguments()[0]);
            }
        }
    }
}



template<>
inline void
GCmdScan::SetParametersF<bool>(std::shared_ptr<GArgument>  a, GArgumentParsed v) const
{
    std::shared_ptr<   GCommandLineArgument < bool>  > ab = std::dynamic_pointer_cast<GCommandLineArgument < bool>>(a);
    G_ASSERT_EXCEPTION(ab != nullptr, "ZERO pointer ");

    if (ab != 0)
    {
        static bool btemp = false;
        if (Verify(a, v) == true)
        {
            btemp = true;
            ab->SetParameterF(&btemp);
        }
        else
        {
            btemp = false;
            ab->SetParameterF(&btemp);
        }
    }
}



/*
* Set parameters of vector type
*/
template<typename T>
inline void
GCmdScan::SetParametersV(std::shared_ptr<GArgument>  a, vector<string> vs) const
{
    std::shared_ptr<     GCommandLineArgument < vector<T> >   > ab = std::dynamic_pointer_cast<GCommandLineArgument < vector<T> >>(a);
    G_ASSERT_EXCEPTION(ab != nullptr, "ZERO pointer ");

    if (ab != 0)
    {
        static vector<T> tmp;
        tmp = g_numbers()->ToFloat<T>(vs);
        ab->SetParameter(&tmp);

    }
}



/*
* Set parameters of vector type
*/
template<typename T, typename U >
inline void
GCmdScan::SetParametersVI(std::shared_ptr<GArgument>  a, vector<string> vs) const
{
    std::shared_ptr<    GCommandLineArgument < U >    > ab = std::dynamic_pointer_cast<GCommandLineArgument < U >>(a);
    G_ASSERT_EXCEPTION(ab != nullptr, "ZERO pointer ");

    if (ab != 0)
    {
        static  vector<T> tmp;
        tmp = g_numbers()->ToInteger<T>(vs);
        ab->SetParameter(&tmp);
    }
    else
    {
        EXCEPTION("cast failed (attempted to cast a to %s", typeid(U).name());
    }
}



template<>
inline void
GCmdScan::SetParametersV< vector < string > >(std::shared_ptr<GArgument>  a, vector<string> vs) const
{
    std::shared_ptr<    GCommandLineArgument < vector < string  > >     > avs = std::dynamic_pointer_cast<GCommandLineArgument < vector < string  > >>(a);
    G_ASSERT_EXCEPTION(avs != nullptr, "ZERO pointer ");

    if (avs != 0)
    {
        avs->SetParameter(&vs);
    }
}



vector<GArgumentParsed>
GCmdScan::ScanArguments(const int argc, const char** argv, std::shared_ptr<GArgument>  arg) const
{
    deque<  std::shared_ptr<GArgument>  > avec;
    avec.push_back(arg);
    return ScanArguments(argc, argv, &avec);
}


#include <stdio.h>

vector <GArgumentParsed>
GCmdScan::ScanArguments(const int argc, const char** argv, deque<  std::shared_ptr<GArgument>  >* args) const
{
    CheckDuplicates(args);

    if (argc >= 2)
    {
        if (IsCommand(argv[1]) == false)
        {
            if (fDoIgnoreStrayArguments == false)
            {
                INVALID_ARGUMENT_EXCEPTION("Stray argument \"%s\"", argv[1]);
            }
            else
            {
                G_WARNING("Stray argument \"%s\"", argv[1]);
            }
        }
    }

    vector<GArgumentParsed> v = SplitCommands(argc, argv);

    CheckValid(v, args);
    CheckMandatory(v, args);

    for (uint16_t i = 0; i < args->size(); i++)
    {
        for (uint16_t j = 0; j < v.size(); j++)
        {
            if (args->at(i)->GetCommand() == v[j].GetCommand())
            {
                vector<string> scanned = v[j].GetArguments();
                string type = args->at(i)->GetTypeId();
                string baseType = args->at(i)->GetTypeIdBase();

                //#ifdef _WIN32
                if (baseType == "Val_t")
                {
                    SetParameterVal_t  < Val_t<double> >(args->at(i), v[j]);
                }

                //#endif
                if (type == typeid(bool).name()) { SetParametersF  <bool>(args->at(i), v[j]); }


                if (type == typeid(string).name()) { SetParametersF  <string>(args->at(i), v[j]); }

                if (type == typeid(float).name()) { SetParametersF  <float>(args->at(i), v[j]); }
                if (type == typeid(double).name()) { SetParametersF  <double>(args->at(i), v[j]); }
                if (type == typeid(long double).name()) { SetParametersF  <long double>(args->at(i), v[j]); }
                if (type == typeid(short).name()) { SetParametersF  <short>(args->at(i), v[j]); }
                if (type == typeid(int).name()) { SetParametersF  <int>(args->at(i), v[j]); }
                if (type == typeid(long int).name()) { SetParametersF  <long int>(args->at(i), v[j]); }
                if (type == typeid(long long int).name()) { SetParametersF  <long long int>(args->at(i), v[j]); }
                if (type == typeid(unsigned short).name()) { SetParametersF  <unsigned short>(args->at(i), v[j]); }
                if (type == typeid(unsigned int).name()) { SetParametersF  <unsigned int>(args->at(i), v[j]); }
                if (type == typeid(unsigned long int).name()) { SetParametersF  <unsigned long int>(args->at(i), v[j]); }
                if (type == typeid(unsigned long long int).name()) { SetParametersF  <unsigned long long int>(args->at(i), v[j]); }
                if (type == typeid(vector<float>).name()) { SetParametersV  <float>(args->at(i), scanned); }
                if (type == typeid(vector<double>).name()) { SetParametersV  <double>(args->at(i), scanned); }
                if (type == typeid(vector<long double>).name()) { SetParametersV  <long double>(args->at(i), scanned); }
                if (type == typeid(vector<short>).name()) { SetParametersVI <short>(args->at(i), scanned); }
                if (type == typeid(vector<int>).name()) { SetParametersVI <int>(args->at(i), scanned); }
                if (type == typeid(vector<long int>).name()) { SetParametersVI <long int>(args->at(i), scanned); }
                if (type == typeid(vector<long long int>).name()) { SetParametersVI <long long int>(args->at(i), scanned); }
                if (type == typeid(vector<unsigned short>).name()) { SetParametersVI <unsigned short>(args->at(i), scanned); }
                if (type == typeid(vector<unsigned int>).name()) { SetParametersVI <unsigned int >(args->at(i), scanned); }
                if (type == typeid(vector<unsigned long int>).name()) { SetParametersVI <unsigned long int>(args->at(i), scanned); }
                if (type == typeid(vector<unsigned long long int>).name()) { SetParametersVI <unsigned long long int>(args->at(i), scanned); }
                if (type == typeid(vector<string>).name()) { SetParametersV  <vector<string> >(args->at(i), scanned); }
                Verify(args->at(i), v[j]);

            }
        }
    }

    return v;
}


bool
GCmdScan::Verify(std::shared_ptr<GArgument> a, GArgumentParsed v) const
{
    if (a->ValidateCommands != nullptr)
    {
        string args_s = g_string()->Vec2String(v.GetSubCommands(), " ") + " " + g_string()->Vec2String(v.GetArguments(), " ");
        bool test = a->ValidateCommands(v.GetCommand(), args_s, v.GetSubCommands(), v.GetArguments());  
        
        return test;
    }
    else
    {
        G_DEBUG("Function pointer to validation function is ZERO");
        string type = a->GetTypeId();

        if (a->GetTypeIdBase() == "Val_t")
        {
            return true;
        }


        if (type == typeid(void).name())
        {
            if (v.GetSubCommands().size() != 0 || v.GetArguments().size() != 0)
            {
                INVALID_ARGUMENT_EXCEPTION("GArguments of type void does not take any subcommands or parameters,%s(%s), You have given these GArgument (%s) and these subcommands (%s)",
                    v.GetCommand().c_str(),
                    type.c_str(),
                    g_string()->ToString(v.GetArguments()).c_str(),
                    g_string()->ToString(v.GetSubCommands()).c_str());
            }
            else
            {
                return true;
            }
        }

        /*********************************************/
        if (type == typeid(bool).name())
        {
            string arg = v.GetArguments().size() > 0 ? v.GetArguments()[0] : "";
            string sub = v.GetSubCommands().size() > 0 ? v.GetSubCommands()[0] : "";

      //      if ((v.GetArguments().size() == 1) != (v.GetSubCommands().size() == 1))
            if ((v.GetArguments().size() == 1) xor (v.GetSubCommands().size() == 1))
            {
                if (sub == "--true" || arg == "1")
                {
                    return true;
                }
                else if (sub == "--false" || arg == "0")
                {
                    return false;
                }
                else
                {
                    INVALID_ARGUMENT_EXCEPTION("Invalid subcommand or argument: %s%s", sub.c_str(), arg.c_str());

                }

            }
            else
            {
                if ((v.GetSubCommands().size() != 0) != (v.GetArguments().size() != 0))
                {
                    INVALID_ARGUMENT_EXCEPTION("boolean types takes either no arguments (defaults to true) or --true/false. Alternatively the verification function is not set: %s(%s) takes only one argument", v.GetCommand().c_str(), type.c_str());
                }
                else
                {
                    return true;
                }
            }
        }

        /**********************************************/

        else if (g_numbers()->IsFundamentalTypeS(type) || type == typeid(string).name())
        {
            if (v.GetSubCommands().size() != 0 || v.GetArguments().size() != 1 || v.GetArguments().size() == 0)
            {
                string n_sub = g_string()->ToString((v.GetSubCommands().size()));
                string n_args = g_string()->ToString((v.GetArguments().size()));
                string args = "Subcommands:" + g_string()->Vec2String(v.GetSubCommands()) + "(" + n_sub + ")\t" + "arguments: " + g_string()->Vec2String(v.GetArguments()) + "(" + n_args + ")";
                INVALID_ARGUMENT_EXCEPTION("Arguments of fundamental types takes exactly one parameter, and no sub arguments: %s(%s) takes only one argument: You have given the following arguments and subcommands: %s", v.GetCommand().c_str(), type.c_str(), args.c_str());
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }

    return false;
}



vector < GArgumentParsed >
GCmdScan::SplitCommands(const int argc, const char** argv, const bool skipfirst) const
{
    vector  <GArgumentParsed > pv;
    const int startindex = skipfirst == true ? 1 : 0;

    for (int i = startindex; i < argc; i++)
    {
        if (IsCommand(string(argv[i])))
        {
            GArgumentParsed  p;
            p.SetCommand(argv[i]);

            if (argc > i + 1)
            {
                while (!IsCommand(string(argv[i + 1])) && i + 1 < argc)
                {
                    if (IsSubCommand(string(argv[i + 1])))
                    {
                        p.AddSubCommand(argv[i + 1]);
                    }
                    else
                    {
                        p.AddParameter(argv[i + 1]);
                    }

                    i++;

                    if (i + 1 == argc)
                    {
                        break;
                    }
                }
            }
            pv.push_back(p);
        }
    }
    return pv;
}


bool
GCmdScan::IsCommand(const string arg) const
{

    if (g_string()->BeginsWith(arg, "-", false) && !g_string()->BeginsWith(arg, "--", false) && !g_numbers()->IsNumber(arg))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool
GCmdScan::IsSubCommand(const string arg) const
{
    if (g_string()->Contains(arg, "--", false))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool
GCmdScan::CheckMandatory(const vector<GArgumentParsed> v, const deque <  std::shared_ptr<GArgument> >* args) const
{
    /** @todo check if  args is nullptr */
    vector<string> tokens;

    for (uint16_t i = 0; i < v.size(); i++)
    {
        tokens.push_back(v[i].GetCommand());
    }

    for (uint16_t i = 0; i < args->size(); i++)
    {
        G_ASSERT_EXCEPTION(args->at(i) != 0, "args[%d] is a ZERO pointer", i);

        if ((args->at(i)->IsMandatory() == true) && (HasArgument(tokens, args->at(i)->GetCommand()) == false))
        {
            MISSING_ARGUMENT_EXCEPTION("argument %s is mandatory, but not present", args->at(i)->GetCommand().c_str());
        }
    }

    return true;
}


inline bool
GCmdScan::HasArgument(int argc, const char** argv, vector<string> commands) const
{
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (HasArgument(argc, argv, commands[i]) == true)
        {
            return true;
        }
    }
    return false;
}



bool
GCmdScan::HasArgument(int argc, const char** argv, const string cmd) const
{
    string s1;

    for (int i = 1; i < argc; i++)
    {
        s1.assign(argv[i]);

        if (s1 == cmd)
        {
            return true;
        }
    }
    return false;
}



inline bool
GCmdScan::HasArgument(const vector<string> tokens, const string command) const
{
    for (uint16_t i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == command)
        {
            return true;
        }
    }
    return false;
}


bool
GCmdScan::CheckValid(const vector<GArgumentParsed> v, const deque < std::shared_ptr<GArgument> >* args) const
{

    bool iret = false;
    for (uint16_t i = 0; i < v.size(); i++)
    {
        iret = false;

        for (uint16_t j = 0; j < args->size(); j++)
        {
            G_ASSERT_EXCEPTION(args->at(j) != 0, "args[%d] is a ZERO pointer", j);
            if (args->at(j)->GetCommand() == v[i].GetCommand())
            {
                iret = true;
            }
        }

        if (iret == false)
        {
            string valid_args;

            for (size_t k = 0; k < args->size(); k++)
            {
                valid_args += "\t" + args->at(k)->str() + "\n";
            }

            string msg = "\nUnknown GArgument: " + v[i].GetCommand() + "\n";
            msg += valid_args + "\n\t********** VALID ARGUMENTS END **********\n\n";
            msg += "\targument parsing resulted in an error because  \"" + v[i].GetCommand() + "\"  Is an invalid argument";

            if (fDoIgnoreStrayArguments == false)
            {
                INVALID_ARGUMENT_EXCEPTION("%s", msg.c_str());
            }
            else
            {
                G_INFO(msg.c_str());
            }
        }
    }

    return iret;
}


void
GCmdScan::CheckDuplicates(deque < std::shared_ptr<GArgument> >* args) const
{
    for (uint16_t i = 0; i < args->size(); i++)
    {
        for (uint16_t j = i + 1; j < args->size(); j++)
        {
            G_ASSERT_EXCEPTION(args->at(i) != 0, "args[%d] is a ZERO pointer", i);
            G_ASSERT_EXCEPTION(args->at(j) != 0, "args[%d] is a ZERO pointer", j);
            string tmpi = string(args->at(i)->GetCommand());
            string tmpj = string(args->at(j)->GetCommand());

            if (tmpi == tmpj)
            {
                INVALID_ARGUMENT_EXCEPTION("Duplicated command line GArgument: %s", tmpi.c_str());
            }
        }
    }
}


void
GCmdScan::SetExecName(deque < std::shared_ptr<GArgument>  >* arg, const char* name) const
{
    for (uint16_t i = 0; i < arg->size(); i++)
    {
        arg->at(i)->SetExcecName(name);
    }
}


GCmdScan*
GCmdScan::Instance()
{
    static GCmdScan* instance = new GCmdScan();
    return instance;
}


void
GCmdScan::SetIgnoreStrayArgument(const bool ignore)
{
    fDoIgnoreStrayArguments = ignore;
}


bool
GCmdScan::GetIgnoreStrayArgument() const
{
    return fDoIgnoreStrayArguments;
}



GCmdScan* g_cmdscan()
{
    return GCmdScan::Instance();
}

