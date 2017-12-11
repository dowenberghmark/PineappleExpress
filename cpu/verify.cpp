#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sha256.hpp"
#include "verify.hpp"

using std::cout;
using std::string;
using std::endl;
using std::cout;
using std::vector;
using std::ifstream;

int verify(std::vector<std::string> fpga_hash_vec){
  //Get vector with hashed passwords from an extrernal SHA-256 hasher
  cout << "Trying to verify" << endl;
  vector<string>ext_hash_vec = SHA256_CPU_verify("cpu/random_passwords.txt");
  int error_row = 0;

  for(unsigned i=0; i<fpga_hash_vec.size(); i++){
    cout << "FPGA hash:" << fpga_hash_vec[i] << endl;
    cout << "EXT  hash:" << ext_hash_vec[i] << endl;
    if (fpga_hash_vec[i].compare(ext_hash_vec[i]) != 0){
      error_row = i+1;
      cout << "Line " << error_row << " is incorrect" << endl;
    }
  }
  cout << "Comparison completed" << endl;
  return 0;
}
