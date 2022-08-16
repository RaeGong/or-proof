#pragma once

#include "./namespace.h"
#include "./utils/ConvertUtils.h"
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include "./Verifier.h"
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <gmp.h>

namespace polyu {

class Prover{
    private:

    public:
    shared_ptr<Verifier> verifier;
    
    ZZ N;

    ZZ N2; 

    Prover(shared_ptr<Verifier> verifier);

    // root proof
    // e is the challenge from verifier, proofs contains cipher, a, z
    Vec<ZZ_p> prove (const ZZ & e);
    //challenge e is returned 
    Vec<ZZ_p> prove_ni (ZZ & e);

    // or-proof
    Vec<ZZ_p> or_proof (const ZZ & e);
    Vec<ZZ_p> or_proof_ni (ZZ& e);

    ZZ_p pickRandom(); // mod N
    ZZ_p pickRandomN2(); // mod N^2
};


}