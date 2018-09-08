#pragma once

#include <fstream>
#include <iomanip>
#include <string>

namespace TopLogger
{
    inline void function( std::string const& message )
    {
        static std::string dn = "..\\logs";
        static std::string fn = "TopLogger_2018-06-22";

        std::ofstream ofs( dn + "\\" + fn + ".txt", std::ios_base::app );

        ofs << message;
        ofs.flush();
    }

    class Sink{};

    inline TopLogger::Sink operator<<( TopLogger::Sink, std::string const& message )
    {
        TopLogger::function( message );
        return TopLogger::Sink{};
    }

    inline TopLogger::Sink operator<<( TopLogger::Sink, std::wstring const& message )
    {
        TopLogger::function( std::string( message.begin(), message.end() ) );
        return TopLogger::Sink{};
    }


    inline TopLogger::Sink operator<<( TopLogger::Sink, int const& i )
    {
        TopLogger::function( std::to_string( i ) );
        return TopLogger::Sink{};
    }

    struct Scope
    {
        Scope( std::string const& file, std::string const& func, int l )
        {
            m_file = file;
            m_function = func;
            m_line = l;
            TopLogger::Sink{} << m_file << " - " << m_function << " - " << m_line << " - " << "ENTER" << "\n";
        }
        ~Scope()
        {
            TopLogger::Sink{} << m_file << " - " << m_function << " - " << m_line << " - " << "EXIT" << "\n";
        }

        std::string m_file;
        std::string m_function;
        int         m_line;

    };

}

#define TOPLOG__PREFIX          " - " << __FUNCTION__ << " - " << __LINE__

#define TOPLOG_SCOPE          TopLogger::Scope scope_logger_instance( "", __FUNCTION__,  __LINE__  )
#define TOPLOG_POINT          TopLogger::Sink{} << TOPLOG__PREFIX << " - " << "POINT" << "\n"
#define TOPLOG_VALUE(value)   TopLogger::Sink{} << TOPLOG__PREFIX << " - " << #value << " == " << value << "\n"
#define TOPLOG_COMMENT(value) TopLogger::Sink{} << TOPLOG__PREFIX << " - " << value << "\n"

