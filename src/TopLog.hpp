#ifndef TopLog_3f086ec6_c405_4a5b_b6c0_2edbc9f0a6b8
#define TopLog_3f086ec6_c405_4a5b_b6c0_2edbc9f0a6b8
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

namespace TopLogger
 {

  namespace _privateSpace
   {

    inline std::string getCurrentTime()
     {
      time_t t = time(0);
      tm   n = *localtime( &t );

      std::stringstream ss;
      ss.str("");

      ss <<                                      n.tm_year + 1900 << "-";
      ss << std::setw(2) << std::setfill('0') << n.tm_mon  + 1    <<  "-";
      ss << std::setw(2) << std::setfill('0') << n.tm_mday        <<  "_";
      ss << std::setw(2) << std::setfill('0') << n.tm_hour        <<  "-";
      ss << std::setw(2) << std::setfill('0') << n.tm_min             ;

      return ss.str();
     }

    inline void function( std::string const& message )
     {
         static std::string dn = ".\\";
         static std::string fn =   "TopLogger_" + TopLogger::_privateSpace::getCurrentTime();

         std::ofstream ofs( dn + "\\" + fn + ".txt", std::ios_base::app );

         ofs << message;
         ofs.flush();
     }

   }

   class Sink{};

   inline TopLogger::Sink operator<<( TopLogger::Sink, std::string const& message )
   {
       TopLogger::_privateSpace::function( message );
       return TopLogger::Sink{};
   }

   inline TopLogger::Sink operator<<( TopLogger::Sink, std::wstring const& message )
   {
       TopLogger::_privateSpace::function( std::string( message.begin(), message.end() ) );
       return TopLogger::Sink{};
   }


   inline TopLogger::Sink operator<<( TopLogger::Sink, int const& i )
   {
       TopLogger::_privateSpace::function( std::to_string( i ) );
       return TopLogger::Sink{};
   }

   struct Scope
   {
    public:
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

#endif
