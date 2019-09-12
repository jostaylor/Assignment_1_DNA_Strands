#include <iostream>
#include <math.h>
#include "Assign1.h"

using namespace std;

TextFileDNA::TextFileDNA(string& all_text){ //constructor
  full_text = all_text;
}
TextFileDNA::~TextFileDNA(){ //destructor
  cout << "Object deleted with destructor" << endl;
}
// Accessor functions
string TextFileDNA::get_full_text(){
  return full_text;
}
int TextFileDNA::get_sum_nucleotides(){
  return sum_nucleotides;
}
int TextFileDNA::get_sum_of_lines(){
  return sum_of_lines;
}
double TextFileDNA::get_string_length_mean(){
  return string_length_mean;
}
double TextFileDNA::get_string_length_variance(){
  return string_length_variance;
}
double TextFileDNA::get_string_length_standard_deviation(){
  return string_length_standard_deviation;
}
double TextFileDNA::get_probability_A(){
  return probability_A;
}
double TextFileDNA::get_probability_C(){
  return probability_C;
}
double TextFileDNA::get_probability_G(){
  return probability_G;
}
double TextFileDNA::get_probability_T(){
  return probability_T;
}
double TextFileDNA::get_probability_bigram_AA(){
  return probability_bigram_AA;
}
double TextFileDNA::get_probability_bigram_AC(){
  return probability_bigram_AC;
}
double TextFileDNA::get_probability_bigram_AG(){
  return probability_bigram_AG;
}
double TextFileDNA::get_probability_bigram_AT(){
  return probability_bigram_AT;
}
double TextFileDNA::get_probability_bigram_CA(){
  return probability_bigram_CA;
}
double TextFileDNA::get_probability_bigram_CC(){
  return probability_bigram_CC;
}
double TextFileDNA::get_probability_bigram_CG(){
  return probability_bigram_CG;
}
double TextFileDNA::get_probability_bigram_CT(){
  return probability_bigram_CT;
}
double TextFileDNA::get_probability_bigram_GA(){
  return probability_bigram_GA;
}
double TextFileDNA::get_probability_bigram_GC(){
  return probability_bigram_GC;
}
double TextFileDNA::get_probability_bigram_GG(){
  return probability_bigram_GG;
}
double TextFileDNA::get_probability_bigram_GT(){
  return probability_bigram_GT;
}
double TextFileDNA::get_probability_bigram_TA(){
  return probability_bigram_TA;
}
double TextFileDNA::get_probability_bigram_TC(){
  return probability_bigram_TC;
}
double TextFileDNA::get_probability_bigram_TG(){
  return probability_bigram_TG;
}
double TextFileDNA::get_probability_bigram_TT(){
  return probability_bigram_TT;
}
void TextFileDNA::calculate_DNA_statistics(){
  // Calculates statistics for the DNA string list

  // Declare variables
  string full_text_formatted = "";
  int new_line_count = 0;
  int count_A = 0;
  int count_C = 0;
  int count_G = 0;
  int count_T = 0;
  int count_bigram_AA = 0;
  int count_bigram_AC = 0;
  int count_bigram_AG = 0;
  int count_bigram_AT = 0;
  int count_bigram_CA = 0;
  int count_bigram_CC = 0;
  int count_bigram_CG = 0;
  int count_bigram_CT = 0;
  int count_bigram_GA = 0;
  int count_bigram_GC = 0;
  int count_bigram_GG = 0;
  int count_bigram_GT = 0;
  int count_bigram_TA = 0;
  int count_bigram_TC = 0;
  int count_bigram_TG = 0;
  int count_bigram_TT = 0;

  // Loops through the full text
  for(int i = 0; i < full_text.size(); ++i){
    if (isalpha(full_text[i])){
      // Converts DNA letter to lowercase
      char ltr = (char)tolower(full_text[i]);
      char next_ltr = (char)tolower(full_text[i+1]);

      // Checks to make sure only DNA letters exist in the textfile
      if (ltr != 'a' && ltr != 'c' && ltr != 'g' && ltr != 't'){
        cout << "ERROR: File contains an invalid character: " << ltr << endl;
        cout << "Please retry with a valid textfile." << endl;
        exit(1);
      }

      // Counts how many of each letter appear in the collection
      if (ltr == 'a'){
        count_A++;
      }
      else if (ltr == 'c'){
        count_C++;
      }
      else if (ltr == 'g'){
        count_G++;
      }
      else if (ltr == 't'){
        count_T++;
      }

      // Counts how many bigrams appear in the collection
      if (ltr == 'a' && next_ltr == 'a'){
        count_bigram_AA++;
      }
      else if (ltr == 'a' && next_ltr == 'c'){
        count_bigram_AC++;
      }
      else if (ltr == 'a' && next_ltr == 'g'){
        count_bigram_AG++;
      }
      else if (ltr == 'a' && next_ltr == 't'){
        count_bigram_AT++;
      }
      else if (ltr == 'c' && next_ltr == 'a'){
        count_bigram_CA++;
      }
      else if (ltr == 'c' && next_ltr == 'c'){
        count_bigram_CC++;
      }
      else if (ltr == 'c' && next_ltr == 'g'){
        count_bigram_CG++;
      }
      else if (ltr == 'c' && next_ltr == 't'){
        count_bigram_CT++;
      }
      else if (ltr == 'g' && next_ltr == 'a'){
        count_bigram_GA++;
      }
      else if (ltr == 'g' && next_ltr == 'c'){
        count_bigram_GC++;
      }
      else if (ltr == 'g' && next_ltr == 'g'){
        count_bigram_GG++;
      }
      else if (ltr == 'g' && next_ltr == 't'){
        count_bigram_GT++;
      }
      else if (ltr == 't' && next_ltr == 'a'){
        count_bigram_TA++;
      }
      else if (ltr == 't' && next_ltr == 'c'){
        count_bigram_TC++;
      }
      else if (ltr == 't' && next_ltr == 'g'){
        count_bigram_TG++;
      }
      else if (ltr == 't' && next_ltr == 't'){
        count_bigram_TT++;
      }

      // Creates formatted text (without new line chars)
      full_text_formatted += full_text[i];
    }

    else if (full_text[i] == '\n'){
      // Count of new line chars gives us the number of lines in the collection
      new_line_count++;
    }

    // File contains something other than newline, carraige return, or ACGT
    // Exits program
    else if (full_text[i] != '\r'){
      cout << "ERROR: File contains an invalid character: " << full_text[i] << endl;
      cout << "Please retry with a valid textfile." << endl;
      exit(1);
    }



  }
  // Initializes statistics variables
  sum_of_lines = new_line_count; // Amount of lines
  sum_nucleotides = full_text_formatted.size(); // Amount of letters
  string_length_mean = (double)sum_nucleotides / (double)sum_of_lines; // Average string length
  // In order to calculate the variance, I must iterate through the collection again
  // I mean I probably don't actually have to, but this is the only way I could think of doing it

  // Declare variables
  int count_for_length_of_DNA_string = 0;
  double total_of_squared_distances_to_mean = 0;

  // Because the newline char shows up at the beginning of every line, we must iterate backwards
  for (int i = full_text.size() - 1; i >= 0; --i){
    // Formats char
    char ltr = (char)tolower(full_text[i]);
    // If there is a letter, add 1 to count
    if (isalpha(ltr)){
      count_for_length_of_DNA_string++;
    }
    // If the line has ended --> count is at correct length
    else if (ltr == '\n'){
      // Calculates the squared distance to the mean and adds its to the total
      double length_of_string_distance_to_mean = (double)count_for_length_of_DNA_string - string_length_mean;
      double squared_distance_to_mean = length_of_string_distance_to_mean * length_of_string_distance_to_mean;
      total_of_squared_distances_to_mean += squared_distance_to_mean;
      // Resets count variable so it can be used again for the next line
      count_for_length_of_DNA_string = 0;
    }
  }

  // Initializes statistics variables
  string_length_variance = total_of_squared_distances_to_mean / (double)sum_of_lines;
  string_length_standard_deviation = sqrt(string_length_variance);

  // For every DNA string, there is 1 less bigram than there are chars
  // So we must subtract 1 from every line to get the total amount of bigrams in that line
  int total_amount_of_bigrams = sum_nucleotides - sum_of_lines;

  probability_A = (double)count_A / (double)sum_nucleotides;
  probability_C = (double)count_C / (double)sum_nucleotides;
  probability_G = (double)count_G / (double)sum_nucleotides;
  probability_T = (double)count_T / (double)sum_nucleotides;
  probability_bigram_AA = (double)count_bigram_AA / (double)total_amount_of_bigrams;
  probability_bigram_AC = (double)count_bigram_AC / (double)total_amount_of_bigrams;
  probability_bigram_AG = (double)count_bigram_AG / (double)total_amount_of_bigrams;
  probability_bigram_AT = (double)count_bigram_AT / (double)total_amount_of_bigrams;
  probability_bigram_CA = (double)count_bigram_CA / (double)total_amount_of_bigrams;
  probability_bigram_CC = (double)count_bigram_CC / (double)total_amount_of_bigrams;
  probability_bigram_CG = (double)count_bigram_CG / (double)total_amount_of_bigrams;
  probability_bigram_CT = (double)count_bigram_CT / (double)total_amount_of_bigrams;
  probability_bigram_GA = (double)count_bigram_GA / (double)total_amount_of_bigrams;
  probability_bigram_GC = (double)count_bigram_GC / (double)total_amount_of_bigrams;
  probability_bigram_GG = (double)count_bigram_GG / (double)total_amount_of_bigrams;
  probability_bigram_GT = (double)count_bigram_GT / (double)total_amount_of_bigrams;
  probability_bigram_TA = (double)count_bigram_TA / (double)total_amount_of_bigrams;
  probability_bigram_TC = (double)count_bigram_TC / (double)total_amount_of_bigrams;
  probability_bigram_TG = (double)count_bigram_TG / (double)total_amount_of_bigrams;
  probability_bigram_TT = (double)count_bigram_TT / (double)total_amount_of_bigrams;
}
