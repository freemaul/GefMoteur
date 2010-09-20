#ifndef GEFDEBUG_HPP
#define GEFDEBUG_HPP
#ifdef DEBUG

#include <cstdlib>
#include <fstream>
#include <iostream>

extern std::size_t nb_new;
extern bool log_alloc;

inline void log(const char* type,const char* file,int line)
{
    static std::ofstream fichier_log("log_alloc.txt", std::ios::out);

    fichier_log << type << "\t" << file << "\t" << line << std::endl;
}

inline void* operator new(std::size_t Size, const char* File, int Line)
{
    void* retour = malloc(Size);
    log("new",File,Line);
    nb_new ++;
    return retour;
}

inline void operator delete(void* Ptr,const char* File,int Line)
{
    nb_new --;
    log("delete",File,Line);
    free(Ptr);
}


#define new new(__FILE__, __LINE__)
#define delete delete(__FILE__, __LINE__)

#endif // DEBUG
#endif // GEFDEBUG_HPP
