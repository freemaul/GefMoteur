#ifndef GEFDEBUG_HPP
#define GEFDEBUG_HPP
#ifdef DEBUG

#include <cstdlib>
#include <fstream>
#include <iostream>

extern std::size_t nb_new;
extern bool log_alloc;
extern std::ofstream fichier_log;

inline void log(const char* type,const char* file,int line,void* Add)
{
    if(fichier_log.is_open())
    {
        fichier_log << type << "\t" << file << "\t" << line << "\t" << Add << std::endl;
    }
}

inline void* operator new(std::size_t Size, const char* Func,const char* File, int Line)
{
    void* retour = malloc(Size);
    log("new",File,Line,retour);
    nb_new ++;
    return retour;
}

inline void operator delete(void* Ptr)
{
    nb_new --;
    log("delete","?",0,Ptr);
    free(Ptr);
}

#define new new(__FUNCTION__,__FILE__, __LINE__)


#endif // DEBUG
#endif // GEFDEBUG_HPP
