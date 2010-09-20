#include <GefMoteur/GefDebug.hpp>
#ifdef DEBUG

std::size_t nb_new=0;
bool log_alloc = false;
std::ofstream fichier_log("log_alloc.txt", std::ios::out);

#endif // DEBUG
