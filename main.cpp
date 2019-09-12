#include <iostream>
#include <fstream>
#include <math.h>
#include "Assign1.h"

using namespace std;

string read_file(string file_name){
  // Declare variables
  ifstream myDNATextFile;
  string line;
  string allText = "";

  // Opens and reads file
  myDNATextFile.open(file_name);

  if (myDNATextFile.is_open()){
    cout << "File opened" << endl;
    while (getline(myDNATextFile, line)){
      allText = allText + "\n" + line;
    }
    myDNATextFile.close();
    cout << "File read and closed" << endl;
  }
  else{
    // Handles error if file could not be read
    cout << "Could not open the file" << "\n";
    cout << "Usage \'./a.out [filename]\'" <<  endl;
    exit(1);
  }
  // returns all text from file
  return allText;
}

void writeResultsToFile(TextFileDNA& obj, ofstream& output_file){
  // Prints results to console
  output_file << "\nResults:" << endl;
  output_file << "Total amount of nucleotides: " << obj.get_sum_nucleotides() << endl;
  output_file << "Total amount of DNA strings: " << obj.get_sum_of_lines() << endl;
  output_file << "Mean length of DNA strings: " << obj.get_string_length_mean() << endl;
  output_file << "Variance of DNA string length: " << obj.get_string_length_variance() << endl;
  output_file << "Standard deviation of DNA string length: " << obj.get_string_length_standard_deviation() << endl;
  output_file << "Probability A: " << obj.get_probability_A() << endl;
  output_file << "Probability C: " << obj.get_probability_C() << endl;
  output_file << "Probability G: " << obj.get_probability_G() << endl;
  output_file << "Probability T: " << obj.get_probability_T() << endl;
  output_file << "Probability bigram AA: " << obj.get_probability_bigram_AA() << endl;
  output_file << "Probability bigram AC: " << obj.get_probability_bigram_AC() << endl;
  output_file << "Probability bigram AG: " << obj.get_probability_bigram_AG() << endl;
  output_file << "Probability bigram AT: " << obj.get_probability_bigram_AT() << endl;
  output_file << "Probability bigram CA: " << obj.get_probability_bigram_CA() << endl;
  output_file << "Probability bigram CC: " << obj.get_probability_bigram_CC() << endl;
  output_file << "Probability bigram CG: " << obj.get_probability_bigram_CG() << endl;
  output_file << "Probability bigram CT: " << obj.get_probability_bigram_CT() << endl;
  output_file << "Probability bigram GA: " << obj.get_probability_bigram_GA() << endl;
  output_file << "Probability bigram GC: " << obj.get_probability_bigram_GC() << endl;
  output_file << "Probability bigram GG: " << obj.get_probability_bigram_GG() << endl;
  output_file << "Probability bigram GT: " << obj.get_probability_bigram_GT() << endl;
  output_file << "Probability bigram TA: " << obj.get_probability_bigram_TA() << endl;
  output_file << "Probability bigram TC: " << obj.get_probability_bigram_TC() << endl;
  output_file << "Probability bigram TG: " << obj.get_probability_bigram_TG() << endl;
  output_file << "Probability bigram TT: " << obj.get_probability_bigram_TT() << endl;

  cout << "Results written to .out file successfully" << endl;
}

int main(int argc, char** argv){

  // Gets text from filename in command line arg
  string all_text = read_file(argv[1]);
  // Creates object
  TextFileDNA DNA_string(all_text);
  // Makes all calculations
  DNA_string.calculate_DNA_statistics();
  // Opens file
  ofstream my_output_file;
  my_output_file.open("joshtaylor.out");
  // Writes personal info to top of output file
  my_output_file << "Josh Taylor" << endl;
  my_output_file << "Student ID: 2317445" << endl;
  my_output_file << "Student email: jostaylor@chapman.edu" << endl;
  my_output_file << "CPSC-350 - 03 - Data Structures" << endl;
  my_output_file << "Assignment 1" << endl;
  // Writes results to file
  writeResultsToFile(DNA_string, my_output_file);
  // Writes new line to file to give space for generated DNA strings
  my_output_file << "\nRandomly generated DNA strings:" << endl;
  // Loop creates 1000 new DNA strings and appends them to the output file
  for (int i = 0; i < 1000; ++i){
    // Resets the seed for rand so we actually get a new value each time
    srand(time(NULL) + i + 1);
    // Randomly generates 2 values and calculates a DNA string length from the distribution
    double a = (double)(rand() % 10000) / 10000;
    double b = (double)(rand() % 10000) / 10000;
    double c = sqrt(-2*log(a)) * cos(2*3.14*b);
    double d = (c * DNA_string.get_string_length_standard_deviation()) + DNA_string.get_string_length_mean();
    // --- Generates random DNA string based on generated length ---
    // Rounds the length up or down based on the decimal
    int new_string_length = (int)d; // Rounds down automatically
    if (d - (double)new_string_length >= 0.5){ // If it should've been rounded up
      new_string_length++;
    }
    // Ensures DNA string has length of at least one
    if (new_string_length <= 0){
      new_string_length = 1;
    }
    // Chooses random DNA letters from AGCT and inserts them into the new string
    // Probability of letters generated is based off of existing nucleotide probabilities
    string new_DNA_string = "";
    for (int i = 0; i < new_string_length; ++i){

      double new_letter_probability = (double)(rand() % 1000000) / 1000000;

      if (new_letter_probability <= DNA_string.get_probability_A()){
        new_DNA_string += "A";
      }
      else if (new_letter_probability <= (DNA_string.get_probability_C() + DNA_string.get_probability_A())){
        new_DNA_string += "C";
      }
      else if (new_letter_probability <= (DNA_string.get_probability_G() + DNA_string.get_probability_C() + DNA_string.get_probability_A())){
        new_DNA_string += "G";
      }
      else{
        new_DNA_string += "T";
      }
    }
    // Writes new string to the output file
    my_output_file << new_DNA_string << endl;
  }
  // Prints success
  cout << "Generated strings written to output file" << endl;
  // Asks user if they would like to read another file
  cout << "Would you like to read another file of DNA strings? (y/n)";
  string user_response = "";
  cin >> user_response;
  while (user_response != "y" && user_response != "n"){
    cout << "Please enter a valid input. --> \'y\' or \'n\'" << endl;
    cin >> user_response;
  }
  if (user_response == "y"){
    // Declares variable and grabs textfile from user
    string new_filename;
    cout << "Please enter the name of your DNA string textfile: " << endl;
    cin >> new_filename;
    // Reads file, creates TextFileDNA object, and calculates statistics, and writes the results to the file
    string all_text = read_file(new_filename);
    TextFileDNA DNA_string_2(all_text);
    DNA_string_2.calculate_DNA_statistics();
    writeResultsToFile(DNA_string_2, my_output_file);
    cout << "Results successfully added to output file." << endl;
    cout << "Goodbye!" << endl;
  }
  // User doesn't want to input 2nd filename
  else{
    cout << "Goodbye!" << endl;
  }

  // Closes the file
  my_output_file.close();

  return 0;
}
