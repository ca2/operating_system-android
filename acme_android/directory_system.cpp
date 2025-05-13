#include "framework.h"
#include "directory_system.h"
#include "acme/platform/system.h"


namespace acme_android
{


    directory_system::directory_system()
    {

    }


    directory_system::~directory_system()
    {

    }


    void directory_system::initialize(::particle *pparticle)
    {

       ::directory_system::initialize(pparticle);

       m_pathHome = system()->m_pathCacheDirectory / "home";

       m_pathRoaming = system()->m_pathCacheDirectory / ".config";

       m_pathCa2Config = system()->m_pathCacheDirectory / ".config/ca2";

    }


    ::file::path directory_system::home()
    {

       return m_pathHome;

    }


    ::file::path directory_system::roaming()
    {

       return m_pathRoaming;

    }


} // namespace acme_android



