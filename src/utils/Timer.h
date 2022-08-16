#pragma once

#include "../namespace.h"

#include <chrono>

using namespace std::chrono;

namespace polyu
{

class Timer
{
public:
  static map<string, high_resolution_clock::time_point> t1;
  static map<string, high_resolution_clock::time_point> t2;

  //used by gbr
  static map<string, double> t3; // duration

  static void start(const string &name);
  static double end(const string &name, bool quite = false);

  //used by gbr
  static double end2(const string &name, size_t length, bool quite = false);
  static double end3(const string &name, bool quite = false);
  static void end_with_update(const string &name, bool quite = true); //in ns
  static void update(const string &name, double &diff); // in ns
};

} // namespace polyu
