// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.


#if defined(_WIN32)
	#if defined(_MSC_VER)
	#define PLATFORM_MSVC_X86
	#endif
	
	#if defined(__GNUC__)
	#define PLATFORM_GCC_COMPATIBLE_X86
	#endif
#endif

#include "cpuinfo.hpp"
#include "cpuinfo_impl.hpp"

#if defined(PLATFORM_GCC_COMPATIBLE_X86)
    #include "init_gcc_x86.hpp"
#elif defined(PLATFORM_MSVC_X86) && !defined(PLATFORM_WINDOWS_PHONE)
    #include "init_msvc_x86.hpp"
#elif defined(PLATFORM_MSVC_ARM)
    #include "init_msvc_arm.hpp"
#elif defined(PLATFORM_CLANG_ARM) && defined(PLATFORM_IOS)
    #include "init_ios_clang_arm.hpp"
#elif defined(PLATFORM_GCC_COMPATIBLE_ARM) && defined(PLATFORM_LINUX)
    #include "init_linux_gcc_arm.hpp"
#else
    #include "init_unknown.hpp"
#endif

namespace cpuid
{
cpuinfo::cpuinfo() :
    m_impl(new impl)
{
    init_cpuinfo(*m_impl);
}

cpuinfo::~cpuinfo()
{ }

// x86 member functions
bool cpuinfo::has_fpu() const
{
    return m_impl->m_has_fpu;
}

bool cpuinfo::has_mmx() const
{
    return m_impl->m_has_mmx;
}

bool cpuinfo::has_sse() const
{
    return m_impl->m_has_sse;
}

bool cpuinfo::has_sse2() const
{
    return m_impl->m_has_sse2;
}

bool cpuinfo::has_sse3() const
{
    return m_impl->m_has_sse3;
}

bool cpuinfo::has_ssse3() const
{
    return m_impl->m_has_ssse3;
}

bool cpuinfo::has_sse4_1() const
{
    return m_impl->m_has_sse4_1;
}

bool cpuinfo::has_sse4_2() const
{
    return m_impl->m_has_sse4_2;
}

bool cpuinfo::has_pclmulqdq() const
{
    return m_impl->m_has_pclmulqdq;
}

bool cpuinfo::has_avx() const
{
    return m_impl->m_has_avx;
}

bool cpuinfo::has_avx2() const
{
    return m_impl->m_has_avx2;
}

// ARM functions
bool cpuinfo::has_neon() const
{
    return m_impl->m_has_neon;
}
}
