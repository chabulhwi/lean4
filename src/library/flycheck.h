/*
Copyright (c) 2014 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#pragma once
#include "library/io_state_stream.h"

namespace lean {
/** \brief Auxiliary object for "inserting" delimiters for flycheck */
class flycheck_scope {
    io_state_stream const & m_ios;
    bool                    m_flycheck;
public:
    flycheck_scope(io_state_stream const & ios, char const * kind);
    ~flycheck_scope();
};

struct flycheck_error : public flycheck_scope {
    flycheck_error(io_state_stream const & ios):flycheck_scope(ios, "ERROR") {}
};

struct flycheck_warning : public flycheck_scope {
    flycheck_warning(io_state_stream const & ios):flycheck_scope(ios, "WARNING") {}
};

class flyinfo_scope {
    io_state_stream const & m_ios;
    bool                    m_flyinfo;
public:
    flyinfo_scope(io_state_stream const & ios);
    ~flyinfo_scope();
};
}
