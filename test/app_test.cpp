#include "gtest/gtest.h"

#include "../src/namespace.h"
#include <fstream>


#include <set>
#include "../src/PaillierEncryption.h"
#include "../src/utils/ConvertUtils.h"
#include "../src/Prover.h"
#include "../src/Verifier.h"
#include "../src/utils/Timer.h"

namespace{

    // non-interactive mode
    TEST(AppTest, work_flow_ni) {
        string file_name = "../../data/root_proof_time_3.csv";
        ifstream ifile(file_name);
        ofstream fs;

        if (ifile) {
            fs.open(file_name, std::ios_base::app);
        } else{
            fs.open(file_name);
            fs << "N length,";
            fs << "proof time (ms), ";
            fs << "verify time (ms), ";
            fs << "(ni) proof time (ms),";
            fs << "(ni) verify time (ms)," << endl;
        }

        double proof_time = 0;
        double verify_time = 0;
        size_t N_length = 256; // bytes

        auto crypto = make_shared<PaillierEncryption>(N_length);
        auto verifier = make_shared<Verifier>(crypto, crypto->getGroupG());
        auto prover = make_shared<Prover>(verifier);
        

        
        ZZ e;
        Timer::start("prove");
        auto proofs = prover->prove_ni(e);
        proof_time += Timer::end3("prove");

        Timer::start("verify");
        auto flag = verifier->verify(proofs, e);
        verify_time += Timer::end3("verify");

        EXPECT_EQ(flag, true);

        if (!flag) 
            cout << "this proof is not correct!" << endl;


        fs << N_length * 8 << ",";
        // todo add into interactive mode time here
        fs << 0 << ",";
        fs << 0 << ",";
        fs << proof_time << ",";
        fs << verify_time << endl;
    
        fs.close();
    }

    // interactive mode
    TEST(AppTest, or_proof_workflow_correct) {
        string file_name = "../../data/new_or_proof_time.csv";
        ifstream ifile(file_name);
        ofstream fs;

        if (ifile) {
            fs.open(file_name, std::ios_base::app);
        } else{
            fs.open(file_name);
            fs << "N length,";
            fs << "proof time (ms), ";
            fs << "verify time (ms), ";
            fs << "(ni) proof time (ms),";
            fs << "(ni) verify time (ms)," << endl;
        }

        double proof_time = 0;
        double verify_time = 0;
        size_t N_length = 256; // 
        
        auto crypto = make_shared<PaillierEncryption>(N_length);
        auto verifier = make_shared<Verifier>(crypto, crypto->getGroupG());
        auto prover = make_shared<Prover>(verifier);

        //verifier: e 
        Timer::start("verify");
        ZZ_p::init(SqrRoot(prover->N));
        ZZ_p e;
        random(e);
        verify_time += Timer::end3("verify");

        Timer::start("prove");
        auto proofs = prover->or_proof(conv<ZZ>(e));
        proof_time += Timer::end3("prove");

        Timer::start("verify");
        bool flag = verifier->or_verify(proofs, conv<ZZ>(e));
        verify_time += Timer::end3("verify");


        EXPECT_EQ(flag, true);

        if (!flag)  
            cout << "verify not correct in or_proof (interactive mode)" << endl;

        fs << N_length * 8 << ",";
        fs << proof_time << ",";
        fs << verify_time << ",";
        fs << 0 << ",";
        fs << 0 << endl;

        fs.close();

    }

      // interactive mode
    TEST(AppTest, or_proof_workflow_wrong) {
        double proof_time = 0;
        double verify_time = 0;
        size_t N_length = 256; // 
        
        auto crypto = make_shared<PaillierEncryption>(N_length);
        auto verifier = make_shared<Verifier>(crypto, crypto->getGroupG());
        auto prover = make_shared<Prover>(verifier);

        //verifier: e 
        Timer::start("verify");
        ZZ_p::init(SqrRoot(prover->N));
        ZZ_p e;
        random(e);
        verify_time += Timer::end3("verify");

        Timer::start("prove");
        auto proofs = prover->or_proof(conv<ZZ>(e));
        proof_time += Timer::end3("prove");

        ZZ_p::init(prover->N2);
        random(proofs[7]);

        Timer::start("verify");
        bool flag = verifier->or_verify(proofs, conv<ZZ>(e));
        verify_time += Timer::end3("verify");


        EXPECT_EQ(flag, false);

        if (!flag)  
            cout << "verify not correct in or_proof (interactive mode)" << endl;

    }

    TEST(AppTest, or_proof_ni_correct) {
        string file_name = "../../data/new_or_proof_ni_time.csv";
        ifstream ifile(file_name);
        ofstream fs;

        if (ifile) {
            fs.open(file_name, std::ios_base::app);
        } else{
            fs.open(file_name);
            fs << "N length,";
            fs << "proof time (ms), ";
            fs << "verify time (ms), ";
            fs << "(ni) proof time (ms),";
            fs << "(ni) verify time (ms)," << endl;
        }

        double proof_time = 0;
        double verify_time = 0;
        size_t N_length = 256; // 
        
        auto crypto = make_shared<PaillierEncryption>(N_length);
        auto verifier = make_shared<Verifier>(crypto, crypto->getGroupG());
        auto prover = make_shared<Prover>(verifier);


        ZZ e;
        Timer::start("prove");
        Vec<ZZ_p> proofs = prover->or_proof_ni(e);
        proof_time += Timer::end3("prove");

        Timer::start("verify");
        bool flag = verifier->or_verify_ni(proofs);
        verify_time += Timer::end3("verify");

        EXPECT_EQ(flag, true);
        
    }

    TEST(AppTest, benchmarktime) {

          string file_name = "../../data/benchmark_or_proof_ni.csv";
        ifstream ifile(file_name);
        ofstream fs;

        if (ifile) {
            fs.open(file_name, std::ios_base::app);
        } else{
            fs.open(file_name);
            fs << "N length (bits),";
            fs << "averaged proof time (ms), ";
            fs << "averaged verify time (ms), ";
            fs << "repetition times," << endl;
        }

        size_t runtime = 30;
        vector<size_t> N_lengths ({128, 256});
        size_t N_length = 0;
        double proof_time = 0;
        double verify_time = 0;


        for (size_t i = 0; i < N_lengths.size(); i++) {
            N_length = N_lengths[i];
            auto crypto = make_shared<PaillierEncryption>(N_length);
            auto verifier = make_shared<Verifier>(crypto, crypto->getGroupG());
            auto prover = make_shared<Prover>(verifier);
            string name_proof = "prove in " + to_string(N_length);
            string name_verify = "verify in " + to_string(N_length);   


            for (size_t j = 0; j < runtime; j++) {
                ZZ e;
                // proof time
                Timer::start(name_proof);
                Vec<ZZ_p> proofs = prover->or_proof_ni(e);
                proof_time += Timer::end3(name_proof);
                
                // verify time
                Timer::start(name_verify);
                bool flag = verifier->or_verify_ni(proofs);
                verify_time += Timer::end3(name_verify);
            }

            // average proof time, ms
            proof_time = proof_time/runtime; 
            verify_time = verify_time/runtime;

            fs << N_length * 8 << " ,";
            fs << proof_time << " ,";
            fs << verify_time << " ,";
            fs << runtime << endl;

        }
        fs.close();
    }

}
