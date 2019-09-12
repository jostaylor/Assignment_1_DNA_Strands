#include <iostream>

using namespace std;

class TextFileDNA{
public:
  TextFileDNA(string &all_text); //constructor
  ~TextFileDNA(); //destructor
  // Accessor functions
  string get_full_text();
  int get_sum_nucleotides();
  int get_sum_of_lines();
  double get_string_length_mean();
  double get_string_length_variance();
  double get_string_length_standard_deviation();
  double get_probability_A();
  double get_probability_C();
  double get_probability_G();
  double get_probability_T();
  double get_probability_bigram_AA();
  double get_probability_bigram_AC();
  double get_probability_bigram_AG();
  double get_probability_bigram_AT();
  double get_probability_bigram_CA();
  double get_probability_bigram_CC();
  double get_probability_bigram_CG();
  double get_probability_bigram_CT();
  double get_probability_bigram_GA();
  double get_probability_bigram_GC();
  double get_probability_bigram_GG();
  double get_probability_bigram_GT();
  double get_probability_bigram_TA();
  double get_probability_bigram_TC();
  double get_probability_bigram_TG();
  double get_probability_bigram_TT();
  // Calculates statistics
  void calculate_DNA_statistics();

private:
  string full_text;
  int sum_nucleotides; //total amount of letters
  int sum_of_lines; //total amount of lines
  double string_length_mean; //average length of DNA string in file
  double string_length_variance; //variance of DNA string length
  double string_length_standard_deviation; //Standard deviation of DNA string lengths
  double probability_A;
  double probability_C;
  double probability_G;
  double probability_T;
  double probability_bigram_AA;
  double probability_bigram_AC;
  double probability_bigram_AG;
  double probability_bigram_AT;
  double probability_bigram_CA;
  double probability_bigram_CC;
  double probability_bigram_CG;
  double probability_bigram_CT;
  double probability_bigram_GA;
  double probability_bigram_GC;
  double probability_bigram_GG;
  double probability_bigram_GT;
  double probability_bigram_TA;
  double probability_bigram_TC;
  double probability_bigram_TG;
  double probability_bigram_TT;
};
