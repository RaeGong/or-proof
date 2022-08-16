#include "./Timer.h"

map<string, high_resolution_clock::time_point> Timer::t1;
map<string, high_resolution_clock::time_point> Timer::t2;
//used by gbr
map<string, double> Timer::t3;

void Timer::start(const string &name)
{
  Timer::t1[name] = high_resolution_clock::now();
}

double Timer::end(const string &name, bool quite)
{
  Timer::t2[name] = high_resolution_clock::now();
  double tDiff = duration_cast<milliseconds>(Timer::t2[name] - Timer::t1[name]).count();
  tDiff /= 1000;
  if (!quite)
  {
    cout << name << " time: " << tDiff << endl;
  }
  return tDiff;
}


//used by gbr 
double Timer::end2(const string &name, size_t length, bool quite)
{
  Timer::t2[name] = high_resolution_clock::now();
  double tDiff = duration_cast<milliseconds>(Timer::t2[name] - Timer::t1[name]).count(); //ms
  if (!quite)
  {
    cout << name << "total time: " << tDiff << endl;
  }
  double ave_time = tDiff/length;
  if (!quite) {
    cout << name << "average time per exp: " << ave_time << " ms" << endl;
  }

  return tDiff;
}


// ms
double Timer::end3(const string &name, bool quite)
{
  Timer::t2[name] = high_resolution_clock::now();
  double tDiff = duration_cast<milliseconds>(Timer::t2[name] - Timer::t1[name]).count(); //ns
  if (!quite)
  {
    cout << name << " time: " << tDiff << endl;
  }
  return tDiff;
}

//in ns
void Timer::end_with_update(const string &name, bool quite) {
  Timer::t2[name] = high_resolution_clock::now();
  double tDiff = duration_cast<nanoseconds>(Timer::t2[name] - Timer::t1[name]).count(); //ns
  if (!quite)
  {
    cout << name << " time: " << tDiff << endl;
  }
  Timer::update(name, tDiff);
}

//in ns
void Timer::update(const string &name, double &diff){ 
  Timer::t3[name] += diff;
}