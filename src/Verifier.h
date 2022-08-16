#pragma once 

#include "./namespace.h"
#include "./PaillierEncryption.h"

#include <math.h>
#include <iostream>

#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include <NTL/vector.h>
#include <NTL/matrix.h>

namespace polyu {

class Verifier {
    private:

    public:

    shared_ptr<PaillierEncryption> crypto;
    ZZ N;

    ZZ N2;

    // generator
    ZZ_p G;

    Verifier (
       const ZZ & N, 
       const ZZ & N2,
       const ZZ_p & G
    );

    Verifier (
        shared_ptr<PaillierEncryption> &crypto,
        const ZZ_p & G
    );

    // e is a challenge from verifier
    bool verify (const Vec<ZZ_p> &proofs, const ZZ &e);
    bool or_verify (const Vec<ZZ_p> &proofs, const ZZ &e);
    bool or_verify_ni (const Vec<ZZ_p> &proofs);
    
};

}